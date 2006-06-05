/*******************************************************************************

 WINBINDER - A native Windows binding

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Functions for Windows controls

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "wb.h"
#include <time.h>				// For time_t
#include <stdlib.h>				// For itoa(), atoi()
#include <shellapi.h>			// For Shell_NotifyIcon()

#ifdef _MSC_VER
#	include <richedit.h>			// For EM
#endif

//-------------------------------------------------------------------- CONSTANTS

#define MAXWINCLASS		32

//-------------------------------------------------------------------- VARIABLES

// Global

WNDPROC lpfnFrameProcOld = NULL;
WNDPROC lpfnEditProcOld = NULL;
WNDPROC lpfnHyperLinkProcOld = NULL;
WNDPROC lpfnInvisibleProcOld = NULL;

// External

extern BOOL SetTaskBarIcon(HWND hwnd, BOOL bModify);
extern BOOL wbSetMenuItemText(PWBOBJ pwbo, LPCTSTR pszText);
extern DWORD GetCalendarTime(PWBOBJ pwbo);
extern BOOL SetCalendarTime(PWBOBJ pwbo, time_t UnixTime);

extern BOOL DisplayHTMLString(PWBOBJ pwbo, LPCTSTR string);
//extern BOOL DisplayHTMLPage(PWBOBJ pwbo, LPCTSTR pszWebPageName);
extern BOOL EmbedBrowserObject(PWBOBJ pwbo);

//---------------------------------------------------------- FUNCTION PROTOTYPES

// Private

static BOOL SetTransparentBitmap(HWND hwnd, HBITMAP hbmBits, BOOL bStatic, COLORREF clTransp);
static HWND CreateToolTip(PWBOBJ pwbo);

static LRESULT CALLBACK FrameProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK EditProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK InvisibleProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// External

extern void SetStatusBarHandle(HWND hCtrl);
extern BOOL IsBitmap(HANDLE handle);
extern BOOL IsIcon(HANDLE handle);
extern BOOL RegisterControlInTab(PWBOBJ pwboParent, PWBOBJ pwbo, UINT id, UINT nTab);
extern LRESULT CALLBACK HyperLinkProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

//----------------------------------------------------------- EXPORTED FUNCTIONS

/*
	TODO: Call wbCreateToolbar() if wbclass is a toolbar
	TODO: Call wbCreateMenu() if wbclass is a menu
*/

PWBOBJ wbCreateControl(PWBOBJ pwboParent, UINT uWinBinderClass, LPCTSTR pszCaption,
  int xPos, int yPos, int nWidth, int nHeight, UINT id, DWORD dwWBStyle, long lParam, int nTab)
{
	PWBOBJ pwbo;
	LPTSTR pszClass;
	int nVisible;
	DWORD dwStyle, dwExStyle;
	HWND hTab;

	if(!pwboParent || !pwboParent->hwnd || !IsWindow(pwboParent->hwnd)) {
		wbError(__FUNCTION__, MB_ICONWARNING, "Cannot create control if parent window is NULL");
		return NULL;
	}
	pwbo = wbMalloc(sizeof(WBOBJ));
	if(!pwbo)
		return NULL;

	pwbo->hwnd = NULL;
	pwbo->id = id;
	pwbo->uClass = uWinBinderClass;
	pwbo->item = -1;
	pwbo->subitem = -1;
	pwbo->style = dwWBStyle;
	pwbo->parent = pwboParent;
	pwbo->pszCallBackFn = NULL;
	pwbo->lparam = lParam;
	ZeroMemory(pwbo->lparams, sizeof(LONG) * 8);
	pwbo->pbuffer = NULL;

	// If parent is a tab control, change the parent to a page handle

	if(pwboParent->uClass == TabControl) {

		PTABDATA pTabData;

		pTabData = (PTABDATA)pwboParent->lparam;

		// nTab is the page index

		nTab = MIN(MIN((UINT)nTab, pTabData->nPages - 1), MAX_TABS);
		hTab = pTabData->page[nTab].hwnd ?
		  pTabData->page[nTab].hwnd : pwboParent->hwnd;

	}

	// Set visible / enabled flags

	nVisible = BITTEST(dwWBStyle, WBC_INVISIBLE) ? 0 : WS_VISIBLE;
	nVisible |= BITTEST(dwWBStyle, WBC_DISABLED) ? WS_DISABLED : 0;

	if(BITTEST(dwWBStyle, WBC_BORDER))
		dwExStyle = WS_EX_STATICEDGE;
	else
		dwExStyle = 0;

	// Set Windows class and styles according to WinBinder class

	switch(uWinBinderClass) {

		//-------------------------------- Regular child controls

		case HyperLink:

			pszClass = "STATIC";
			dwStyle = WS_CHILD | SS_NOTIFY | SS_LEFT | nVisible;
			dwExStyle = WS_EX_TRANSPARENT;
			break;

		case Label:

			pszClass = "STATIC";
			if(BITTEST(dwWBStyle, WBC_ELLIPSIS))
				dwStyle = WS_CHILD | SS_WORDELLIPSIS | nVisible;
			else
				dwStyle = WS_CHILD | nVisible;

			if(BITTEST(dwWBStyle, WBC_CENTER))
				dwStyle |= SS_CENTER;
			else if(BITTEST(dwWBStyle, WBC_RIGHT))
				dwStyle |= SS_RIGHT;
			else {
				dwStyle |= SS_LEFT;
				if(!BITTEST(dwWBStyle, WBC_MULTILINE))
					dwStyle |= SS_LEFTNOWORDWRAP;
			}
			break;

		case Frame:
			if((nWidth > nHeight) && nHeight <= 8) {			// Horizontal line
				pszClass = "STATIC";
				dwStyle = WS_CHILD | SS_ETCHEDHORZ | nVisible;
			} else if((nWidth < nHeight) && nWidth <= 8) {		// Vertical line
				pszClass = "STATIC";
				dwStyle = WS_CHILD | SS_ETCHEDVERT | nVisible;
			} else if(BITTEST(dwWBStyle, WBC_IMAGE)) {			// Image
				pszClass = "STATIC";
				dwStyle = WS_CHILD | SS_WORDELLIPSIS | SS_CENTERIMAGE | nVisible;
				if(BITTEST(dwWBStyle, WBC_CENTER))
					dwStyle |= SS_CENTER;
				else if(BITTEST(dwWBStyle, WBC_RIGHT))
					dwStyle |= SS_RIGHT;
				else
					dwStyle |= SS_LEFT;
			} else {											// Group box
				pszClass = "BUTTON";
				dwStyle = WS_CHILD | BS_GROUPBOX | nVisible;
				dwExStyle |= WS_EX_TRANSPARENT;
			}
			break;

		case Calendar:
			pszClass = MONTHCAL_CLASS;
			dwStyle = (BITTEST(dwWBStyle, WBC_BORDER) ? WS_BORDER : 0) | WS_CHILD | WS_VISIBLE | MCS_DAYSTATE | nVisible;
			break;

		case PushButton:
			pszClass = "BUTTON";
			dwStyle = WS_CHILD | WS_TABSTOP | BS_PUSHBUTTON | BS_NOTIFY | nVisible;
			break;

		case ImageButton:
			pszClass = "BUTTON";
			dwStyle = WS_CHILD | WS_TABSTOP | BS_OWNERDRAW | nVisible;
			break;

		case InvisibleArea:
			pszClass = "STATIC";
			dwStyle = WS_CHILD | SS_NOTIFY | SS_SIMPLE | nVisible;
			dwExStyle = WS_EX_TRANSPARENT;
//			pwbo->lparam = (LPARAM)dwWBStyle;
			break;

		case CheckBox:
			pszClass = "BUTTON";
			dwStyle = WS_CHILD | WS_TABSTOP | BS_AUTOCHECKBOX | BS_NOTIFY | nVisible;
			break;

		case RadioButton:
			pszClass = "BUTTON";
			dwStyle = WS_CHILD | WS_TABSTOP | BS_AUTORADIOBUTTON | BS_NOTIFY | nVisible;
			if(BITTEST(dwWBStyle, WBC_GROUP))
				dwStyle |= WS_GROUP;
			break;

		case EditBox:
			pszClass = "EDIT";

			dwStyle = WS_CHILD | WS_TABSTOP | nVisible;
			if(BITTEST(dwWBStyle, WBC_READONLY))
				dwStyle |= ES_READONLY;
			if(BITTEST(dwWBStyle, WBC_MASKED))
				dwStyle |= ES_PASSWORD;
			if(BITTEST(dwWBStyle, WBC_NUMBER))
				dwStyle |= ES_NUMBER;
			if(BITTEST(dwWBStyle, WBC_MULTILINE)) {
				if(BITTEST(dwWBStyle, WBC_READONLY))
					dwStyle |= WS_VSCROLL | ES_MULTILINE;
				else
					dwStyle |= WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN;
			} else {
				dwStyle |= ES_AUTOHSCROLL;
				if(BITTEST(dwWBStyle, WBC_CENTER))
					dwStyle |= ES_CENTER;
				else if(BITTEST(dwWBStyle, WBC_RIGHT))
					dwStyle |= ES_RIGHT;
				else
					dwStyle |= ES_LEFT;
			}
			dwExStyle |= WS_EX_CLIENTEDGE;
			break;

		case RTFEditBox:
			pszClass = RICHEDITCONTROL;
			dwStyle = WS_CHILD | WS_TABSTOP | nVisible;
			if(BITTEST(dwWBStyle, WBC_READONLY))
				dwStyle |= ES_READONLY | WS_VSCROLL | ES_MULTILINE;
			else
				dwStyle |= WS_VSCROLL | ES_MULTILINE | ES_WANTRETURN;
			if(BITTEST(dwWBStyle, WBC_CENTER))
				dwStyle |= ES_CENTER;
			else if(BITTEST(dwWBStyle, WBC_RIGHT))
				dwStyle |= ES_RIGHT;
			else
				dwStyle |= ES_LEFT;
			dwExStyle |= WS_EX_CLIENTEDGE;
			break;

		case ListBox:
			pszClass = "LISTBOX";
			dwStyle = WS_CHILD | WS_TABSTOP | WS_VSCROLL | LBS_NOTIFY | nVisible;
			if(BITTEST(dwWBStyle, WBC_SORT))
				dwStyle |= LBS_SORT;
			dwExStyle |= WS_EX_CLIENTEDGE;
			break;

		case ComboBox:
			pszClass = "COMBOBOX";
			dwStyle = WS_CHILD | WS_TABSTOP | WS_VSCROLL | nVisible;
			if(BITTEST(dwWBStyle, WBC_READONLY))
				dwStyle |= CBS_DROPDOWNLIST;
			else
				dwStyle |= CBS_DROPDOWN;
			if(BITTEST(dwWBStyle, WBC_SORT))
				dwStyle |= CBS_SORT;
			break;

		case ScrollBar:
			pszClass = "SCROLLBAR";
			if(nHeight >= nWidth)
				dwStyle = WS_CHILD | WS_TABSTOP | SBS_VERT | nVisible;
			else
				dwStyle = WS_CHILD | WS_TABSTOP | nVisible;
			break;

		case ListView:
			pszClass = WC_LISTVIEW;
			dwStyle = WS_CHILD | WS_TABSTOP | LVS_REPORT | LVS_SHOWSELALWAYS | LVS_NOLABELWRAP | nVisible;
			if(!BITTEST(dwWBStyle, WBC_SORT))
				dwStyle |= LVS_NOSORTHEADER;
			if(BITTEST(dwWBStyle, WBC_SINGLE))
				dwStyle |= LVS_SINGLESEL;
			dwExStyle |= WS_EX_CLIENTEDGE;
			break;

		case Spinner:
			pszClass = UPDOWN_CLASS;
			if(BITTEST(dwWBStyle, WBC_GROUP))
				dwStyle = WS_CHILD | WS_TABSTOP | UDS_ARROWKEYS | UDS_NOTHOUSANDS | UDS_AUTOBUDDY | UDS_SETBUDDYINT | nVisible;
			else
				dwStyle = WS_CHILD | WS_TABSTOP | UDS_ARROWKEYS | UDS_NOTHOUSANDS | nVisible;
			break;

		case Gauge:
			pszClass = PROGRESS_CLASS;
			dwStyle = WS_CHILD | nVisible;
			break;

		case Slider:
			pszClass = TRACKBAR_CLASS;
			if(BITTEST(dwWBStyle, WBC_LINES))
				dwStyle = WS_CHILD | WS_TABSTOP | TBS_AUTOTICKS | nVisible;
			else
				dwStyle = WS_CHILD | WS_TABSTOP | TBS_NOTICKS | nVisible;
			break;

		case TreeView:
			{
				PTREEDATA ptrdt;
				int i;

				pszClass = WC_TREEVIEW;
				dwStyle = WS_CHILD | WS_TABSTOP | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS | nVisible;
				dwExStyle |= WS_EX_CLIENTEDGE;

				// Attach a structure to the treeview control and initialize it

				ptrdt = wbMalloc(sizeof(TREEDATA));
//				memset(ptrdt, 0, sizeof(TREEDATA));

				ptrdt->hLast = TVI_ROOT;
				for(i = 0; i < MAX_TREEVIEW_LEVELS; i++) {
					ptrdt->hParent[i] = TVI_ROOT;
					ptrdt->bCustomImages[i] = FALSE;
				}
				ptrdt->nLastLevel = 0;
				pwbo->lparam = (LPARAM)ptrdt;
			}
			break;

		case StatusBar:
			pszClass =  STATUSCLASSNAME;
			if(BITTEST(GetWindowLong(pwboParent->hwnd, GWL_STYLE), WS_THICKFRAME))
				dwStyle = WS_CHILD | CCS_BOTTOM | CCS_NOMOVEY | SBARS_SIZEGRIP | nVisible;
			else
				dwStyle = WS_CHILD | CCS_BOTTOM | CCS_NOMOVEY | nVisible;
			break;

		case TabControl:
			pszClass = WC_TABCONTROL;
			dwStyle = WS_CHILD | WS_TABSTOP | WS_CLIPCHILDREN | nVisible;
			{
				PTABDATA pTabData;

				// Alloc memory for tab data

				pTabData = wbMalloc(sizeof(TABDATA));
				memset(pTabData, 0, sizeof(TABDATA));
				pwbo->lparam = (LPARAM)pTabData;
				pwbo->uClass = TabControl;

			}
			break;

		case HTMLControl:
			pszClass = BROWSER_WINDOW_CLASS;
			dwStyle = WS_CHILD | nVisible;
			break;

		default:
			wbError(__FUNCTION__, MB_ICONWARNING, "Unknown control class %d", uWinBinderClass);
			return NULL;

	} // end switch

	// Create the control

	pwbo->hwnd = CreateWindowEx(
		dwExStyle,
		pszClass,
		pszCaption && *pszCaption ? pszCaption : "",
		dwStyle,
		xPos, yPos, nWidth, nHeight,
		(pwboParent->uClass == TabControl) ? hTab : (pwboParent ? pwboParent->hwnd : NULL),
		(HMENU)id,
		hAppInstance,
		NULL
	);

	if(!pwbo->hwnd) {
		wbError(__FUNCTION__, MB_ICONWARNING, "Error creating control of class %d ('%s')",
		  uWinBinderClass, pszClass);
		return NULL;
	}

	// Further processing after control creation

	switch(pwbo->uClass) {

		case HTMLControl:
			EmbedBrowserObject(pwbo);
			break;

		case ImageButton:
			CreateToolTip(pwbo);
			if(lParam)		// Check button
				SendMessage(pwbo->hwnd, BM_SETCHECK, TRUE, 0);
			break;

		case RadioButton:
		case CheckBox:
		case PushButton:

			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			if(lParam)		// Check button
				SendMessage(pwbo->hwnd, BM_SETCHECK, TRUE, 0);
			break;

		case EditBox:			// Subclasses edit box to process keyboard messages
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			lpfnEditProcOld = (WNDPROC)SetWindowLong(pwbo->hwnd, GWL_WNDPROC, (LONG)EditProc);
			break;

		case TabControl:		// Subclasses tab control to process WM_COMMAND
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
//			lpfnTabProcOld = (WNDPROC)SetWindowLong(pwbo->hwnd, GWL_WNDPROC, (LONG)TabProc);
			wbSetTabControlText(pwbo, pszCaption);

			// Assign window handler, if any

//			if(pwbo->parent && pwbo->parent->pszCallBackFn && *pwbo->parent->pszCallBackFn)
//				pwbo->pszCallBackFn = pwbo->parent->pszCallBackFn;
			break;

		case Frame:				// Subclasses Frame control to process WM_COMMAND
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			if(!stricmp(pszClass, "BUTTON"))		// Only for group boxes!
				lpfnFrameProcOld = (WNDPROC)SetWindowLong(pwbo->hwnd, GWL_WNDPROC, (LONG)FrameProc);
			break;

		case InvisibleArea:		// Subclasses InvisibleArea to process WM_MOUSEMOVE
			lpfnInvisibleProcOld = (WNDPROC)SetWindowLong(pwbo->hwnd, GWL_WNDPROC, (LONG)InvisibleProc);
			break;

		case Spinner:
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			SendMessage(pwbo->hwnd, UDM_SETRANGE, 0, MAKELONG(100, 0));
			SendMessage(pwbo->hwnd, UDM_SETPOS, 0, MAKELONG((short)0, 0));
			break;

		case ScrollBar:
			SendMessage(pwbo->hwnd, SBM_SETRANGE, 0, 100);
			break;

		case StatusBar:
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			SetStatusBarHandle(pwbo->hwnd);
			break;

		case ListView:
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			SendMessage(pwbo->hwnd, LVM_SETEXTENDEDLISTVIEWSTYLE, 0, LVS_EX_FULLROWSELECT | LVS_EX_HEADERDRAGDROP | LVS_EX_LABELTIP | LVS_EX_SUBITEMIMAGES);
			break;

		case RTFEditBox:
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			SendMessage(pwbo->hwnd, EM_FMTLINES, TRUE, 0);
			SendMessage(pwbo->hwnd, EM_SETEVENTMASK, 0, ENM_CHANGE);	// Enables EN_CHANGE messages. Should be EN_UPDATE instead?
			SetWindowText(pwbo->hwnd, pszCaption);
			break;

		case HyperLink:			// Subclasses static control
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			lpfnHyperLinkProcOld = (WNDPROC)SetWindowLong(pwbo->hwnd, GWL_WNDPROC, (LONG)HyperLinkProc);
			break;

		default:
			// Set the control font
			SendMessage(pwbo->hwnd, WM_SETFONT, (WPARAM)hIconFont, 0);
			break;
	}

	// Add any additional styles that may be present

	wbSetStyle(pwbo, dwWBStyle, TRUE);

	// Is the parent window a tab control?

	if(pwboParent->uClass == TabControl)
		RegisterControlInTab(pwboParent, pwbo, id, nTab);

	SetWindowLong(pwbo->hwnd, GWL_USERDATA, (LONG)pwbo);

	return pwbo;
}


/* Destroy a control created by wbCreateControl(). */

BOOL wbDestroyControl(PWBOBJ pwbo)
{
	if(!pwbo || !pwbo->hwnd || !IsWindow(pwbo->hwnd))
		return FALSE;

	switch(pwbo->uClass) {
		case TreeView:
		case TabControl:
			wbFree((void *)pwbo->lparam);
			break;
	}
	return DestroyWindow(pwbo->hwnd);
}


/*
	TODO: Process treeview items?
	TODO: Must validate toolbar item first
*/

PWBOBJ wbGetControl(PWBOBJ pwboParent, int id)
{
	PWBOBJ pwbo;

	if(!wbIsWBObj(pwboParent, TRUE)) {				// Is it a valid control?
		wbError(__FUNCTION__, MB_ICONWARNING, "First parameter is not a valid WinBinder control");
		return NULL;
	}

	if(pwboParent->uClass == Menu) {

		if(IsMenu((HMENU)pwboParent->hwnd)) {		// Is it a menu?

			MENUITEMINFO mi;

			mi.cbSize = sizeof(MENUITEMINFO);
			mi.fMask = MIIM_ID;
			if(GetMenuItemInfo((HMENU)pwboParent->hwnd, id, FALSE, &mi)) {

				pwbo = wbMalloc(sizeof(WBOBJ));
				memcpy(pwbo, pwboParent, sizeof(WBOBJ));
				pwbo->id = id;

			} else {

				wbError(__FUNCTION__, MB_ICONWARNING, "Menu item #%d not found in menu #%d", id, (int)pwboParent->hwnd);
				return NULL;
			}
		} else {
			wbError(__FUNCTION__, MB_ICONWARNING, "Menu object does not have a valid menu handle");
			return NULL;
		}

	} else if(!IsWindow(pwboParent->hwnd)) {			// Is it a window?

		wbError(__FUNCTION__, MB_ICONWARNING, "Object does not have a valid window handle");
		return NULL;

	} else {											// Yes, it's a window

		switch(pwboParent->uClass) {

			case ToolBar:								// It's a toolbar

				pwbo = wbMalloc(sizeof(WBOBJ));
				pwbo->hwnd = pwboParent->hwnd;
				pwbo->id = id;
				pwbo->uClass = pwboParent->uClass;
				pwbo->item = -1;
				pwbo->subitem = -1;
				pwbo->style = 0;
				pwbo->parent = pwboParent;
				pwbo->pszCallBackFn = NULL;
				pwbo->lparam = 0;
				pwbo->pbuffer = NULL;
				break;

			default:									// Regular window classes
				{
					HWND hCtrl;

					hCtrl = GetDlgItem(pwboParent->hwnd, id);

					if(hCtrl) {

						// It's a regular control

						if(IsWindow(hCtrl)) {
							pwbo = (PWBOBJ)GetWindowLong(hCtrl, GWL_USERDATA);
						} else {
							pwbo = wbMalloc(sizeof(WBOBJ));
							pwbo->hwnd = hCtrl;
							pwbo->id = id;
							pwbo->uClass = pwboParent->uClass;
							pwbo->item = -1;
							pwbo->subitem = -1;
							pwbo->style = 0;
							pwbo->parent = pwboParent;
							pwbo->pszCallBackFn = NULL;
							pwbo->lparam = 0;
							pwbo->pbuffer = NULL;
						}

					} else {

						// Is its parent a tab control?

						if(pwboParent->uClass == TabControl) {

							// Yes, let's try to find it

							PTABDATA pTabData;
							UINT i;

							pTabData = (PTABDATA)pwboParent->lparam;

							for(i = 0; i < pTabData->nCtrls; i++) {
								if(pTabData->ctrl[i].id == (UINT)id) {

									hCtrl = pTabData->ctrl[i].hwnd;

									if(IsWindow(hCtrl)) {
										pwbo = (PWBOBJ)GetWindowLong(hCtrl, GWL_USERDATA);
									} else {
										pwbo = NULL;
									}
									break;
								}
							}

						} else {

							// No, control does not exist

							char szText[256];

							wbGetText(pwboParent, szText, 255);
							wbError(__FUNCTION__, MB_ICONWARNING, "Control #%d not found in window '%s'", id, szText);
							return NULL;
						}
					}
				}
		} // switch
	} // else

	return pwbo;
}


BOOL wbSetText(PWBOBJ pwbo, LPCTSTR pszText, int nItem)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case Spinner:

			// Change text of "buddy" control. The buddy is the edit box attached to the Up-down control
			{
				HWND hBuddy = (HWND)SendMessage(pwbo->hwnd, UDM_GETBUDDY, 0, 0);

				if(hBuddy)
					return SetWindowText(hBuddy, pszText);
				else
					return FALSE;
			}
			break;

		case TabControl:

			return wbSetTabControlText(pwbo, pszText);

		case Menu:

			pwbo->id = nItem;
			return wbSetMenuItemText(pwbo, pszText);

		case HTMLControl:
//			if(nItem)
//				return DisplayHTMLPage(pwbo, pszText);
//			else
				return DisplayHTMLString(pwbo, pszText);

		default:

			return SetWindowText(pwbo->hwnd, pszText);
	}
}

/*
	Limitation: Treeview items <= 1024 characters
*/

UINT wbGetTextLength(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case Spinner:
			{
				// Measure length of text of "buddy" control. The buddy is the edit box attached to the Up-down control

				HWND hBuddy;

				hBuddy = (HWND)SendMessage(pwbo->hwnd, UDM_GETBUDDY, 0, 0);
				return GetWindowTextLength(hBuddy);
			}

		case ListBox:
			{
				int nIndex;

				nIndex = SendMessage(pwbo->hwnd, LB_GETCURSEL, 0, 0);
				if(nIndex == LB_ERR)
					return 0;
				return SendMessage(pwbo->hwnd, LB_GETTEXTLEN, nIndex, 0);
			}

		case ComboBox:
			{
				// lparam < 0 means the child edit control was modified

				if(pwbo->lparam < 0) {
					return SendMessage(pwbo->hwnd, WM_GETTEXTLENGTH, 0, 0);
				} else {
					return SendMessage(pwbo->hwnd, CB_GETLBTEXTLEN, pwbo->lparam, 0);
				}
			}

		case TreeView:
			{
				TV_ITEM tvi;
				char szText[MAX_ITEM_STRING];

				tvi.hItem = TreeView_GetSelection(pwbo->hwnd);
				if(!tvi.hItem)
					return 0;

				tvi.pszText = szText;
				tvi.cchTextMax = MAX_ITEM_STRING;
				tvi.mask = TVIF_TEXT;
				TreeView_GetItem(pwbo->hwnd, &tvi);
				if(tvi.pszText && *tvi.pszText)
					return strlen(tvi.pszText);
				else
					return 0;
			}

		default:
			/*
				TODO: Trying to fix control text length bug

				According to WinHelp for GetWindowTextLength, "To obtain the exact length of
				the text, use (...) the GetWindowText function." Makes no difference, however.
			{
				char *pszText;
				int nLen;

				pszText = wbMalloc(32767);
				nLen = GetWindowText(pwbo->hwnd, pszText, 32767);
				wbFree(pszText);
				return nLen;
			}*/
			return GetWindowTextLength(pwbo->hwnd);
	}
}

BOOL wbGetText(PWBOBJ pwbo, LPTSTR pszText, UINT nMaxChars)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	if(!nMaxChars)
		return FALSE;

	*pszText = '\0';

	switch(pwbo->uClass) {

		case Spinner:
			{
				// Reads text of "buddy" control. The buddy is the edit box attached to the Up-down control
				HWND hBuddy;

				hBuddy = (HWND)SendMessage(pwbo->hwnd, UDM_GETBUDDY, 0, 0);
				GetWindowText(hBuddy, pszText, nMaxChars);
				return TRUE;
			}

		case ListBox:
			{
				int nIndex;
				BOOL bRet;

				if(pwbo->item < 0) {
					nIndex = SendMessage(pwbo->hwnd, LB_GETCURSEL, 0, 0);
					if(nIndex == LB_ERR)
						return FALSE;
				} else {
					nIndex = pwbo->item;
				}

				bRet = SendMessage(pwbo->hwnd, LB_GETTEXT, nIndex, (LPARAM)(LPTSTR)pszText);
				return (bRet != LB_ERR);
			}

		case ComboBox:

			// lparam < 0 means the child edit control was modified

			if(pwbo->lparam < 0) {
				SendMessage(pwbo->hwnd, WM_GETTEXT, nMaxChars, (LPARAM)pszText);
				return TRUE;
			} else{
				int nIndex;
				BOOL bRet;

				if(pwbo->item < 0) {
					nIndex = SendMessage(pwbo->hwnd, CB_GETCURSEL, 0, 0);
					if(nIndex == CB_ERR) {
						return FALSE;
					}
				} else {
					nIndex = pwbo->item;
				}

				bRet = SendMessage(pwbo->hwnd, CB_GETLBTEXT, nIndex, (LPARAM)(LPTSTR)pszText);
				return (bRet != CB_ERR);
			}

		case TreeView:

			{
				TV_ITEM tvi;

				tvi.hItem = TreeView_GetSelection(pwbo->hwnd);
				if(!tvi.hItem)
					return FALSE;
				tvi.pszText = pszText;
				tvi.cchTextMax = nMaxChars;
				tvi.mask = TVIF_TEXT;
				TreeView_GetItem(pwbo->hwnd, &tvi);
				return (tvi.pszText && *tvi.pszText);
			}

		default:

			GetWindowText(pwbo->hwnd, pszText, nMaxChars);
			return TRUE;
	}
}

BOOL wbSetEnabled(PWBOBJ pwbo, BOOL bState)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	if(pwbo->uClass == Menu && IsMenu((HMENU)pwbo->hwnd)) {		// Is it a menu item?

		MENUITEMINFO mi;
		BOOL bRet;

		mi.cbSize = sizeof(MENUITEMINFO);
		mi.fMask = MIIM_STATE;
		mi.fState = bState ? MFS_ENABLED : (MFS_DISABLED | MFS_GRAYED);

		bRet = SetMenuItemInfo((HMENU)pwbo->hwnd, pwbo->id, FALSE, &mi);
		if(!bRet)
			wbError(__FUNCTION__, MB_ICONWARNING, "Could not set state of menu item #%d", pwbo->id);
		return bRet;

	} else if(IsWindow(pwbo->hwnd)) {		// Is it a window?

		switch(pwbo->uClass) {

			case ToolBar:

				return SendMessage((HWND)pwbo->hwnd, TB_ENABLEBUTTON, pwbo->id, MAKELONG(bState, 0));

			default:
				EnableWindow(pwbo->hwnd, bState ? 1 : 0);
				return TRUE;
		}
	} else
		return FALSE;
}

BOOL wbGetEnabled(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	if(pwbo->uClass == Menu && IsMenu((HMENU)pwbo->hwnd)) {		// Is it a menu item?
//	if(IsMenu((HMENU)pwbo->hwnd)) {		// Is it a menu item?

		MENUITEMINFO mi;

		mi.cbSize = sizeof(MENUITEMINFO);
		mi.fMask = MIIM_STATE;

		if(!GetMenuItemInfo((HMENU)pwbo->hwnd, pwbo->id, FALSE, &mi)) {
			wbError(__FUNCTION__, MB_ICONWARNING, "Could not get state of menu item #%d.", pwbo->id);
			return FALSE;
		}
		return (mi.fState & (MFS_DISABLED | MFS_GRAYED) ? FALSE : TRUE);

	} else if(IsWindow(pwbo->hwnd)) {		// Is it a window?

		switch(pwbo->uClass) {
			case ToolBar:								// Toolbar
				return SendMessage(pwbo->hwnd, TB_ISBUTTONENABLED, pwbo->id, 0);
			default:
				return IsWindowEnabled(pwbo->hwnd);	// The window
		}
	} else
		return FALSE;
}

DWORD wbGetSelected(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case ComboBox:

			// lparam < 0 means the child edit control was modified

			if(pwbo->lparam < 0)
				return -1;
			else
				return SendMessage(pwbo->hwnd, CB_GETCURSEL, 0, 0);

		case ListBox:

			return SendMessage(pwbo->hwnd, LB_GETCURSEL, 0, 0);

		case TabControl:

			return SendMessage(pwbo->hwnd, TCM_GETCURSEL, 0, 0);

		case CheckBox:
		case RadioButton:

			// 0 means unchecked, 1 means checked.

			return (SendMessage(pwbo->hwnd, BM_GETCHECK, 0, 0) == BST_CHECKED);

		case EditBox:
		case HyperLink:
		case ImageButton:
		case Label:
		case Menu:
		case PushButton:
		case RTFEditBox:
		case Slider:
		case Spinner:
			return 0;

		default:
			return 0;
	}
}

DWORD wbGetItemCount(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case ListView:
			return SendMessage(pwbo->hwnd, LVM_GETITEMCOUNT, 0, 0);

		case ListBox:
			return SendMessage(pwbo->hwnd, LB_GETCOUNT, 0, 0);

		case ComboBox:
			return SendMessage(pwbo->hwnd, CB_GETCOUNT, 0, 0);

		default:
			return 0;
	}
}

BOOL wbDeleteItems(PWBOBJ pwbo, BOOL bClearAll)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case ListBox:
			if(!bClearAll)
				SendMessage(pwbo->hwnd, LB_DELETESTRING, pwbo->item, 0);
			else
				SendMessage(pwbo->hwnd, LB_RESETCONTENT, 0, 0);
			break;

		case ComboBox:
			if(!bClearAll)
				SendMessage(pwbo->hwnd, CB_DELETESTRING, pwbo->item, 0);
			else
				SendMessage(pwbo->hwnd, CB_RESETCONTENT, 0, 0);
			break;

		case ListView:
			if(!bClearAll)
				return ListView_DeleteItem(pwbo->hwnd, pwbo->item);
			else
				return SendMessage(pwbo->hwnd, LVM_DELETEALLITEMS, 0, 0);
			break;

		case TreeView:

			if(!bClearAll) {
				if(pwbo->item)
					return SendMessage(pwbo->hwnd, TVM_DELETEITEM, 0, (LPARAM)(HTREEITEM)pwbo->item);
			} else {
				PTREEDATA ptrdt	= (PTREEDATA)pwbo->lparam;
				int i;

				// Clear the treeview data

				ptrdt = wbMalloc(sizeof(TREEDATA));

				ptrdt->hLast = TVI_ROOT;
				for(i = 0; i < MAX_TREEVIEW_LEVELS; i++) {
					ptrdt->hParent[i] = TVI_ROOT;
					ptrdt->bCustomImages[i] = FALSE;
				}
				ptrdt->nLastLevel = 0;
				pwbo->lparam = (LPARAM)ptrdt;
			}
			return TreeView_DeleteAllItems(pwbo->hwnd);
	}
	return TRUE;
}

BOOL wbGetVisible(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	return IsWindowVisible(pwbo->hwnd);
}

BOOL wbSetVisible(PWBOBJ pwbo, BOOL bState)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	//ShowWindow(pwbo->hwnd, bState ? SW_SHOW : SW_HIDE);
	SetWindowPos(pwbo->hwnd, 0, 0, 0, 0, 0, (bState ? SWP_SHOWWINDOW : SWP_HIDEWINDOW) | SWP_NOSIZE | SWP_NOMOVE | SWP_NOZORDER);
	return TRUE;
}

PWBOBJ wbGetFocus(void)
{
	return wbGetWBObj(GetFocus());
}

BOOL wbSetFocus(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case EditBox:
			SendMessage(pwbo->hwnd, EM_SETSEL, 0, -1);	// Select all
			break;
	}

	return (SetFocus(pwbo->hwnd) != NULL);
}

// Sets the styles of some controls

BOOL wbSetStyle(PWBOBJ pwbo, DWORD dwWBStyle, BOOL bSet)
{
	switch(pwbo->uClass) {

		case AppWindow:
		case ResizableWindow:
		case PopupWindow:
		case NakedWindow:

			if(bSet) {
				if(BITTEST(dwWBStyle, WBC_TOP))
					SetWindowPos(pwbo->hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			} else {
				if(BITTEST(dwWBStyle, WBC_TOP))
					SetWindowPos(pwbo->hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
			}
			break;

		case ListView:

			if(bSet) {
				if(BITTEST(dwWBStyle, WBC_LINES))
					SendMessage(pwbo->hwnd, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_GRIDLINES, LVS_EX_GRIDLINES);
				if(BITTEST(dwWBStyle, WBC_CHECKBOXES))
					SendMessage(pwbo->hwnd, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_CHECKBOXES, LVS_EX_CHECKBOXES);

			} else {
				if(BITTEST(dwWBStyle, WBC_LINES))
					SendMessage(pwbo->hwnd, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_GRIDLINES, 0);
				if(BITTEST(dwWBStyle, WBC_CHECKBOXES))
					SendMessage(pwbo->hwnd, LVM_SETEXTENDEDLISTVIEWSTYLE, LVS_EX_CHECKBOXES, 0);
			}
			break;

		case TreeView:

			if(bSet) {
				if(BITTEST(dwWBStyle, WBC_LINES))
					SetWindowLong(pwbo->hwnd, GWL_STYLE, GetWindowLong(pwbo->hwnd, GWL_STYLE) | (TVS_HASLINES));
			} else {
				if(BITTEST(dwWBStyle, WBC_LINES)) {
					SetWindowLong(pwbo->hwnd, GWL_STYLE, GetWindowLong(pwbo->hwnd, GWL_STYLE) & ~(TVS_HASLINES));
				}
			}
			break;

		case Slider:

			if(bSet) {
				if(BITTEST(dwWBStyle, WBC_LINES))
					SendMessage(pwbo->hwnd, TBM_SETTICFREQ, 10, 1);
			} else {
				if(BITTEST(dwWBStyle, WBC_LINES)) {
					SendMessage(pwbo->hwnd, TBM_CLEARTICS, 1, 0);
				}
			}
			break;

		default:
			return FALSE;
	}
	return TRUE;
}

BOOL wbSetValue(PWBOBJ pwbo, DWORD dwValue)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		case ListBox:
			if(pwbo->item < 0)
				pwbo->item = SendMessage(pwbo->hwnd, LB_GETCURSEL, 0, 0);
			return SendMessage(pwbo->hwnd, LB_SETITEMDATA, pwbo->item, dwValue);

		case ComboBox:
			if(pwbo->item < 0)
				pwbo->item = SendMessage(pwbo->hwnd, LB_GETCURSEL, 0, 0);
			return SendMessage(pwbo->hwnd, CB_SETITEMDATA, pwbo->item, dwValue);

		case Slider:
			return SendMessage(pwbo->hwnd, TBM_SETPOS, TRUE, dwValue);

		case Gauge:
			return SendMessage(pwbo->hwnd, PBM_SETPOS, (WPARAM)dwValue, 0);

		case Spinner:
			return SendMessage(pwbo->hwnd, UDM_SETPOS, 0, MAKELONG((short)dwValue, 0));

		case ScrollBar:
			return SendMessage(pwbo->hwnd, SBM_SETPOS, (WPARAM)dwValue, TRUE);

		case Calendar:
			return SetCalendarTime(pwbo, dwValue);

		// Set value as text

		case EditBox:
		case RTFEditBox:
		case Label:
			{
				char szText[32];

				itoa(dwValue, szText, 10);
				return SetWindowText(pwbo->hwnd, szText);
			}

		// Check / uncheck button

		case PushButton:
		case ImageButton:
		case CheckBox:
		case RadioButton:
			return SendMessage(pwbo->hwnd, BM_SETCHECK, dwValue, 0);

		// Check/uncheck menu item

		case Menu:
			return wbSetMenuItemChecked(pwbo, dwValue);
	}

	return TRUE;
}

BOOL wbSetRange(PWBOBJ pwbo, LONG lMin, LONG lMax)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	switch(pwbo->uClass) {

		// Set range

		case Slider:
			SendMessage(pwbo->hwnd, TBM_SETRANGEMIN, FALSE, lMin);
			return SendMessage(pwbo->hwnd, TBM_SETRANGEMAX, FALSE, lMax);

		case Gauge:
			return SendMessage(pwbo->hwnd, PBM_SETRANGE32, lMin, lMax);

		case Spinner:		// Inverted so that the control increases upwards
			return SendMessage(pwbo->hwnd, UDM_SETRANGE32, lMin, lMax);

		case ScrollBar:
			return SendMessage(pwbo->hwnd, SBM_SETRANGE, lMin, lMax);
	}

	return TRUE;
}

DWORD wbGetValue(PWBOBJ pwbo)
{
	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return 0;

	switch(pwbo->uClass) {

		case Calendar:
			return GetCalendarTime(pwbo);

		case ListBox:
			if(pwbo->item < 0)
				pwbo->item = SendMessage(pwbo->hwnd, LB_GETCURSEL, 0, 0);
			return SendMessage(pwbo->hwnd, LB_GETITEMDATA, pwbo->item, 0);

		case ComboBox:
			if(pwbo->item < 0)
				pwbo->item = SendMessage(pwbo->hwnd, CB_GETCURSEL, 0, 0);

			// lparam < 0 means the child edit control was modified
			if(pwbo->lparam < 0)
				return -1;
			else
				return SendMessage(pwbo->hwnd, CB_GETITEMDATA, pwbo->item, 0);

		case EditBox:
		case ImageButton:
		case Label:
		case PushButton:
		case RTFEditBox:

			{
				char szText[65];

				wbGetText(pwbo, szText, 64);
				return atoi(szText);
			}

		case Slider:

			return SendMessage(pwbo->hwnd, TBM_GETPOS, 0, 0);

		case Spinner:

			return LOWORD(SendMessage(pwbo->hwnd, UDM_GETPOS, 0, 0));

		case ScrollBar:

			return SendMessage(pwbo->hwnd, SBM_GETPOS, 0, 0);

		case CheckBox:
		case RadioButton:

			// 0 means unchecked, 1 means checked.

			return (SendMessage(pwbo->hwnd, BM_GETCHECK, 0, 0) == BST_CHECKED);

		case TreeView:

			{
	    		TV_ITEM tvi;

				tvi.hItem = TreeView_GetSelection(pwbo->hwnd);
				return wbGetTreeViewItemValue(pwbo, tvi.hItem);

/*				if(!tvi.hItem)
					return 0;
				else {
					tvi.mask = TVIF_PARAM;
					TreeView_GetItem(pwbo->hwnd, &tvi);
					return tvi.lParam;
				}*/
			}

		case ListView:
			return wbGetListViewItemChecked(pwbo, pwbo->item);

		case Menu:
			return wbGetMenuItemChecked(pwbo);

		default:
			return 0;
	}
}

BOOL wbSetImage(PWBOBJ pwbo, HANDLE hImage, COLORREF clTransp, LPARAM lParam)
{
	BOOL bRet = TRUE;
	LONG lStyle;

	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	if(!hImage)
		return FALSE;

	switch(pwbo->uClass) {

		case Menu:
			wbSetMenuItemImage(pwbo, hImage);
			break;

		case PushButton:

			lStyle = GetWindowLong(pwbo->hwnd, GWL_STYLE) & ~(BS_ICON | BS_BITMAP);
			bRet = TRUE;
			if(IsIcon(hImage)) {
				SetWindowLong(pwbo->hwnd, GWL_STYLE, lStyle | BS_ICON);
				SendMessage(pwbo->hwnd, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hImage);
				break;
			} else if(IsBitmap(hImage)) {
				SetWindowLong(pwbo->hwnd, GWL_STYLE, lStyle | BS_BITMAP);
				bRet = SetTransparentBitmap(pwbo->hwnd, (HBITMAP)hImage, FALSE, clTransp);
				break;
			} else
				bRet = FALSE;
			break;

		case ImageButton:

			if(IsBitmap(hImage)) {

				HIMAGELIST hi;
				BITMAP bm;

				GetObject(hImage, sizeof(BITMAP), (LPSTR) &bm);
				if((bm.bmWidth == 0) | (bm.bmHeight == 0))
					return FALSE;

				hi = ImageList_Create(bm.bmWidth / 4, bm.bmHeight, ILC_COLORDDB, 4, 0);
				ImageList_Add(hi, hImage, NULL);
				pwbo->lparam = (LPARAM)hi;
				break;
			} else
				bRet = FALSE;
			break;

		case Frame:

			lStyle = GetWindowLong(pwbo->hwnd, GWL_STYLE) & ~(SS_ICON | SS_BITMAP);
			bRet = TRUE;
			if(IsIcon(hImage)) {
				SetWindowLong(pwbo->hwnd, GWL_STYLE, lStyle | SS_ICON);
				SendMessage(pwbo->hwnd, STM_SETIMAGE, IMAGE_ICON, (LPARAM)hImage);
				InvalidateRect(pwbo->hwnd, NULL, FALSE);
				break;
			} else if(IsBitmap(hImage)) {
				SetWindowLong(pwbo->hwnd, GWL_STYLE, lStyle | SS_BITMAP);
				SetTransparentBitmap(pwbo->hwnd, (HBITMAP)hImage, TRUE, clTransp);
				InvalidateRect(pwbo->hwnd, NULL, FALSE);
				break;
			} else
				bRet = FALSE;
			break;

		case ListView:

			lParam = MAX(1, lParam);	// Image count
			bRet = wbCreateListViewImageList(pwbo, hImage, lParam, clTransp);
			break;

		case TreeView:

			lParam = MAX(1, lParam);	// Image count
			bRet = wbCreateTreeViewImageList(pwbo, hImage, lParam, clTransp);
			break;

		default:

			// Set the window icon

			SendMessage(pwbo->hwnd, WM_SETICON, ICON_BIG, (WPARAM)hImage);
			bRet = TRUE;

			// Change the icon in the taskbar if it is the case

			if((pwbo->style & WBC_TASKBAR) && IsIconic(pwbo->hwnd))
				bRet = SetTaskBarIcon(pwbo->hwnd, TRUE);

	} // end switch
	return bRet;
}

BOOL wbCreateItem(PWBOBJ pwbo, LPCTSTR pszItemText)
{
	LRESULT lRet;

	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	if(!pszItemText || !*pszItemText)
		return FALSE;

	switch(pwbo->uClass) {

		case ListBox:
			lRet = SendMessage(pwbo->hwnd, LB_ADDSTRING, 0, (LPARAM)pszItemText);
			return ((lRet != LB_ERR) && (lRet != LB_ERRSPACE));

		case ComboBox:

			lRet = SendMessage(pwbo->hwnd, CB_ADDSTRING, 0, (LPARAM)pszItemText);
			if(lRet == CB_ERR || lRet == CB_ERRSPACE)
				return FALSE;
			lRet = SendMessage(pwbo->hwnd, CB_SETCURSEL, 0, 0);
			return (lRet != CB_ERR);

		case TabControl:
			return wbCreateTabItem(pwbo, pszItemText);

		default:
			return FALSE;
	}
}

/* Refresh a window or control. */

BOOL wbRefreshControl(PWBOBJ pwbo, int xpos, int ypos, int nWidth, int nHeight, BOOL bNow)
{
	BOOL bRet;
	RECT rc;

	if(!wbIsWBObj(pwbo, TRUE))					// Is it a valid control?
		return FALSE;

	if(!IsWindow(pwbo->hwnd))
		return FALSE;

	if(!((pwbo->style & WBC_NOTIFY) && (pwbo->lparam & WBC_REDRAW) && pwbo->pszCallBackFn && *pwbo->pszCallBackFn)) {

		// Not custom drawn

		if(nWidth <= 0 || nHeight <= 0) {
			bRet = InvalidateRect(pwbo->hwnd, NULL, TRUE);	// Whole control
		} else {
			rc.left = xpos;
			rc.top = ypos;
			rc.right = xpos + nWidth;
			rc.bottom = ypos + nHeight;
			bRet = InvalidateRect(pwbo->hwnd, &rc, TRUE);
		}

		// Force an immediate update

		if(bNow) {
			bRet = UpdateWindow(pwbo->hwnd);
		}

	} else {

		// Custom drawn

		if(nWidth <= 0 || nHeight <= 0) {

			// We use the callback function to let the user do the drawing

			// *** Should probably use pwbo->parent for child controls, but the
			// *** use of parameter pwboParent in wbCallUserFunction() is not clear
			wbCallUserFunction(pwbo->pszCallBackFn, pwbo, pwbo,
				IDDEFAULT, WBC_REDRAW, (LPARAM)pwbo->pbuffer, 0);

			bRet = InvalidateRect(pwbo->hwnd, NULL, TRUE);

			// Force an immediate update

			if(bNow) {
				bRet = UpdateWindow(pwbo->hwnd);
			}

		} else {

			rc.left = xpos;
			rc.top = ypos;
			rc.right = xpos + nWidth;
			rc.bottom = ypos + nHeight;

			// We use the callback function to let the user do the drawing

			// *** Should probably use pwbo->parent for child controls, but the
			// *** use of parameter pwboParent in wbCallUserFunction() is not clear
			wbCallUserFunction(pwbo->pszCallBackFn, pwbo, pwbo,
				IDDEFAULT, WBC_REDRAW, (LPARAM)pwbo->pbuffer,
				(LPARAM)&rc);

			bRet = InvalidateRect(pwbo->hwnd, &rc, TRUE);

			// Force an immediate update

			if(bNow) {
				bRet = UpdateWindow(pwbo->hwnd);
			}
		}
	}
	return bRet;
}

//------------------------------------------- FUNCTIONS PUBLIC TO WINBINDER ONLY

BOOL IsIcon(HANDLE handle)
{
	ICONINFO ii;

	return GetIconInfo((HICON)handle, &ii);
}

BOOL IsBitmap(HANDLE handle)
{
	SIZE siz;

	return GetBitmapDimensionEx(handle, &siz);
}

//------------------------------------------------------------ PRIVATE FUNCTIONS

/*

For opaque bitmaps, set clTransp to CLR_INVALID

*/

static BOOL SetTransparentBitmap(HWND hwnd, HBITMAP hbmBits, BOOL bStatic, COLORREF clTransp)
{
//	static HBITMAP hbm = NULL, hbmMask;
	HBITMAP hbm, hbmMask, hbmOld;
	HDC hdc;
	RECT rc;
	HBRUSH hbr;
	BITMAP bm;

//	if(clTransp == CLR_INVALID) {
//		SendMessage(hwnd, bStatic ? STM_SETIMAGE : BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbmBits);
//		return TRUE;
//	}

	// Create an empty bitmap the same size as hwnd

	GetClientRect(hwnd, &rc);

	hbm = wbCreateBitmap(rc.right - rc.left, rc.bottom - rc.top, NULL, NULL);
	hdc = wbCreateBitmapDC(hbm);

	// Paint hbmBits with a mask

	if(clTransp != CLR_INVALID)
		hbmMask = wbCreateMask(hbmBits, clTransp);
	hbr = CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
	SelectObject(hdc, hbr);
	SelectObject(hdc, GetStockObject(WHITE_PEN));
	Rectangle(hdc, 0, 0, rc.right - rc.left, rc.bottom - rc.top);
	GetObject(hbmBits, sizeof(BITMAP), (LPVOID)&bm);
	if(clTransp == CLR_INVALID) {
		wbCopyPartialBits(hdc, hbmBits,
			((rc.right - rc.left) - bm.bmWidth) / 2,
			((rc.bottom - rc.top) - bm.bmHeight) / 2,
			rc.right - rc.left, rc.bottom - rc.top, 0, 0);
	} else {
		wbMaskPartialBits(hdc, hbmBits, hbmMask,
			((rc.right - rc.left) - bm.bmWidth) / 2,
			((rc.bottom - rc.top) - bm.bmHeight) / 2,
			rc.right - rc.left, rc.bottom - rc.top, 0, 0);
	}

	// Deletes old handle, if any

	hbmOld = (HBITMAP)SendMessage(hwnd, bStatic ? STM_SETIMAGE : BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hbm);
	if(hbmOld)
		DeleteObject(hbmOld);

	// Cleanup

	DeleteObject(hbr);
//	if(hbmMask && (clTransp != CLR_INVALID))
	if(hbmMask)
		DeleteObject(hbmMask);
	DeleteDC(hdc);

	return TRUE;
}

/*

// Trying to custom draw a Frame to avoid paint problems, but nah

static BOOL DrawFrame(HDC hdc, HWND hwnd, LPRECT lprc)
{
	char szString[256];
	int nLen;
	COLORREF clOld;
	HFONT hFont, hfOld;
	HBRUSH hbr, hbrOld;
	BOOL bRet;
	COLORREF color = 0x004000;

	GetWindowText(hwnd, szString, 255);
	nLen = strlen(szString);

	// Draw a background rectangle

	hbr = CreateSolidBrush(GetSysColor(COLOR_BTNFACE));
	hbrOld = SelectObject(hdc, hbr);
	Rectangle(hdc, lprc->left, lprc->top, lprc->right, lprc->bottom);
	SelectObject(hdc, hbrOld);
	DeleteObject(hbr);

	DrawEdge(hdc, lprc, EDGE_ETCHED, BF_RECT);

	// Prepare to draw text

	hFont = (HFONT)SendMessage(hwnd, WM_GETFONT, 0, 0);
	clOld = SetTextColor(hdc, color);
	SetBkMode(hdc, TRANSPARENT);
	hfOld = SelectObject(hdc, hFont);

	// Draw the text

	if(nLen)
		bRet = DrawTextEx(hdc, (PSZ)szString, nLen, lprc, DT_LEFT | DT_SINGLELINE, NULL);

	// Draw a line under the text
	{
		SIZE siz;

		if(GetTextExtentPoint32(hdc, (PSZ)szString, nLen, &siz)) {
			wbDrawLine(hdc, lprc->left, lprc->top + siz.cy - 1,
			  lprc->left + siz.cx, lprc->top + siz.cy - 1, color, 0);
		}
	}

	// Restore the original context

	SelectObject(hdc, hfOld);
	SetBkMode(hdc, OPAQUE);
	SetTextColor(hdc, clOld);

	return bRet;
}
*/

// Processing routine for Frame controls

static LRESULT CALLBACK FrameProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg) {

/*		case WM_PAINT:
			{
				HDC hdc;
				PAINTSTRUCT ps;

				PWBOBJ pwbobj = wbGetWBObj(hwnd);

				if(!pwbobj)
					break;
				hdc = BeginPaint(hwnd, &ps);
				DrawFrame(hdc, hwnd, &ps.rcPaint);
				EndPaint(hwnd, &ps);
			}
			return 0;*/

		case WM_COMMAND:		// Passes commands to parent window
		case WM_NOTIFY:
			{
				HWND hwndParent = GetParent(hwnd);

				if(hwndParent)
					SendMessage(hwndParent, msg, wParam, lParam);
			}
			break;
	}
	return CallWindowProc(lpfnFrameProcOld, hwnd, msg, wParam, lParam);
}

// Processing routine for Edit controls

static LRESULT CALLBACK EditProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg) {

		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
			{
				HWND hwndParent = GetParent(hwnd);

				if(hwndParent)
					SendMessage(hwndParent, WBWM_KEYDOWN, (WPARAM)hwnd, (LPARAM)wParam);
			}
			break;

		case WM_KEYUP:
		case WM_SYSKEYUP:
			{
				HWND hwndParent = GetParent(hwnd);

				if(hwndParent)
					SendMessage(hwndParent, WBWM_KEYUP, (WPARAM)hwnd, (LPARAM)wParam);
			}
			break;
	}
	return CallWindowProc(lpfnEditProcOld, hwnd, msg, wParam, lParam);
}

// Processing routine for InvisibleAreas

static LRESULT CALLBACK InvisibleProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg) {

		case WM_MOUSEMOVE:
			{
				PWBOBJ pwbobj = wbGetWBObj(hwnd);

				if(!pwbobj)
					break;

				if(BITTEST(pwbobj->style, WBC_NOTIFY) &&
					BITTEST(pwbobj->lparam, WBC_MOUSEMOVE)) {

					DWORD dwAlt = (GetKeyState(VK_MENU) < 0) ? WBC_ALT : 0;

					if(pwbobj && pwbobj->parent && pwbobj->parent->pszCallBackFn && *pwbobj->parent->pszCallBackFn) {
//printf("%08X %s\n", pwbobj->lparam, pwbobj->parent->pszCallBackFn);
						wbCallUserFunction(pwbobj->parent->pszCallBackFn, pwbobj->parent, pwbobj, pwbobj->id,
						WBC_MOUSEMOVE | wParam | dwAlt, lParam, 0);
					}
				}
			}
			break;
	}
	return CallWindowProc(lpfnInvisibleProcOld, hwnd, msg, wParam, lParam);
}

static HWND CreateToolTip(PWBOBJ pwbo)
{
	HWND hwndTT;
	TOOLINFO ti;

	// Create the ToolTip control.

	hwndTT = CreateWindow(TOOLTIPS_CLASS, NULL,
		TTS_ALWAYSTIP,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		pwbo->hwnd,
		NULL, NULL, NULL);

	// Create a tool that contains the desired control (pwbo->hwnd)

	ti.cbSize = sizeof(TOOLINFO);
	ti.uFlags = TTF_SUBCLASS;
	ti.hwnd	= pwbo->hwnd;
	ti.uId	= 0;
	ti.hinst = NULL;

	// Get the window text

	ti.lpszText	= wbMalloc(256);
	GetWindowText(pwbo->hwnd, ti.lpszText, 255);

	// It's not completely clear on the doc: Must have the line below, otherwise the tooltip won't appear.
	// The MSDN doc, in the "Messaging and Notification" topic, gets close:
	// http://msdn.microsoft.com/library/default.asp?url=/library/en-us/shellcc/platform/commctls/tooltip/tooltip.asp
	// It says "The tool is a control or is defined as a rectangle in the tool's TOOLINFO structure."
	// I add: "For controls, the rect member of the TOOLINFO structure must be set to the size of the client area."

	GetClientRect(pwbo->hwnd, &ti.rect);

	// Add the tool to the control

	if(!SendMessage(hwndTT, TTM_ADDTOOL, 0, (LPARAM)&ti))
		return NULL;

	return hwndTT;
}

//------------------------------------------------------------------ END OF FILE
