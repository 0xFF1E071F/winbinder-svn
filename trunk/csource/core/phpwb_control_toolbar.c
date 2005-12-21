/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 ZEND wrapper for toolbar control

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"

//----------------------------------------------------------- EXPORTED FUNCTIONS

ZEND_FUNCTION(wbtemp_create_toolbar)
{
	int i, nelem, s_len = 0;
	zval *zarray, **entry;
	HashTable *target_hash;
	HANDLE hImage;
	LONG l;
	long pwboParent, width = 0, height = 0;
	char *s = "";
	PWBITEM *pitem;

	// Get function parameters

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	 "lz!|lls", &pwboParent, &zarray, &width, &height, &s, &s_len) == FAILURE)
		return;

	if(!wbIsWBObj((void *)pwboParent, TRUE))
		RETURN_NULL()

	if(zarray->type == IS_ARRAY) {

		target_hash = HASH_OF(zarray);
		if(!target_hash)
			RETURN_NULL();

		nelem = zend_hash_num_elements(target_hash);
		zend_hash_internal_pointer_reset(target_hash);

		// Allocate memory for toolbar pointers

		pitem = emalloc(nelem * sizeof(PWBITEM));

		// Loop to read array items

		for(i = 0; i < nelem; i++) {

			if(zend_hash_get_current_data(target_hash, (void **) &entry) == FAILURE) {
				zend_error(E_WARNING, "Could not retrieve element %d from array in function %s()",
				  i, get_active_function_name(TSRMLS_C));
				efree(pitem);
				RETURN_NULL();
			}

			// Allocate memory for item description

			pitem[i] = emalloc(sizeof(WBITEM));

			switch(Z_TYPE_PP(entry)) {

				case IS_ARRAY:				// Toolbar button
					parse_array(*entry, "lssl", &pitem[i]->id, &pitem[i]->pszCaption, &pitem[i]->pszHint, &pitem[i]->index);
					break;

				case IS_NULL:				// Separator
					pitem[i] = NULL;
					break;

				default:
					zend_error(E_WARNING, "Invalid element type in array: must be an array or null in function %s()",
					  get_active_function_name(TSRMLS_C));
					efree(pitem);
					RETURN_NULL();
			}

			if(i < nelem - 1)
				zend_hash_move_forward(target_hash);
		}

		hImage = wbLoadImage(s, 0, 0);

		if(!hImage) {
			zend_error(E_WARNING, "%s is an invalid image file or has an unrecognizable format in function %s()",
			  s, get_active_function_name(TSRMLS_C));
		}

	} else {
		nelem = 0;
		pitem = NULL;
	}

	// Create toolbar and attach it to window

	l = (LONG)wbCreateToolbar((PWBOBJ)pwboParent, pitem, nelem, width, height, hImage);

	if(pitem)
		efree(pitem);

	RETURN_LONG(l);
}

//------------------------------------------------------------------ END OF FILE
