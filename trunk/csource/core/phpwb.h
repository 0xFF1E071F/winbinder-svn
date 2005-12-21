/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Common header for WinBinder for PHP

*******************************************************************************/

#ifndef _PHP_WB_H
#define _PHP_WB_H

//-------------------------------------------------------------------- CONSTANTS

// WINBINDER constants

#define APPNAME			"WinBinder-PHP"
#define MODULENAME		"winbinder"		// For phpinfo() and extension_loaded()
#define LIBVERSION		WINBINDER_VERSION

// ZEND constants

#if defined _MSC_VER		// Rick
#	if defined(ZEND_EXPORTS)
#		undef ZEND_EXPORTS
#	endif
#	undef ZEND_DEBUG
#endif

#define ZEND_DEBUG	FALSE	// Must be FALSE
#define ZTS					// Must define ZTS (Zend Thread Safety)
#define PHP_REGEX_H			// Skip php_regex.h: '_off_t' not defined anywhere

//----------------------------------------------------------------- DEPENDENCIES

#include "wb/wb.h"
#include <php.h>

//---------------------------------------------------------- AUXILIARY FUNCTIONS

int parse_array(zval *array, const char *fmt, ...);
zval *process_array(zval *zitems, TSRMLS_D);

//------------------------------------------------------------------ END OF FILE

#endif // _PHP_WB_H
