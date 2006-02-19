/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 ZEND wrapper for bitmap functions

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"

//----------------------------------------------------------- EXPORTED FUNCTIONS

/*
 index is the index of the image on the file if filename is an icon library. Default is 0.
*/

/*ZEND_FUNCTION(wb_load_image)
{
	char *s;
	int s_len;
	long index;
	HANDLE hImage;

	// Default parameter values

	index = 0;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "s|l", &s, &s_len, &index) == FAILURE)
		return;

	hImage = wbLoadImage(s, index);
	if(!hImage) {
		RETURN_NULL();
	} else
		RETURN_LONG((long)hImage);
}*/

ZEND_FUNCTION(wb_load_image)
{
	char *s;
	int s_len;
	long index;
	BOOL param;
	HANDLE hImage;

	// Default parameter values

	index = 0;
	param = FALSE;

	 if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "s|ll", &s, &s_len, &index, &param) == FAILURE)
		return;

	hImage = wbLoadImage(s, index, param);
	if(!hImage) {
		RETURN_NULL();
	} else
		RETURN_LONG((long)hImage);
}


ZEND_FUNCTION(wb_save_image)
{
	long hbm;
	char *s;
	int s_len;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "ls", &hbm, &s, &s_len) == FAILURE)
		RETURN_BOOL(FALSE);

	if(!hbm)
		RETURN_NULL();

	RETURN_BOOL(wbSaveBitmap((HBITMAP)hbm, s));
}

ZEND_FUNCTION(wb_create_image)
{
    long w, h, bmi = 0, bits = 0;
    int nargs;

	nargs = ZEND_NUM_ARGS();

    if(zend_parse_parameters(nargs TSRMLS_CC,
	  "ll|ll", &w, &h, &bmi, &bits) == FAILURE)
		return;

	if(nargs == 3) {
		zend_error(E_WARNING, "Invalid parameter type passed to function %s()",
		  get_active_function_name(TSRMLS_C));
		RETURN_LONG(0);
	}

	RETURN_LONG((LONG)wbCreateBitmap(w, h, (BITMAPINFO *)bmi, (void *)bits))
}

ZEND_FUNCTION(wb_get_image_data)
{
    long hbm;
    BYTE *lpBits = NULL;
    DWORD size;
    BOOL compress4to3 = FALSE;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "l|l", &hbm, &compress4to3) == FAILURE)
		return;

	size = wbGetBitmapBits((HBITMAP)hbm, &lpBits, compress4to3);

	if(!size || !lpBits)
		RETURN_NULL();

	RETVAL_STRINGL(lpBits, size, TRUE);
	efree(lpBits);
}

// TODO: perform a non-destructive masking

ZEND_FUNCTION(wb_create_mask)
{
    long hbm, c;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "ll", &hbm, &c) == FAILURE)
		return;

	if(!hbm)
		RETURN_NULL();

	RETURN_LONG((LONG)wbCreateMask((HBITMAP)hbm, c))
}

ZEND_FUNCTION(wb_destroy_image)
{
    long hbm;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "l", &hbm) == FAILURE)
		return;

	if(!hbm)
		RETURN_NULL();

	RETURN_BOOL(wbDestroyBitmap((HBITMAP)hbm))
}

//------------------------------------------------------------------ END OF FILE
