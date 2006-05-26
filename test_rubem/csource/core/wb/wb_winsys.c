/*******************************************************************************

 WINBINDER - A native Windows binding

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Window system functions

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "wb.h"
#include <shellapi.h>		// For ShellExecute()
#include <shlobj.h>			// For SHGetSpecialFolderLocation()
#include <io.h>				// For access()
#include <stdio.h>			// For printf() -- beep

#include <shlobj.h>			// For uxtheme.h
#include <uxtheme.h>		// For theme functions
#include <psapi.h>			// For memory information functions
#include <ole2.h>			// For OleInitialize()

//-------------------------------------------------------------------- CONSTANTS

#define OBJ_COLORSPACE		14

//----------------------------------------------------------------------- MACROS

#define M_FileExists(file)	(access(file, 0) == 0)

//-------------------------------------------------------------------- VARIABLES

// Global

HFONT hIconFont = NULL;
HWND hCurrentDlg = NULL;

// Local

static HACCEL hAccelTable = NULL;			// Accelerator table
static HWND hAccelWnd = NULL;				// Accelerator table window
static HCURSOR hClassCursor[NUMCLASSES];	// Table of mouse cursors, one for each class

//---------------------------------------------------------- FUNCTION PROTOTYPES

// Private

static int _GetUserObjects(void);
static int _GetGDIObjects(void);
static HKEY _GetKeyFromString(LPCTSTR pszKey);
static BOOL _GetOSVersionString(LPTSTR pszString);
static HCURSOR GetSysCursor(LPCTSTR pszCursor);

// Public to wb_* modules

LPTSTR MakeWinPath(LPTSTR pszPath);

// External

extern BOOL RegisterClasses(void);

//------------------------------------------------------------- PUBLIC FUNCTIONS

/* Module initialization */

BOOL wbInit(void)
{
//	int nClass;
	LOGFONT lfIcon;
	OSVERSIONINFO ovInfo;
	INITCOMMONCONTROLSEX icex;

	// Create the interface font

	SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lfIcon, 0);
	hIconFont = CreateFontIndirect(&lfIcon);

	// Load the common control DLLs

	InitCommonControls();
	if(!LoadLibrary("RICHED20.DLL"))		// This is version 2.0 of the DLL
		LoadLibrary("RICHED32.DLL");
	icex.dwSize = sizeof(icex);
	icex.dwICC  = ICC_DATE_CLASSES;			// Load date and time picker control class
	InitCommonControlsEx(&icex);
	if(OleInitialize(NULL) != S_OK) 		// Initialize the OLE interface
		return FALSE;

	// Get the handle of the file used to create this process

	hAppInstance = GetModuleHandle(NULL);

	// Set the background color for tab controls

	ovInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&ovInfo);

	if(ovInfo.dwMajorVersion >= 5 && ovInfo.dwMinorVersion >= 1) {	// Windows XP only

		// Check if a manifest file exists

		OFSTRUCT ofs;
		char *szApp = wbStrnDup(GetCommandLine(), MAX_PATH);

		if(strchr(szApp, ' '))
			*strchr(szApp, ' ') = '\0';
		strcat(szApp, ".manifest");

		ofs.cBytes = sizeof(OFSTRUCT);
		if(OpenFile(szApp, &ofs, OF_EXIST) != HFILE_ERROR) {

			// Check if themes are enabled

			HANDLE hLib;
			HTHEME hTheme;

//			THEMEAPI_(HTHEME)(*w_OpenThemeData)(HWND, LPCWSTR);
//			THEMEAPI (*w_CloseThemeData)(HTHEME);

//			HTHEME (DECLSPEC_IMPORT STDAPICALLTYPE *w_OpenThemeData)(HWND, LPCWSTR);
//			HRESULT (DECLSPEC_IMPORT STDAPICALLTYPE *w_CloseThemeData)(HTHEME);
			HTHEME (STDAPICALLTYPE *w_OpenThemeData)(HWND, LPCWSTR);
			HRESULT (STDAPICALLTYPE *w_CloseThemeData)(HTHEME);

			hLib = LoadLibrary("UxTheme.dll");

			if(hLib) {					// Is the DLL present?
				w_OpenThemeData = (void *)GetProcAddress(hLib, "OpenThemeData");
				w_CloseThemeData = (void *)GetProcAddress(hLib, "CloseThemeData");
				hTheme = w_OpenThemeData(GetDesktopWindow(), L"Tab");

				if(hTheme) {			// Is there an active theme?

					clrTabs = 0xFCFCFE; // This is the tab color for all standard XP themes, but of course
										// it should not be hardcoded. Couldn't find a method of obtaining
										// this color. GetThemeColor() with TABP_PANE/TIS_NORMAL/TMT_FILLCOLOR
										// should work but it doesn't, maybe because WinBinder doesn't use
										// class #32770 (dialog class) for the tab pages.
					hbrTabs = CreateSolidBrush(clrTabs);
					w_CloseThemeData(hTheme);
				}
			}
		}
	}

	if(!RegisterClasses())
		return FALSE;

//	for(nClass = 0; nClass < NUMCLASSES; nClass++)
//		wbSetCursor((PWBOBJ)Calendar, NULL);

	// Initializes mouse cursor for some control classes

	wbSetCursor((PWBOBJ)EditBox, "ibeam", NULL);
	wbSetCursor((PWBOBJ)InvisibleArea, "arrow", NULL);

	return TRUE;
}

/* Module end */

BOOL wbEnd(void)
{
	if(hIconFont)
		DeleteObject(hIconFont);
	if(hbrTabs)
		DeleteObject(hbrTabs);
	if(hAccelTable)
		DestroyAcceleratorTable(hAccelTable);
	OleUninitialize();
	return TRUE;
}

/*

References:

http://groups.google.com/groups?hl=en&lr=&frame=right&th=d1c76898d0731052&seekm=1KE29.8484%24wh1.7226%40news01.bloor.is.net.cable.rogers.com#link6
http://code.glowdot.com/tutorials/win32tutorial.php?page=10

Notice that TranslateAccelerator is called before IsDialogMessage. if they are called
in the reverse order, and the focus is on one of our edit controls, IsDialogMessage
will take our shortcut combo and process it as a dialog message.

*/

WPARAM wbMainLoop(void)
{
	MSG msg;

	// Main message loop

	while(GetMessage(&msg, NULL, 0, 0)) {
		if(!TranslateAccelerator(hAccelWnd, hAccelTable, &msg)) {
	     	if(!hCurrentDlg || !IsDialogMessage(hCurrentDlg, &msg)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	return msg.wParam;
}

// Used in wb_wait()
// Reference: API help, "Examining a Message Queue"

UINT wbCheckInput(PWBOBJ pwbo, DWORD dwFlags, DWORD dwTimeout)
{
	HWND hwnd;
	MSG msg;
	DWORD dwMs;

	if(!pwbo)
		hwnd = GetForegroundWindow();
	else {
		if(!pwbo || !pwbo->hwnd || !IsWindow(pwbo->hwnd))
			return FALSE;
		hwnd = pwbo->hwnd;
	}

	// Ensure that messages will go to this window

	SetFocus(hwnd);

	// Peek message

	dwMs = GetTickCount();

//	dwTimeout = MAX(1, dwTimeout);

	while(TRUE) {

		if(PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {

			switch(msg.message) {

				case WM_LBUTTONDOWN:
					if(dwFlags & WBC_MOUSEDOWN)
						return MAKELONG(WBC_MOUSEDOWN, 1);
					break;

				case WM_MBUTTONDOWN:
					if(dwFlags & WBC_MOUSEDOWN)
						return MAKELONG(WBC_MOUSEDOWN, 2);
					break;

				case WM_RBUTTONDOWN:
					if(dwFlags & WBC_MOUSEDOWN)
						return MAKELONG(WBC_MOUSEDOWN, 3);
					break;

				case WM_LBUTTONUP:
					if(dwFlags & WBC_MOUSEUP)
						return MAKELONG(WBC_MOUSEUP, 1);
					break;

				case WM_MBUTTONUP:
					if(dwFlags & WBC_MOUSEUP)
						return MAKELONG(WBC_MOUSEUP, 2);
					break;

				case WM_RBUTTONUP:
					if(dwFlags & WBC_MOUSEUP)
						return MAKELONG(WBC_MOUSEUP, 3);
					break;

				case WM_KEYDOWN:
					if(dwFlags & WBC_KEYDOWN)
						return MAKELONG(msg.wParam, 0);
					break;

				case WM_KEYUP:
					if(dwFlags & WBC_KEYUP)
						return MAKELONG(msg.wParam, 0);
					break;
			}

			// "Eat" this message

			TranslateMessage(&msg);
			DispatchMessage(&msg);

		} // ~if

		if(dwTimeout == 0)
			break;

		if(GetTickCount() >= dwMs + dwTimeout)	// Time's out
			break;
	} // ~while

	return 0;
}


// ******* It seems that all child controls inherit the mouse cursor style
// ******* from their parent window, and it's not clear if this
// ******* behavior is standard in Windows (seems so) or some WinBinder bug

// Set system, class or control mouse cursor

BOOL wbSetCursor(PWBOBJ pwbo, LPCTSTR pszCursor, HANDLE handle)
{
	HCURSOR hCursor;

	if(!pwbo) {

		// Set system cursor

		if(handle)									// Cursor handle
			hCursor = handle;
		if(!pszCursor || !*pszCursor)				// pszCursor is NULL
			hCursor = GetSysCursor("arrow");
		else										// Cursor name
			hCursor = GetSysCursor(pszCursor);

		if(hCursor)
			SetCursor(hCursor == (HCURSOR)-1 ? 0 : hCursor);

		// Must NOT use the value returned from from SetCursor()
		return (hCursor != 0);

	} else if(wbIsValidClass((UINT)pwbo)) {

		// Stores class ((UINT)pwbo) mouse cursor in array hClassCursor

		if(handle)									// Cursor handle
			hCursor = handle;
		else if(!pszCursor || !*pszCursor)			// pszCursor is NULL
			hCursor = GetSysCursor("arrow");
		else										// Cursor name
			hCursor = GetSysCursor(pszCursor);

		hClassCursor[(UINT)pwbo] = hCursor;
		return TRUE;

	} else {

		// Stores mouse cursor handle in control param (M_nMouseCursor)

		if(!pwbo->hwnd || !IsWindow(pwbo->hwnd))
			return FALSE;

		if(handle)									// Cursor handle
			hCursor = handle;
		else if(!pszCursor || !*pszCursor)			// pszCursor is NULL
			hCursor = hClassCursor[pwbo->uClass];
		else										// Cursor name
			hCursor = GetSysCursor(pszCursor);

		M_nMouseCursor = (LONG)hCursor;
		return (hCursor != 0);
	}
}

// Returns TRUE if uClass is a valid WinBinder class

BOOL wbIsValidClass(UINT uClass)
{
	switch(uClass) {

		case AppWindow:
		case ModalDialog:
		case ModelessDialog:
		case NakedWindow:
		case PopupWindow:
		case ResizableWindow:
		case ToolDialog:
			return TRUE;

		case Accel:
		case Calendar:
		case CheckBox:
		case ComboBox:
		case EditBox:
		case Frame:
		case Gauge:
		case HTMLControl:
		case HyperLink:
		case ImageButton:
		case InvisibleArea:
		case Label:
		case ListBox:
		case ListView:
		case Menu:
		case PushButton:
		case RTFEditBox:
		case RadioButton:
		case ScrollBar:
		case Slider:
		case Spinner:
		case StatusBar:
		case TabControl:
		case ToolBar:
		case TreeView:
			return TRUE;
	}
	return FALSE;
}


/*
	Gets the accelerator from a string like "Ctrl+S", "Alt+Ctrl+Shift+F12", "F1", "J", etc.
	Returns the key code in the LOWORD and the accelerator flags in the HIWORD.
*/

DWORD wbMakeAccelFromString(const char *pszAccel)
{
	WORD key = 0, fVirt = 0;
	char szAux[100];	// Should be enough
	char *ptr;
	int i;

	if(!pszAccel || !*pszAccel)			// Ignore null or empty strings
		return 0;

	strcpy(szAux, pszAccel);
	ptr = strtok(szAux, "+");
	if(ptr && *ptr) {
		for(i = 0; ptr && *ptr && (i < 4); i++) {

			// Normal key

			if(ptr && *ptr)
				key = *ptr;

			// Up to three modifiers: ctrl, alt, shift

			if(!stricmp(ptr, "ctrl"))
				fVirt |= FCONTROL | FVIRTKEY;
			else if(!stricmp(ptr, "alt"))
				fVirt |= FALT | FVIRTKEY;
			else if(!stricmp(ptr, "shift"))
				fVirt |= FSHIFT | FVIRTKEY;

			// Special keys

//			else
//				fVirt |= FVIRTKEY;

			else if(!stricmp(ptr, "enter"))
				key = VK_RETURN;
			else if(!stricmp(ptr, "escape") || !stricmp(ptr, "esc"))
				key = VK_ESCAPE;
			else if(!stricmp(ptr, "tab"))
				key = VK_TAB;
			else if(!stricmp(ptr, "backspace"))
				key = VK_BACK;
			else if(!stricmp(ptr, "space"))
				key = VK_SPACE;
			else if(!stricmp(ptr, "left"))
				key = VK_LEFT;
			else if(!stricmp(ptr, "up"))
				key = VK_UP;
			else if(!stricmp(ptr, "right"))
				key = VK_RIGHT;
			else if(!stricmp(ptr, "down"))
				key = VK_DOWN;
			else if(!stricmp(ptr, "pagedown") || !stricmp(ptr, "pgdn"))
				key = VK_NEXT;
			else if(!stricmp(ptr, "pageup") || !stricmp(ptr, "pgup"))
				key = VK_PRIOR;
			else if(!stricmp(ptr, "home"))
				key = VK_HOME;
			else if(!stricmp(ptr, "end"))
				key = VK_END;
			else if(!stricmp(ptr, "insert") || !stricmp(ptr, "ins"))
				key = VK_INSERT;
			else if(!stricmp(ptr, "delete") || !stricmp(ptr, "del"))
				key = VK_DELETE;
			else if(!stricmp(ptr, "plus"))
				key = fVirt ? VK_ADD : '+';


			// F-keys

			else if((*ptr == 'F' || *ptr == 'f') && *(ptr + 1)) {
				key = VK_F1 - 1 + atoi(ptr + 1);
				fVirt |= FVIRTKEY;
			}

			ptr = strtok(NULL, "+");
		}
	} else {
		return 0;
	}
//	printf("ACCEL: [%s], key %d, fVirt %d\n", pszAccel, key, fVirt);

	return MAKELONG(key, fVirt);
}

BOOL wbSetAccelerators(PWBOBJ pwbo, LPACCEL paccels, int nCount)
{
	if(hAccelTable)
		DestroyAcceleratorTable(hAccelTable);

	if(paccels && nCount) {
		hAccelTable = CreateAcceleratorTable(paccels, nCount);
		if(!hAccelTable)
			return FALSE;
		hAccelWnd = pwbo->hwnd;
		return TRUE;
	} else
		return TRUE;
}

/*

Return values:

IDCANCEL	 0
IDIGNORE	 0
IDABORT		 0
IDNO		 0
Others		 0
IDOK		 1
IDRETRY		 1
IDYES		 1

Error		-1

*/

int wbMessageBox(PWBOBJ pwboParent, LPCTSTR pszText, LPCTSTR pszCaption, UINT nStyle)
{
	int nRet;

	if(!pwboParent)
		nRet = MessageBox(NULL, pszText, pszCaption, nStyle);
	else {
		if(!pwboParent->hwnd || !IsWindow(pwboParent->hwnd))
			return -1;
		nRet = MessageBox(pwboParent->hwnd, pszText, pszCaption, nStyle);
	}

	switch(nRet) {
		case IDCANCEL:
		case IDIGNORE:
		case IDABORT:
		case IDNO:
		default:
			return 0;

		case IDOK:
		case IDYES:
		case IDRETRY:
			return 1;
	}
}

BOOL wbPlaySystemSound(int nStyle)
{
	switch(nStyle) {

		case MB_OK:
		case MB_ICONINFORMATION:
		case MB_ICONWARNING:
		case MB_ICONSTOP:
		case MB_ICONQUESTION:
			break;						// nStyle is valid

		case WBC_BEEP:
//			nStyle = 0xFFFFFFFF;		// Beep speaker (doesn't work, really)
			nStyle = printf("\x07");	// Beep speaker
			return TRUE;

		default:
			nStyle = MB_OK;
	}

	return MessageBeep(nStyle);
}

BOOL wbExec(LPCTSTR pszPgm, LPCTSTR pszParm, BOOL bShowWindow)
{
	BOOL bRet;

	// Is pszPgm a WinBinder script?

	if(strstr(pszPgm, "." WB_EXTENSION) == pszPgm + strlen(pszPgm) - sizeof(WB_EXTENSION)) {

		char szApp[1024];

		GetModuleFileName(NULL, szApp, 1023);

		if(pszParm && (*pszParm == 'o' || *pszParm == 'O')) {			// User wants to open the file (which will usually run it, except if the user has changed the .phpw association)
			goto Execute;	// Sometimes a good ol' GOTO can be useful
		} else if(pszParm && (*pszParm == 'c' || *pszParm == 'C')) {	// User wants console mode
			;	// do nothing
		} else if(pszParm && (*pszParm == 'w' || *pszParm == 'W')) {	// User wants windowed mode
			*strstr(szApp, ".exe") = '\0';
			*strcat(szApp, "-win.exe");					// PHP-specific
		} else {
			char szTitle[MAX_PATH + 1];

			// Determine console mode according to the calling program

			if(!GetConsoleTitle(szTitle, MAX_PATH)) {
				*strstr(szApp, ".exe") = '\0';
				*strcat(szApp, "-win.exe");				// PHP-specific
			}
		}

		bRet = (ShellExecute(GetActiveWindow(), "open",
			szApp, pszPgm, NULL, bShowWindow ? SW_SHOWNORMAL : SW_HIDE) > (HINSTANCE)32);

	} else {

Execute:
		// Shell execute

		bRet = (ShellExecute(GetActiveWindow(), "open",
			pszPgm, pszParm, NULL, bShowWindow ? SW_SHOWNORMAL : SW_HIDE) > (HINSTANCE)32);
	}

	if(!bRet)
		wbError(__FUNCTION__, MB_ICONWARNING, "Could not run application %s", pszPgm);

	return bRet;
}

BOOL wbShowLastError(LPCTSTR pszCaption, BOOL bMessageBox)
{
	LPVOID lpMsgBuf;

	FormatMessage(
	    FORMAT_MESSAGE_ALLOCATE_BUFFER |
	    FORMAT_MESSAGE_FROM_SYSTEM |
	    FORMAT_MESSAGE_IGNORE_INSERTS,
	    NULL,
	    GetLastError(),
	    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
	    (LPTSTR)&lpMsgBuf, 0, NULL);
	if(bMessageBox)
		MessageBox(NULL, (LPCTSTR)lpMsgBuf, pszCaption, MB_OK | MB_ICONINFORMATION);
	else
		printf("%s - %s\n", pszCaption, (LPCTSTR)lpMsgBuf);
	LocalFree(lpMsgBuf);
	return TRUE;
}

/*

If pszFile exists, do nothing and return TRUE.
If not, look for pszFile in the Windows directory, then in the System directory.
If it exists in one of those, put the complete path in pszFile and return TRUE.
If not, do nothing and return FALSE.

NOTE: Do not use SearchPath(), it may crash PHP (why?)

*/

BOOL wbFindFile(LPTSTR pszFile, UINT uLen)
{
	char szPath[MAX_PATH * 2];

	if(M_FileExists(pszFile))
		return TRUE;

	if(uLen > MAX_PATH)
		uLen = MAX_PATH;

	// Look for the file in the Windows directory

	GetWindowsDirectory(szPath, MAX_PATH - 1);
	if(!szPath[strlen(szPath) - 1] != '\\')
		strcat(szPath, "\\");
	strcat(szPath, pszFile);
	if(M_FileExists(szPath)) {
		strcpy(pszFile, szPath);
		return TRUE;
	}

	// Look for the file in the System directory

	GetSystemDirectory(szPath, MAX_PATH - 1);
	if(!szPath[strlen(szPath) - 1] != '\\')
		strcat(szPath, "\\");
	strcat(szPath, pszFile);
	if(M_FileExists(szPath)) {
		strcpy(pszFile, szPath);
		return TRUE;
	}

	// Found nothing

	wbError(__FUNCTION__, MB_ICONWARNING, "File %s was not found.", pszFile);

	return FALSE;
}

BOOL wbReadRegistryKey(LPCTSTR pszKey, LPTSTR pszSubKey, LPTSTR pszEntry, LPTSTR pszValue, int *pnBufLen)
{
	HKEY hMaster;
	HKEY hKey;
	DWORD dwType;

	// Get hMaster from pszKey

	hMaster = _GetKeyFromString(pszKey);
	if(!hMaster) {
		*pszValue = '\0';
		return FALSE;
	}

	// Convert any '/'s to '\\'s

	if(!pszEntry || !*pszEntry)		// No entry?
		pszEntry = NULL;
	else
		MakeWinPath(pszEntry);
	MakeWinPath(pszSubKey);

	//printf("%s\\%s\\%s\n", pszKey, pszSubKey, pszEntry);

	// Read the data

	if(RegOpenKeyEx(hMaster, pszSubKey, 0, KEY_READ, &hKey) != ERROR_SUCCESS) {

		// The entry does not exist

		*pszValue = '\0';
		return FALSE;
	}

	// The entry exists

	if(RegQueryValueEx(hKey, pszEntry, NULL, &dwType, pszValue, (LPDWORD)pnBufLen) != ERROR_SUCCESS) {

		// The entry exists but is empty

		*pszValue = '\0';
		RegCloseKey(hKey);
		return TRUE;
	}

	RegCloseKey(hKey);

	//printf("[%d] %s\n", dwType, pszValue);
	switch(dwType) {

		case REG_DWORD:
			{
				DWORD dw = *((DWORD *)pszValue);

				ltoa(dw, pszValue, 10);
			}
			return TRUE;

		case REG_SZ:
		case REG_MULTI_SZ:
		case REG_EXPAND_SZ:
			return TRUE;

		case REG_BINARY:
		case REG_NONE:
		case REG_DWORD_BIG_ENDIAN:
		default:
			*pszValue = '\0';
			return FALSE;
	}
}

// If pszValue is NULL and bString is TRUE, deletes the value

BOOL wbWriteRegistryKey(LPCTSTR pszKey, LPTSTR pszSubKey, LPTSTR pszEntry, LPCTSTR pszValue, DWORD dwValue, BOOL bString)
{
	HKEY hMaster;
	HKEY hKey;
	DWORD dwDisp;

	// Get hMaster from pszKey

	hMaster = _GetKeyFromString(pszKey);
	if(!hMaster)
		return FALSE;

	// Convert any '/'s to '\\'s

	if(!pszEntry || !*pszEntry)		// No entry?
		pszEntry = NULL;
	else
		MakeWinPath(pszEntry);
	MakeWinPath(pszSubKey);

//	printf("%s %s (%d %d)\n", pszEntry, pszValue, dwValue, bString);

	// Opens or creates the entry

	if(RegCreateKeyEx(hMaster, pszSubKey, 0, NULL, REG_OPTION_NON_VOLATILE,
	  KEY_WRITE, NULL, &hKey, &dwDisp))
		return FALSE;

	if(bString && !pszValue) {					// Delete value
		if(RegDeleteValue(hKey, pszEntry) != ERROR_SUCCESS)
			return FALSE;
	} else if(bString && pszValue) {			// Create a string value
		if(RegSetValueEx(hKey, pszEntry, 0, REG_SZ, (BYTE *)pszValue, strlen(pszValue)) != ERROR_SUCCESS)
			return FALSE;
	} else {									// Create a DWORD value
		if(RegSetValueEx(hKey, pszEntry, 0, REG_DWORD, (BYTE *)&dwValue, sizeof(DWORD)) != ERROR_SUCCESS)
			return FALSE;
	}

	if(RegCloseKey(hKey) != ERROR_SUCCESS)
		return FALSE;

	return TRUE;
}

/*
  Returns various system data (long or string)

  To get the value, must check the value of pbString:

  If FALSE, the value is a LONG returned by the function;
  If TRUE, the value is contained in pszString.
*/

LONG wbGetSystemInfo(LPCTSTR pszInfo, BOOL *pbIsString, LPTSTR pszString, UINT uLen)
{
	*pbIsString = FALSE;

	if(!stricmp(pszInfo,        "gdiobjects")) {

		*pbIsString = FALSE;
		return _GetGDIObjects();

	} else if(!stricmp(pszInfo, "userobjects")) {

		*pbIsString = FALSE;
		return _GetUserObjects();

	} else if(!stricmp(pszInfo, "instance")) {

		*pbIsString = FALSE;
		return (LONG)hAppInstance;

	} else if(!stricmp(pszInfo, "ospath")) {

		GetWindowsDirectory(pszString, uLen);
		*pbIsString = TRUE;
		if(*(pszString + strlen(pszString) - 1) != '\\')
			strcat(pszString, "\\");
		return 0;

	} else if(!stricmp(pszInfo, "systempath")) {

		GetSystemDirectory(pszString, uLen);
		*pbIsString = TRUE;
		if(*(pszString + strlen(pszString) - 1) != '\\')
			strcat(pszString, "\\");
		return 0;

	} else if(!stricmp(pszInfo, "fontpath")) {

		// Taken from comp.os.ms-windows.programmer.tools.mfc

		LPITEMIDLIST pidlFontDir;

		SHGetSpecialFolderLocation(NULL, CSIDL_FONTS, &pidlFontDir);
		SHGetPathFromIDList((LPCITEMIDLIST) pidlFontDir, pszString);
		*pbIsString = TRUE;
		if(*(pszString + strlen(pszString) - 1) != '\\')
			strcat(pszString, "\\");
		return 0;

	} else if(!stricmp(pszInfo, "pgmpath")) {

		// Taken from comp.os.ms-windows.programmer.tools.mfc

		LPITEMIDLIST pidlFontDir;

		SHGetSpecialFolderLocation(NULL, CSIDL_PROGRAM_FILES, &pidlFontDir);
		SHGetPathFromIDList((LPCITEMIDLIST) pidlFontDir, pszString);
		*pbIsString = TRUE;
		if(*(pszString + strlen(pszString) - 1) != '\\')
			strcat(pszString, "\\");
		return 0;

	} else if(!stricmp(pszInfo, "exepath")) {

		strncpy(pszString, GetCommandLine(), uLen);
		if(strchr(pszString, ' '))
			*strchr(pszString, ' ') = '\0';
		if(strchr(pszString, '\\'))
			*(strrchr(pszString, '\\') + 1) = '\0';
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "diskdrives")) {

		int drive;
		char szAux[5];
		DWORD dwDrives = GetLogicalDrives();

		// Build a string with the drive letters

		for(*pszString = '\0', drive = 0; drive < 32; drive++) {
			if(((dwDrives >> drive) & 0x01) == 0x01) {
				wsprintf(szAux, "%s%c:", (*pszString ? " " : ""), 'A' + drive);
				strcat(pszString, szAux);
			}
		}

		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "commandline")) {

		strncpy(pszString, GetCommandLine(), uLen);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "osversion")) {

		_GetOSVersionString(pszString);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "osnumber")) {

		OSVERSIONINFO ovInfo;

		ovInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		GetVersionEx(&ovInfo);

		sprintf(pszString, "%d.%d",
			ovInfo.dwMajorVersion,
			ovInfo.dwMinorVersion);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "consolemode")) {

		char title[MAX_PATH + 1];

		*pbIsString = FALSE;
		return GetConsoleTitle(title, MAX_PATH) ? TRUE : FALSE;

	} else if(!stricmp(pszInfo, "computername")) {

		GetComputerName(pszString, &uLen);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "username")) {

		GetUserName(pszString, &uLen);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "temppath")) {

		GetTempPath(uLen, pszString);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "screenarea")) {

		wsprintf(pszString, "%d %d %d %d", 0, 0,
			GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "workarea")) {

		RECT rc;

		SystemParametersInfo(SPI_GETWORKAREA, sizeof(LOGFONT), &rc, 0);
		wsprintf(pszString, "%d %d %d %d", rc.left, rc.top,
			rc.right - rc.left, rc.bottom - rc.top);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "colordepth")) {

		HDC	hdcScreen;
		HWND hwndMain;
		int bpp;

		*pbIsString = FALSE;

		hwndMain = GetForegroundWindow();
		hdcScreen = GetDC(hwndMain);
		bpp = GetDeviceCaps(hdcScreen, BITSPIXEL) * GetDeviceCaps(hdcScreen, PLANES);
		ReleaseDC(hwndMain, hdcScreen);
		return bpp;

	} else if(!stricmp(pszInfo, "systemfont")) {

		LOGFONT lfIcon;
		HDC hdc;

		SystemParametersInfo(SPI_GETICONTITLELOGFONT, sizeof(LOGFONT), &lfIcon, 0);
		hdc = CreateCompatibleDC(NULL);
		wsprintf(pszString, "%s %d %s%s", lfIcon.lfFaceName,
		(int)((float)72 * (float)-lfIcon.lfHeight / GetDeviceCaps(hdc, LOGPIXELSY)),
		(lfIcon.lfWeight >= FW_SEMIBOLD ? "Bold" : "Regular"),
		(lfIcon.lfItalic ? " Italic" : ""));
		DeleteDC(hdc);
		*pbIsString = TRUE;
		return 0;

	} else if(!stricmp(pszInfo, "appmemory")) {

		OSVERSIONINFO ovInfo;

		*pbIsString = FALSE;

		ovInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		GetVersionEx(&ovInfo);
		if(ovInfo.dwPlatformId != VER_PLATFORM_WIN32_NT)	// Only NT-based
			return 0;
		else {
			HANDLE hProcess;
			HMODULE hLib = NULL;
//			BOOL WINAPI (*w_GetProcessMemoryInfo)(HANDLE Process, PPROCESS_MEMORY_COUNTERS ppsmemCounters, DWORD cb);
			BOOL (WINAPI *w_GetProcessMemoryInfo)(HANDLE Process, PPROCESS_MEMORY_COUNTERS ppsmemCounters, DWORD cb);
			PROCESS_MEMORY_COUNTERS pmc;

			hLib = LoadLibrary("psapi.dll");
			if(hLib) {					// Is the DLL present?
				w_GetProcessMemoryInfo = (void *)GetProcAddress(hLib, "GetProcessMemoryInfo");
				if(!w_GetProcessMemoryInfo)
					return 0;
			}

			hProcess = GetCurrentProcess();
			if(!hProcess)
				return 0;

			if(w_GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc))) {
//				wsprintf(pszString, "%d", pmc.WorkingSetSize);
				ltoa(pmc.WorkingSetSize, pszString, 10);
				CloseHandle(hProcess);
				return pmc.WorkingSetSize;
			}
			return 0;
		}

	} else if(!stricmp(pszInfo, "totalmemory")) {

		MEMORYSTATUS mst;

		mst.dwLength = sizeof(MEMORYSTATUS);
		GlobalMemoryStatus(&mst);
		*pbIsString = FALSE;
		return mst.dwTotalPhys;

	} else if(!stricmp(pszInfo, "freememory")) {

		MEMORYSTATUS mst;

		mst.dwLength = sizeof(MEMORYSTATUS);
		GlobalMemoryStatus(&mst);
		*pbIsString = FALSE;
		return mst.dwAvailPhys;

	} else if(!stricmp(pszInfo, "backgroundcolor")) {

		*pbIsString = FALSE;
		return GetSysColor(COLOR_BTNFACE);

	} else {

		wbError(__FUNCTION__, MB_ICONWARNING, "Unrecognized parameter \"%s\".", pszInfo);
		*pbIsString = TRUE;
		*pszString = '\0';
		return -1;

	}
}

/* Transforms a UNIX or mixed DOS/UNIX path into a Windows path. */

LPTSTR MakeWinPath(LPTSTR pszPath)
{
	if(pszPath && *pszPath) {
		UINT i;

		for(i = 0; i < strlen(pszPath); i++)
			if(*(pszPath + i) == '/')
				*(pszPath + i) = '\\';
	}
	return pszPath;
}

//------------------------------------------------------------ PRIVATE FUNCTIONS

// Returns the hKey that corresponds to pszKey

static HKEY _GetKeyFromString(LPCTSTR pszKey)
{
	if(!stricmp(pszKey, "HKCU") || !stricmp(pszKey, "HKEY_CURRENT_USER"))
		return HKEY_CURRENT_USER;
	else if(!stricmp(pszKey, "HKLM") || !stricmp(pszKey, "HKEY_LOCAL_MACHINE"))
		return HKEY_LOCAL_MACHINE;
	else if(!stricmp(pszKey, "HKCR") || !stricmp(pszKey, "HKEY_CLASSES_ROOT"))
		return HKEY_CLASSES_ROOT;
	else if(!stricmp(pszKey, "HKU") || !stricmp(pszKey, "HKEY_USERS"))
		return HKEY_USERS;
	else if(!stricmp(pszKey, "HKCC") || !stricmp(pszKey, "HKEY_CURRENT_CONFIG"))
		return HKEY_CURRENT_CONFIG;
	else if(!stricmp(pszKey, "HKD") || !stricmp(pszKey, "HKEY_DYN_DATA"))
		return HKEY_DYN_DATA;
	else
		return NULL;
}

/* Counts User objects. */

static int _GetUserObjects(void)
{
	OSVERSIONINFO ovInfo;

	ovInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&ovInfo);

	if(ovInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
		return GetGuiResources(GetCurrentProcess(), GR_USEROBJECTS);
	} else
		return 0;
}

/* Counts GDI objects.

  Windows 95/98: Adapted from Leaks.exe source code (MS)
  // ******* TODO: test under Win98

*/

static int _GetGDIObjects(void)
{
	OSVERSIONINFO ovInfo;

	ovInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&ovInfo);

	if(ovInfo.dwPlatformId == VER_PLATFORM_WIN32_NT) {
		return GetGuiResources(GetCurrentProcess(), GR_GDIOBJECTS);
	} else {

		int nObjCount = 0;
		DWORD dwObjType;
		DWORD dwhGdi;

		// Test all possible handle values

		for(dwhGdi = 0; dwhGdi < 0xFFFF; dwhGdi++) {
			dwObjType = GetObjectType((HGDIOBJ)dwhGdi);
			switch(dwObjType) {

				// 16-bit GDI heap

				case OBJ_BITMAP:
				case OBJ_BRUSH:
				case OBJ_PAL:
				case OBJ_PEN:
				case OBJ_DC:
				case OBJ_MEMDC:
				case OBJ_EXTPEN:
				case OBJ_METADC:
				case OBJ_ENHMETADC:
					if((dwhGdi & 2) && ((dwhGdi % 2) == 0) && (dwhGdi <= 0x6000))
						nObjCount++;
					break;

				// Undocumented special cases

				case OBJ_METAFILE:
				case OBJ_ENHMETAFILE:
				case OBJ_COLORSPACE:
					nObjCount++;
					break;

				// 32-bit GDI heap

				case OBJ_FONT:
				case OBJ_REGION:
					if((dwhGdi % 4) == 0)
						nObjCount++;
					break;
			}
		}

		return nObjCount;
	}
}

// This code is adapted from MSDN article 'Getting the system version':
// http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/base/getting_the_system_version.asp

static BOOL _GetOSVersionString(LPTSTR pszString)
{
	char szOS[256] ="";
	char szVer[256] ="";
	char szSP[256] ="";
	OSVERSIONINFOEX osvi;
	BOOL bOsVersionInfoEx;

	// Try calling GetVersionEx using the OSVERSIONINFOEX structure.
	// if that fails, try using the OSVERSIONINFO structure.

	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

	if(!(bOsVersionInfoEx = GetVersionEx ((OSVERSIONINFO *) &osvi))) {
		osvi.dwOSVersionInfoSize = sizeof (OSVERSIONINFO);
		if(!GetVersionEx((OSVERSIONINFO *) &osvi))
			return FALSE;
	}

	switch(osvi.dwPlatformId) {


		// Test for the Windows NT product family.

		case VER_PLATFORM_WIN32_NT:

			// Test for the specific product.
			if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2)
				strcpy(szOS,"Microsoft Windows Server 2003,");

			if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 1)
				strcpy(szOS,"Microsoft Windows XP");

			if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0)
				strcpy(szOS,"Microsoft Windows 2000");

			if(osvi.dwMajorVersion <= 4)
				strcpy(szOS,"Microsoft Windows NT");

			if(bOsVersionInfoEx) {		// Test for specific product on Windows NT 4.0 SP6 and later.

				// Test for the workstation type.

				if(osvi.wProductType == VER_NT_WORKSTATION) {

					if(osvi.dwMajorVersion == 4)
						strcpy(szVer,"Workstation 4.0");
					else if(osvi.wSuiteMask & VER_SUITE_PERSONAL)
						strcpy(szVer,"Home Edition");
					else
						strcpy(szVer,"Professional");

				} else if(osvi.wProductType == VER_NT_SERVER || osvi.wProductType == VER_NT_DOMAIN_CONTROLLER) {

					// Test for the server type.

					if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 2) {
						if(osvi.wSuiteMask & VER_SUITE_DATACENTER)
							strcpy(szVer,"Datacenter Edition");
						else if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
							strcpy(szVer,"Enterprise Edition");
						else if(osvi.wSuiteMask == VER_SUITE_BLADE)
							strcpy(szVer,"Web Edition");
						else
							strcpy(szVer,"Standard Edition");
					} else if(osvi.dwMajorVersion == 5 && osvi.dwMinorVersion == 0) {
						if(osvi.wSuiteMask & VER_SUITE_DATACENTER)
							strcpy(szVer,"Datacenter Server");
						else if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
							strcpy(szVer,"Advanced Server");
						else
							strcpy(szVer,"Server");
					} else { // Windows NT 4.0
						if(osvi.wSuiteMask & VER_SUITE_ENTERPRISE)
							strcpy(szVer,"Server 4.0, Enterprise Edition");
						else
							strcpy(szVer,"Server 4.0");
					}
				}

			} else {		// Test for specific product on Windows NT 4.0 SP5 and earlier

				HKEY hKey;
				char szProductType[80];
				DWORD dwBufLen = 80;
				LONG lRet;

				lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Control\\ProductOptions", 0, KEY_QUERY_VALUE, &hKey);
				if(lRet != ERROR_SUCCESS)
					return FALSE;

				lRet = RegQueryValueEx(hKey, "ProductType", NULL, NULL, (LPBYTE) szProductType, &dwBufLen);
				if((lRet != ERROR_SUCCESS) || (dwBufLen > 80))
					return FALSE;

				RegCloseKey(hKey);

				if(lstrcmpi("WINNT", szProductType) == 0)
					strcpy(szVer,"Workstation");
				if(lstrcmpi("LANMANNT", szProductType) == 0)
					strcpy(szVer,"Server");
				if(lstrcmpi("SERVERNT", szProductType) == 0)
					strcpy(szVer,"Advanced Server");

				sprintf(szSP,"%d.%d", osvi.dwMajorVersion, osvi.dwMinorVersion);
			}

			// Display service pack (if any) and build number.

			if(osvi.dwMajorVersion == 4 && lstrcmpi(osvi.szCSDVersion,"Service Pack 6") == 0) {
				HKEY hKey;
				LONG lRet;

				// Test for SP6 versus SP6a.
				lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Hotfix\\Q246009", 0, KEY_QUERY_VALUE, &hKey);
				if(lRet == ERROR_SUCCESS)
					sprintf(szSP,"Service Pack 6a (Build %d)", osvi.dwBuildNumber & 0xFFFF);
				else  {
					// Windows NT 4.0 prior to SP6a
					sprintf(szSP,"%s (Build %d)", osvi.szCSDVersion, osvi.dwBuildNumber & 0xFFFF);
				}

				RegCloseKey(hKey);

			} else {
				// not Windows NT 4.0
				sprintf(szSP,"%s (Build %d)", osvi.szCSDVersion, osvi.dwBuildNumber & 0xFFFF);
			}

			break;

		// Test for Windows Me/98/95.

		case VER_PLATFORM_WIN32_WINDOWS:

			if(osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 0) {
				 strcpy(szOS,"Microsoft Windows 95");
				 if(osvi.szCSDVersion[1] == 'C' || osvi.szCSDVersion[1] == 'B')
					 sprintf(pszString,"OSR2");
			}

			if(osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 10) {
				 strcpy(szOS,"Microsoft Windows 98");
				 if(osvi.szCSDVersion[1] == 'A')
					 sprintf(pszString,"SE");
			}

			if(osvi.dwMajorVersion == 4 && osvi.dwMinorVersion == 90) {
				 strcpy(szOS,"Microsoft Windows Millennium Edition");
			}
			break;

		case VER_PLATFORM_WIN32s:

			strcpy(szOS,"Microsoft Win32s");
			break;
	}

	sprintf(pszString,"%s %s %s", szOS, szVer, szSP);

	return TRUE;
}

static HCURSOR GetSysCursor(LPCTSTR pszCursor)
{
	LPTSTR pszCursorName;

	// Selects a system cursor

	if(!(pszCursor && *pszCursor))
		pszCursorName = IDC_ARROW;
	else if(!stricmp(pszCursor, "arrow"))
		pszCursorName = IDC_ARROW;
	else if(!stricmp(pszCursor, "wait"))
		pszCursorName = IDC_WAIT;
	else if(!stricmp(pszCursor, "cross"))
		pszCursorName = IDC_CROSS;
	else if(!stricmp(pszCursor, "help"))
		pszCursorName = IDC_HELP;
	else if(!stricmp(pszCursor, "waitarrow"))
		pszCursorName = IDC_APPSTARTING;
	else if(!stricmp(pszCursor, "ibeam"))
		pszCursorName = IDC_IBEAM;
	else if(!stricmp(pszCursor, "help"))
		pszCursorName = IDC_ARROW;
	else if(!stricmp(pszCursor, "finger"))
		pszCursorName = IDC_HAND;
	else if(!stricmp(pszCursor, "sizeall"))
		pszCursorName = IDC_SIZEALL;
	else if(!stricmp(pszCursor, "sizens"))
		pszCursorName = IDC_SIZENS;
	else if(!stricmp(pszCursor, "sizewe"))
		pszCursorName = IDC_SIZEWE;
	else if(!stricmp(pszCursor, "sizenesw"))
		pszCursorName = IDC_SIZENESW;
	else if(!stricmp(pszCursor, "sizenwse"))
		pszCursorName = IDC_SIZENWSE;
	else if(!stricmp(pszCursor, "uparrow"))
		pszCursorName = IDC_UPARROW;
	else if(!stricmp(pszCursor, "forbidden"))
		pszCursorName = IDC_NO;
	else if(!stricmp(pszCursor, "none"))
		return (HCURSOR)-1;
	else {
		wbError(__FUNCTION__, MB_ICONWARNING, "Cursor style \"%s\" does not exist", pszCursor);
		return NULL;
	}
	return LoadCursor(NULL, pszCursorName);
}

/*
// DEBUGGING FUNCTION
void printthem(void)
{
	int nClass;

	for(nClass = 0; nClass < NUMCLASSES; nClass++)
		printf("%04X ", hClassCursor[nClass]);
	printf("\n");
}
*/

//------------------------------------------------------------------ END OF FILE
