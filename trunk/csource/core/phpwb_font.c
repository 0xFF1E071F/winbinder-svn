/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 ZEND wrapper for font functions

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"

//----------------------------------------------------------- EXPORTED FUNCTIONS

// Creates a font and stores it in the font cache

ZEND_FUNCTION(wb_create_font)
{
    LONG height = 10, color = 0x000000, flags = 0;
    char *name;
    int name_len;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "sl|ll", &name, &name_len, &height, &color, &flags) == FAILURE)
		return;

	RETURN_LONG(wbCreateFont(name, height, color, flags));
}

// Destroys a font or all created fonts

ZEND_FUNCTION(wb_destroy_font)
{
    int nfont = 0;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "|l", &nfont) == FAILURE)
		return;

	RETURN_BOOL(wbDestroyFont(nfont));
}

// Applies a font to a control

ZEND_FUNCTION(wb_set_font)
{
    LONG pwbo, nfont = 0, redraw;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "l|ll", &pwbo, &nfont, &redraw) == FAILURE)
		return;

	RETURN_BOOL(wbSetControlFont((PWBOBJ)pwbo, nfont, redraw));
}

//------------------------------------------------------------------ END OF FILE
