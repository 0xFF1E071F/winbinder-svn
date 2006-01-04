/*******************************************************************************

 WINBINDER - A native Windows binding

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 General-purpose functions

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "wb.h"

//----------------------------------------------------------- EXPORTED FUNCTIONS

BOOL wbIsWBObj(void *pwbo, BOOL bShowErrors)
{
	if(!pwbo) {
		if(bShowErrors)
			wbError(__FUNCTION__, MB_ICONWARNING, "NULL WinBinder object");
		return FALSE;
	}

	// Is pwbo a valid memory address?

	if(IsBadReadPtr(pwbo, sizeof(WBOBJ))) {
		if(bShowErrors)
			wbError(__FUNCTION__, MB_ICONWARNING, "Invalid memory address");
//		printf("%d\n", pwbo);
		return FALSE;
	}

	// A Windows or menu handle is not a WinBinder object

	if(IsWindow(pwbo) || IsMenu(pwbo)) {
		if(bShowErrors)
			wbError(__FUNCTION__, MB_ICONWARNING, "Not a WinBinder object");
		return FALSE;
	}

	// Does it have a valid handle?

	{
		PWBOBJ pwboTest = wbMalloc(sizeof(WBOBJ));
		if(pwboTest) {
			CopyMemory(pwboTest, pwbo, sizeof(WBOBJ));

			if(!pwboTest->hwnd) {
				wbFree(pwboTest);
				if(bShowErrors)
					wbError(__FUNCTION__, MB_ICONWARNING, "NULL WinBinder object handle");
				return FALSE;
			}
			wbFree(pwboTest);
		}
	}

	if(IsMenu((HMENU)((PWBOBJ)pwbo)->hwnd))
		return TRUE;

	if(IsWindow((HWND)((PWBOBJ)pwbo)->hwnd))
		return TRUE;

	if(bShowErrors)
		wbError(__FUNCTION__, MB_ICONWARNING, "Invalid WinBinder object");

	return FALSE;
}

/* TODO: Return PWBOBJ from menus */

PWBOBJ wbGetWBObj(HANDLE hwnd)
{
	if(IsWindow(hwnd)) {
		return (PWBOBJ)GetWindowLong((HWND)hwnd, GWL_USERDATA);

/*
	} else if(IsMenu(hwnd)) {

		MENUITEMINFO mi;

		GetMenuItemInfo((HMENU)hwnd, 0, TRUE, &mi);
		if(!((PWBOBJ)(mi.dwItemData)))
//			printf("MENU: NULL\n");
		else
//			printf("MENU: %d\n", ((PWBOBJ)(mi.dwItemData))->parent);
		return (PWBOBJ)(mi.dwItemData);*/

	} else
		return NULL;
}

//  Removes all trailing blanks from a string.

int wbTrimLeft(LPTSTR pszStr)
{
	int i = 0, j;

	j = strlen(pszStr) - 1;
	while (isspace(pszStr[i]) && (i <= j))
		i++;
	if(i > 0)
		strcpy(pszStr, &pszStr[i]);
	return i;
}

// Removes all leading blanks from a string.

int wbTrimRight(LPTSTR pszStr)
{
	int i, j;

	j = i = strlen(pszStr) - 1;
	while(isspace(pszStr[i]) && (i >= 0))
		pszStr[i--] = '\0';
	return j - i;
}

// Removes all leading and trailing blanks in a string.
// Blanks are defined with ISSPACE  (blank, tab, newline, return, formfeed,
// vertical tab = 0x09 - 0x0D + 0x20)

int wbTrim(LPTSTR pszStr)
{
	int nBlank;

	nBlank = wbTrimRight(pszStr);
	nBlank += wbTrimLeft(pszStr);
	return nBlank;
}

//------------------------------------------------------------- ANSI C FUNCTIONS

#ifdef __LCC__

int isinf(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF0000000000000ll?1:u.l==0xFFF0000000000000ll?-1:0);
}

int isnan(double d) {
  union {
    unsigned long long l;
    double d;
  } u;
  u.d=d;
  return (u.l==0x7FF8000000000000ll || u.l==0x7FF0000000000000ll || u.l==0xfff8000000000000ll);
}

int _finite(double d) {
  return isinf(d)==0 && isnan(d)==0;
}

#endif	// LCC

//------------------------------------------------------------------ END OF FILE
