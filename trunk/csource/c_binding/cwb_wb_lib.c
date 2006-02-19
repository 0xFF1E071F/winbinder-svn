/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Library of C functions for the WinBinder extension

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include <string.h>
#include <stdio.h>
#include <wb.h>

//-------------------------------------------------------------------- CONSTANTS

#define CALLBACK_ARGS	5	// Number of arguments of the callback function

//----------------------------------------------------------- EXPORTED FUNCTIONS

/*
	TODO: optionally use a message box to display errors and/or log errors to a file
*/

BOOL wbError(LPCTSTR szFunction, int nType, LPCTSTR pszFmt, ...)
{
	char szString[MAX_ERR_MESSAGE];
	char szAux[MAX_ERR_MESSAGE];

	// Build the string

	va_list args;
	va_start(args, pszFmt);
	vsprintf(szAux, pszFmt, args);
	va_end(args);

	// Prepend the function name

	strcpy(szString, szFunction);
	strcat(szString, ": ");
	strcat(szString, szAux);

	printf("Error: %d %s\n", nType, szString);
	return FALSE;
}

BOOL wbCallUserFunction(LPCTSTR pszFunctionName, PWBOBJ pwboParent, PWBOBJ pctrl, UINT id, LPARAM lParam1, LPARAM lParam2)
{
	return TRUE;
}

// Memory-allocation functions

void *wbMalloc(size_t size)
{
	return malloc(size);
}

void *wbCalloc(size_t nmemb, size_t size)
{
	return calloc(nmemb, size);
}

void *wbRealloc(void *ptr, size_t size)
{
	return realloc(ptr, size);
}

char *wbStrDup(const char *string)
{
	return strdup(string);
}

char *wbStrnDup(const char *string, size_t size)
{
	char *szDup = (char *)malloc(size + 1);

	if(szDup) {
		strncpy(szDup, string, size);
		szDup[size] = '\0';
	}
	return szDup;
}

BOOL wbFree(void *ptr)
{
	if(ptr)
		free(ptr);
	return TRUE;
}

//------------------------------------------------------------------ END OF FILE
