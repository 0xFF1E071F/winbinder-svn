/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Code sample: "Hello world" application

*******************************************************************************/

//----------------------------------------------------------------- DEPENDENCIES

#include <wb.h>      // Include header for WinBinder API layer

//-------------------------------------------------------------------- CONSTANTS

// Application name

#define APPNAME		"Hello world!"

// Control identifiers

#define ID_EDIT		101

//---------------------------------------------------------------- MAIN FUNCTION


int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	WPARAM wParam;
	PWBOBJ pwpoMain;

	// Start WinBinder

	wbInit();

	// Create application window

	pwpoMain = wbCreateWindow(NULL, PopupWindow, APPNAME, WBC_CENTER, WBC_CENTER, 480, 200, 0, 0, 0);

	wbCreateControl(pwpoMain, EditBox, "Hello, I'm here.", 20, 20, 200, 20, ID_EDIT, 0, 0, 0);

	// Enter message loop

	wParam = wbMainLoop();

	// End WinBinder

	wbEnd();
	return wParam;
}

//------------------------------------------------------------------ END OF FILE
