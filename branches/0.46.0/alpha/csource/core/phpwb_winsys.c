/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 ZEND wrapper for Windows system functions

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include "phpwb.h"
#include "php_ini.h"			// for cfg_get_string()

//-------------------------------------------------------------------- VARIABLES

// Private

static char szAppName[] = APPNAME;

// Public to wb_* modules

extern LPTSTR MakeWinPath(LPTSTR pszPath);

//----------------------------------------------------------- EXPORTED FUNCTIONS

// How can a function that is so important be so small?

ZEND_FUNCTION(wb_main_loop)
{
	RETURN_LONG(wbMainLoop());
}

ZEND_FUNCTION(wbtemp_set_accel_table)
{
	int i, nelem;
	zval *zarray, **entry;
	HashTable *target_hash;
	char *str_accel;
	ACCEL accel[MAX_ACCELS];
	DWORD dwacc;
	int naccel= 0;
	long pwbo;

	// Get function parameters

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	 "lz!", &pwbo, &zarray) == FAILURE)
		return;

	if(zarray->type == IS_ARRAY) {

		target_hash = HASH_OF(zarray);
		if(!target_hash)
			RETURN_NULL();

		nelem = zend_hash_num_elements(target_hash);
		zend_hash_internal_pointer_reset(target_hash);

		// Loop to read array items

		for(i = 0; i < nelem; i++) {
			if(zend_hash_get_current_data(target_hash, (void **) &entry) == FAILURE) {
				zend_error(E_WARNING, "Could not retrieve element %d from array in function %s()",
				  i, get_active_function_name(TSRMLS_C));
				RETURN_NULL();
			}

			switch(Z_TYPE_PP(entry)) {

				case IS_ARRAY:				// An accelerator item is an array inside an array
					parse_array(*entry, "ls", &accel[naccel].cmd, &str_accel);
					if(str_accel && *str_accel && naccel < MAX_ACCELS) {
						dwacc = wbMakeAccelFromString(str_accel);
						accel[naccel].key = LOWORD(dwacc);
						accel[naccel].fVirt = (BYTE)HIWORD(dwacc);
//						printf("> %d %d %d %s\n", accel[naccel].key, accel[naccel].fVirt, accel[naccel].cmd, str_accel);
						naccel++;
					}
					break;

				default:
					zend_error(E_WARNING, "%s(): Accelerator table must be an array of arrays with two elements",
					  get_active_function_name(TSRMLS_C));
					RETURN_NULL();
					break;
			}

			if(i < nelem - 1)
				zend_hash_move_forward(target_hash);
		}

		// Create accelerator table

		RETURN_BOOL(wbSetAccelerators((PWBOBJ)pwbo, accel, naccel));

	} else {
		RETURN_BOOL(wbSetAccelerators((PWBOBJ)pwbo, NULL, 0));
	}
}

// TODO: Not working?
// TODO: Play WAV, MIDI, MP3...

ZEND_FUNCTION(wb_play_sound)
{
	int style;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "l", &style) == FAILURE)
		return;

	RETURN_BOOL(wbPlaySystemSound(style));
}

/*

Return values:

IDCANCEL	FALSE
IDIGNORE	FALSE
IDABORT		FALSE
IDNO		FALSE
Others		FALSE
IDOK		TRUE
IDRETRY		TRUE
IDYES		TRUE

Error		NULL

*/

ZEND_FUNCTION(wb_message_box)
{
	char *msg, *title = NULL;
	long pwbo, style = 0;
	int msg_len, title_len = 0, ret;

	style = MB_OK;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "ls|sl", &pwbo, &msg, &msg_len, &title, &title_len, &style) == FAILURE)
		return;

	if(pwbo && !wbIsWBObj((void *)pwbo, TRUE))
		RETURN_NULL()

	if(!title || !*title) {
		title = szAppName;
		title_len = strlen(szAppName);
	}
	ret = wbMessageBox((PWBOBJ)pwbo, msg, title, style);

	if(ret < 0)
		RETURN_NULL()
	else
		RETURN_LONG(ret);
}

ZEND_FUNCTION(wb_exec)
{
	char *pgm, *parm = NULL;
	int pgm_len, parm_len = 0;
	BOOL show;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "s|sl", &pgm, &pgm_len, &parm, &parm_len, &show) == FAILURE)
		return;

	RETURN_BOOL(wbExec(pgm, parm, show));
}

// TODO: without parameters, wb_get_system_info() should return an
// associative array with all information


ZEND_FUNCTION(wb_get_system_info)
{
	char *s;
	int s_len;
	BOOL isstr;
	LONG res;
	char strval[1024];

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "s", &s, &s_len) == FAILURE)
		return;

	if(!stricmp(s, "extensionpath")) {

		// Calls Zend function cfg_get_string()

		char *value;

		if(cfg_get_string("extension_dir", &value) == FAILURE)
			RETURN_BOOL(FALSE);

		// Assemble the final string

		wbGetSystemInfo("exepath", &isstr, strval, 1023);
		strcat(strval, value);
		MakeWinPath(strval);
		isstr = TRUE;

	} else {
		// Calls the API (low-level) WinBinder layer
		res = wbGetSystemInfo(s, &isstr, strval, 1023);
	}

	if(isstr) {
		if(!*strval && (res == -1)) {		// Unrecognized parameter
			RETURN_NULL();
		} else {
			RETURN_STRING(strval, strlen(strval));
		}
	} else {
		RETURN_LONG(res);
	}
}

/*

Search for a file in the Windows and System directories, in this order. If the file exists,
return the complete path to it. If not, return filename.

*/

ZEND_FUNCTION(wb_find_file)
{
	char *s;
	int s_len;
	char path[MAX_PATH * 4];

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "s", &s, &s_len) == FAILURE)
		return;

	strcpy(path, s);
	wbFindFile(path, MAX_PATH * 4);

	RETURN_STRING(path, TRUE);
}

/*

Reads a registry key as a string. If it is a DWORD, convert to a string

TODO: support binary data and other odd formats
NOTE: maximum string is 1024 characters

*/

ZEND_FUNCTION(wb_get_registry_key)
{
	char *key, *subkey, *entry = NULL;
	int key_len, subkey_len, entry_len;
	int buflen = 1024;
	char sval[1024];

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "ss|s", &key, &key_len, &subkey, &subkey_len, &entry, &entry_len) == FAILURE)
		return;

	if(wbReadRegistryKey(key, subkey, entry, sval, &buflen)) {
		if(*sval)
			RETURN_STRING(sval, TRUE)
		else
			RETURN_STRING("", TRUE)
	} else {
		RETURN_NULL();
	}
}

ZEND_FUNCTION(wb_set_registry_key)
{
	char *key, *subkey, *entry;
	int key_len, subkey_len, entry_len;
    zval *source = NULL;

	if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	  "ss|sz!", &key, &key_len, &subkey, &subkey_len, &entry, &entry_len, &source) == FAILURE)
		return;

	if(!source) {
		RETURN_BOOL(wbWriteRegistryKey(key, subkey, entry, NULL, 0, TRUE));
	} else if(source->type == IS_LONG || source->type == IS_BOOL) {
		RETURN_BOOL(wbWriteRegistryKey(key, subkey, entry, NULL, source->value.lval, FALSE));
	} else if(source->type == IS_DOUBLE) {
		char szAux[50];
		sprintf(szAux, "%20.20f", source->value.dval);
		RETURN_BOOL(wbWriteRegistryKey(key, subkey, entry, szAux, 0, TRUE));
	} else if(source->type == IS_STRING) {
		RETURN_BOOL(wbWriteRegistryKey(key, subkey, entry, source->value.str.val, 0, TRUE));
	} else {
		zend_error(E_WARNING, "Invalid parameter type passed to function %s()",
		  get_active_function_name(TSRMLS_C));
		RETURN_NULL();
	}
}

ZEND_FUNCTION(wb_create_timer)
{
	long pwbo;
	int id, ms;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	 "lll", &pwbo, &id, &ms) == FAILURE)
		return;

	if(!wbIsWBObj((void *)pwbo, TRUE))
		RETURN_NULL();

	RETURN_BOOL(wbSetTimer((PWBOBJ)pwbo, id, MAX(1, ms)));
}

ZEND_FUNCTION(wb_destroy_timer)
{
	long pwbo;
	int id;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	 "ll", &pwbo, &id) == FAILURE)
		return;

	if(!wbIsWBObj((void *)pwbo, TRUE))
		RETURN_NULL();

	RETURN_BOOL(wbSetTimer((PWBOBJ)pwbo, id, 0));
}

ZEND_FUNCTION(wb_wait)
{
	long pwbo = 0, pause = 0, flags = WBC_KEYDOWN;

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC,
	 "|lll", &pwbo, &pause, &flags) == FAILURE)
		return;

	if(pwbo != 0 && !wbIsWBObj((void *)pwbo, TRUE))
		RETURN_NULL();

	RETURN_LONG(wbCheckInput((PWBOBJ)pwbo, flags, pause));
}

//------------------------------------------------------------------ END OF FILE
