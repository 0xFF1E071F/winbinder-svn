/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 ZEND wrapper for common dialog boxes

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"
//#include <shlobj.h>
//#include <stdio.h>

//----------------------------------------------------------- EXPORTED FUNCTIONS

ZEND_FUNCTION(wbtemp_sys_dlg_open)
{
    long pwboParent;
	char *title = "", *filter = "", *path = "";
	int title_len = 0, filter_len = 0, path_len = 0;
	char szFile[MAX_PATH] = "";

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "|lsss", &pwboParent, &title, &title_len, &filter, &filter_len, &path, &path_len) == FAILURE)
		return;

	if(pwboParent && !wbIsWBObj((void *)pwboParent, TRUE))
		RETURN_NULL()

	wbSysDlgOpen((PWBOBJ)pwboParent, title, filter, path, szFile);
	if(*szFile)
		RETURN_STRINGL(szFile, strlen(szFile), TRUE)
	else
		RETURN_STRING("", TRUE)
}

ZEND_FUNCTION(wbtemp_sys_dlg_save)
{
    long pwboParent;
	char *title = "", *filter = "", *path = "", *file = "", *defext = "";
	int title_len = 0, filter_len = 0, path_len = 0, file_len = 0, defext_len = 0;
	char szFile[MAX_PATH] = "";
	char szDefExt[MAX_PATH] = "";

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "|lsssss", &pwboParent, &title, &title_len, &filter, &filter_len, &path, &path_len, &file, &file_len, &defext, &defext_len) == FAILURE)
		return;

	if(pwboParent && !wbIsWBObj((void *)pwboParent, TRUE))
		RETURN_NULL()

	if(*file)
		strcpy(szFile, file);
	if(*defext)
		strcpy(szDefExt, defext);

	wbSysDlgSave((PWBOBJ)pwboParent, title, filter, path, szFile, szDefExt);
	if(*szFile)
		RETURN_STRING(szFile, TRUE)
	else
		RETURN_STRING("", TRUE)
}

ZEND_FUNCTION(wb_sys_dlg_path)
{
    long pwboParent = (long)NULL;
	char *title = "", *path = "";
	int title_len = 0, path_len = 0;
	char szSelPath[MAX_PATH] = "";

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "|lss", &pwboParent, &title, &title_len, &path, &path_len) == FAILURE)
		return;

	if(pwboParent && !wbIsWBObj((void *)pwboParent, TRUE))
		RETURN_NULL()

	wbSysDlgPath((PWBOBJ)pwboParent, title, path, szSelPath);
	if(*szSelPath)
		RETURN_STRING(szSelPath, TRUE)
	else
		RETURN_STRING("", TRUE)
}

ZEND_FUNCTION(wb_sys_dlg_color)
{
    long pwboParent = (long)NULL;
    long color = CLR_INVALID;
	char *title = "";
	int title_len = 0;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "|lsl", &pwboParent, &title, &title_len, &color) == FAILURE)
		return;

	if(pwboParent && !wbIsWBObj((void *)pwboParent, TRUE))
		RETURN_NULL()

	RETURN_LONG(wbSysDlgColor((PWBOBJ)pwboParent, title, (COLORREF)color));
}

/*
ZEND_FUNCTION(wb_sys_dlg_font)
{
    long pwbparent = (long)NULL;
	char *title = "";
	char *name = "";
	int height = 0, color = 0, flags = 0;
	int title_len = 0, name_len = 0;
	FONT font;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "|lsslll", &pwbparent, &title, &title_len, &name, &name_len, &height, &color, &flags) == FAILURE)
		return;

	if(pwbo && !wbIsWBObj((void *)pwbo, TRUE))
		RETURN_NULL()

	font.pszName = name;
	font.nHeight = height;
	font.color = color;
	font.dwFlags = flags;
	RETURN_LONG(wbSysDlgFont((PWBOBJ)pwbparent, title, &font));
}
*/

//------------------------------------------------------------------ END OF FILE
