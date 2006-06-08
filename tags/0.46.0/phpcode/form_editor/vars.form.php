<?php

/*******************************************************************************

WINBINDER - form editor PHP file (generated automatically)

*******************************************************************************/

// Control identifiers

if(!defined('IDC_PUSHBUTTON1004')) define('IDC_PUSHBUTTON1004', 1004);
if(!defined('IDC_PUSHBUTTON1005')) define('IDC_PUSHBUTTON1005', 1005);

// Create window

$winmain = wb_create_window(null, AppWindow, 'Variables', WBC_CENTER, WBC_CENTER, 171, 189, 0x00000000, 0);

// Insert controls

$ctrl_1 = wb_create_control($winmain, Frame, 'Frame1', 20, 20, 120, 115, 0, 0x00000000, 0, 0);
$ctrl_2 = wb_create_control($winmain, PushButton, 'Button1', 35, 50, 90, 25, IDC_PUSHBUTTON1004, 0x00000000, 0, 0);
$ctrl_3 = wb_create_control($winmain, PushButton, 'Button2', 35, 85, 90, 25, IDC_PUSHBUTTON1005, 0x00000000, 0, 0);

// End controls

?>