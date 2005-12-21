/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 General-purpose functions (not exported to the ZEND engine)

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"

//------------------------------------------------------------- GLOBAL VARIABLES

const char *pszWbobjName = "WinBinder Object";

//------------------------------------------------------------- PUBLIC FUNCTIONS

/* Accepts a limited subset of the parameters accepted by zend_parse_parameters() */

int parse_array(zval *array, const char *fmt, ...)
{
	int i, nelem;
	void *arg;
	zval **entry;
	va_list ap;
	HashTable *target_hash;
#if (PHP_MAJOR_VERSION >= 5)
	TSRMLS_FETCH();
#endif

	va_start(ap, fmt);

	target_hash = HASH_OF(array);
	if(!target_hash)
		return 0;

	nelem = zend_hash_num_elements(target_hash);
	zend_hash_internal_pointer_reset(target_hash);

	// Parse loop

	for(i = 0; i < (int)strlen(fmt); i++) {

		arg = va_arg(ap, void *);
		if(!arg)
			break;

		// Requested items past the length of the array must return NULL

		if(i >= nelem ) {

			switch(fmt[i]) {

				case 'l':
					*((long *)arg) = 0;
					break;

				case 'd':
					*((double *)arg) = 0;
					break;

				case 's':
					*((long *)arg) = (long)NULL;
					break;

				default:
					zend_error(E_WARNING, "Invalid format character '%c' in function %s()",
					  fmt[i], __FUNCTION__);
					continue;
			}
			continue;

		} else if(zend_hash_get_current_data(target_hash, (void **) &entry) == FAILURE) {

			zend_error(E_WARNING, "Could not retrieve element %d from array in function %s()",
			  i, __FUNCTION__);
			continue;

		} else {

			if(!entry || !*entry)
				break;

			switch(fmt[i]) {

				case 'l':
					if(Z_TYPE_PP(entry) == IS_NULL) {
						*((long *)arg) = (long)NULL;
					} else
						*((long *)arg) = (*entry)->value.lval;
					break;

				case 'd':
					if(Z_TYPE_PP(entry) == IS_NULL) {
						*((long *)arg) = (long)NULL;
					} else
						*((double *)arg) = (*entry)->value.dval;
					break;

				case 's':
					if(Z_TYPE_PP(entry) == IS_STRING) {
						*((long *)arg) = (long)((*entry)->value.str.val);
					} else if(Z_TYPE_PP(entry) == IS_NULL) {
						*((long *)arg) = (long)NULL;
					} else
						*((long *)arg) = (long)NULL;
					break;

				default:
					zend_error(E_WARNING, "Invalid format string '%s' in function %s()",
					  fmt, __FUNCTION__);
					continue;

			} // switch

		} // else

		if(i < nelem - 1)
			zend_hash_move_forward(target_hash);
	}

	va_end(ap);
	return nelem;
}

/* Function to process arrays. Returns a pointer to a zval element from array zitems or
  NULL if end of array is reached */

zval *process_array(zval *zitems, TSRMLS_D)
{
	static int nelem = 0;
	static int nelems = 0;
	static HashTable *target_hash = NULL;
	zval **entry = NULL;

	if(zitems->type != IS_ARRAY)
		return FALSE;

	// Prepare to read items from zitem array

	if(!nelems && !nelem) {

		target_hash = HASH_OF(zitems);
		if(!target_hash)
			return FALSE;

		nelems = zend_hash_num_elements(target_hash);

		if(!nelems) {

			// Array is empty: reset everything

			target_hash = NULL;
			nelems = 0;
			nelem = 0;
			return NULL;

		} else {

			// Start array

			zend_hash_internal_pointer_reset(target_hash);
			nelem = 0;
		}

	} else {

		if(nelem < nelems - 1) {

			zend_hash_move_forward(target_hash);
			nelem++;

		} else if(nelem == nelems - 1) {

			// End of array: reset everything

			target_hash = NULL;
			nelems = 0;
			nelem = 0;
			return NULL;
		}
	}

	// Get zval data

	if(zend_hash_get_current_data(target_hash, (void **) &entry) == FAILURE)
		zend_error(E_WARNING, "Could not retrieve element %d from array in function %s()",
		  nelem, get_active_function_name(tsrm_ls));

	return *entry;
}


//------------------------------------------------------------------ END OF FILE
