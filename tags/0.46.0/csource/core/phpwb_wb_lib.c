/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright � 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Library of ZEND-specific functions for the WinBinder extension

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"

//-------------------------------------------------------------------- CONSTANTS

#define CALLBACK_ARGS	6	// Number of arguments of the callback function

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

	switch(nType) {
		case MB_OK:
		case MB_ICONINFORMATION:
			nType = E_NOTICE;
			break;

		case MB_ICONWARNING:
			nType = E_WARNING;
			break;

		case MB_ICONSTOP:
		case MB_ICONQUESTION:
		default:
			nType = E_ERROR;
			break;
	}
	zend_error(nType, szString);
	return FALSE;
}

// *** The use of parameter pwboParent in wbCallUserFunction() is not clear

BOOL wbCallUserFunction(LPCTSTR pszFunctionName, PWBOBJ pwboParent, PWBOBJ pctrl, UINT id, LPARAM lParam1, LPARAM lParam2, LPARAM lParam3)
{
	zval *fname;
	zval *return_value = NULL;
	zval **parms[CALLBACK_ARGS];
	zval *z0, *z1, *z2, *z3, *z4, *z5;
	BOOL bRet;
	char *pszFName;

	TSRMLS_FETCH();

	// Is there a callback function assigned to the window?

	pszFName = (char *)pszFunctionName;
	if(!pszFName || !*pszFName) {
		char szTitle[256];

		if(GetWindowText(pwboParent->hwnd, szTitle, 256))
			zend_error(E_WARNING, "%s(): No callback function assigned to window '%s'",
			  get_active_function_name(TSRMLS_C), szTitle);
		else
			zend_error(E_WARNING, "%s(): No callback function assigned to window #%ld",
			  get_active_function_name(TSRMLS_C), (LONG)pwboParent);
		return FALSE;
	}

	MAKE_STD_ZVAL(fname);
	ZVAL_STRING(fname, pszFName, 1);

	if(!zend_is_callable(fname, 0, &pszFName)) {
		zend_error(E_WARNING, "%s(): '%s' is not a function or cannot be called",
		  get_active_function_name(TSRMLS_C), pszFName);
		efree(pszFName);				// These two lines prevent a leakage
		efree(fname->value.str.val);	// that occurred on every function call
		efree(fname);
		return FALSE;
	}

	ALLOC_INIT_ZVAL(z0);
	ZVAL_LONG(z0, (LONG)pwboParent);				// PWBOBJ pointer
	parms[0] = &z0;

	ALLOC_INIT_ZVAL(z1);							// id
	ZVAL_LONG(z1, (LONG)id);
	parms[1] = &z1;

	ALLOC_INIT_ZVAL(z2);							// control handle
	ZVAL_LONG(z2, (LONG)pctrl);
	parms[2] = &z2;

	ALLOC_INIT_ZVAL(z3);							// lparam1
	ZVAL_LONG(z3, (LONG)lParam1);
	parms[3] = &z3;

	ALLOC_INIT_ZVAL(z4);							// lparam2
	ZVAL_LONG(z4, (LONG)lParam2);
	parms[4] = &z4;

	ALLOC_INIT_ZVAL(z5);							// lparam3
	ZVAL_LONG(z5, (LONG)lParam3);
	parms[5] = &z5;

	// Call the user function

	bRet = call_user_function_ex(
		CG(function_table),			// Hash value for the function table
		NULL,						// Pointer to an object (may be NULL)
		fname,						// Function name
		&return_value,				// Return value
		CALLBACK_ARGS,				// Parameter count
		parms,						// Parameter array
		0,							// No separation flag (always 0)
		NULL TSRMLS_CC
		);

	if(bRet != SUCCESS) {
    	zend_error(E_WARNING, "%s(): User function call failed",
    	  get_active_function_name(TSRMLS_C));
	}

	// Free everything we can

	zval_ptr_dtor(&return_value);

	efree(z5);
	efree(z4);
	efree(z3);
	efree(z2);
	efree(z1);
	efree(z0);
	efree(pszFName);				// These two lines prevent a leakage
	efree(fname->value.str.val);	// that occurred on every function call
	efree(fname);

	return TRUE;
}

// Memory-allocation functions

void *wbMalloc(size_t size)
{
	return emalloc(size);
}

void *wbCalloc(size_t nmemb, size_t size)
{
	return ecalloc(nmemb, size);
}

void *wbRealloc(void *ptr, size_t size)
{
	return erealloc(ptr, size);
}

char *wbStrDup(const char *string)
{
	return estrdup(string);
}

char *wbStrnDup(const char *string, size_t size)
{
	return estrndup(string, size);
}

BOOL wbFree(void *ptr)
{
	if(ptr)
		efree(ptr);
	return TRUE;
}

//------------------------------------------------------------------ END OF FILE
