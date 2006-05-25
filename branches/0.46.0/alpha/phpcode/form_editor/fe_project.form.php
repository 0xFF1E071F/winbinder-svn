<?php

/*******************************************************************************

WINBINDER - form editor PHP file (generated automatically)

*******************************************************************************/

// Control identifiers

if(!defined('IDC_FORMVAR')) define('IDC_FORMVAR', 3005);
if(!defined('IDC_PARENT')) define('IDC_PARENT', 3007);
if(!defined('IDC_LABEL3001')) define('IDC_LABEL3001', 3001);
if(!defined('IDC_CTRLVAR')) define('IDC_CTRLVAR', 3008);
if(!defined('IDC_LABEL3001')) define('IDC_LABEL3001', 3001);
if(!defined('IDC_STARTCTRLVAL')) define('IDC_STARTCTRLVAL', 3009);
if(!defined('IDC_PREFIX')) define('IDC_PREFIX', 3011);
if(!defined('IDC_STARTVAL')) define('IDC_STARTVAL', 3013);
if(!defined('IDC_ISTABPAGE')) define('IDC_ISTABPAGE', 3014);
if(!defined('IDC_TABNUMBER')) define('IDC_TABNUMBER', 3016);
if(!defined('IDC_TABNUMBERSPINNER')) define('IDC_TABNUMBERSPINNER', 3017);
if(!defined('IDC_FILLLISTS')) define('IDC_FILLLISTS', 3018);
if(!defined('IDC_FILLHEADERS')) define('IDC_FILLHEADERS', 3019);
if(!defined('IDC_IMAGENAMES')) define('IDC_IMAGENAMES', 3020);
if(!defined('IDC_INSERTONTABS')) define('IDC_INSERTONTABS', 3021);
if(!defined('IDC_APPLYVALUES')) define('IDC_APPLYVALUES', 3022);
if(!defined('IDC_LOCALIZE')) define('IDC_LOCALIZE', 3023);
if(!defined('IDC_LOCPREFIX')) define('IDC_LOCPREFIX', 3025);
if(!defined('IDOK')) define('IDOK', 3026);
if(!defined('IDCANCEL')) define('IDCANCEL', 3027);
if(!defined('IDC_LABEL3001')) define('IDC_LABEL3001', 3001);

// Create window

$wb->winproject = wb_create_window($wb->mainwin, ModalDialog, 'Project Properties', WBC_CENTER, WBC_CENTER, 620, 391, 0x00000001, 0);

// Insert controls

wb_create_control($wb->winproject, Label, 'The properties below apply to the current project. You may use sprintf() syntax for the control variable name.', 20, 10, 580, 15, 0, 0x00000080, 0, 0);
wb_create_control($wb->winproject, Frame, 'General project data', 15, 35, 285, 205, 0, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Frame, 'Tab pages', 15, 245, 285, 65, 0, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Frame, 'Additional code generation options', 315, 35, 285, 205, 0, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, '&Form variable name:', 20, 55, 125, 15, 0, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 155, 55, 135, 20, IDC_FORMVAR, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, '&Parent variable name:', 20, 85, 125, 15, 0, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 155, 85, 135, 20, IDC_PARENT, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, '&Control variable name:', 20, 115, 125, 15, IDC_LABEL3001, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 155, 115, 135, 20, IDC_CTRLVAR, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, 'Control &start value:', 20, 145, 125, 15, IDC_LABEL3001, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 155, 145, 75, 20, IDC_STARTCTRLVAL, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, 'Constant prefi&x:', 25, 175, 120, 15, 0, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 155, 175, 75, 20, IDC_PREFIX, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, 'Constant start &value:', 20, 205, 125, 15, 0, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 155, 205, 75, 20, IDC_STARTVAL, 0x00000400, 0, 0);
wb_create_control($wb->winproject, CheckBox, 'This form is a &tab page', 30, 270, 135, 15, IDC_ISTABPAGE, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, 'Ta&b #', 165, 270, 45, 15, 0, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '0', 215, 270, 55, 20, IDC_TABNUMBER, 0x00000400, 0, 0);
wb_create_control($wb->winproject, Spinner, 'Spinner20', 270, 270, 20, 20, IDC_TABNUMBERSPINNER, 0x00080000, 0, 0);
wb_create_control($wb->winproject, CheckBox, 'Use captions to &fill out ListBoxes and ComboBoxes', 325, 60, 270, 15, IDC_FILLLISTS, 0x00000000, 0, 0);
wb_create_control($wb->winproject, CheckBox, 'Use captions as ListView &headers', 325, 85, 255, 15, IDC_FILLHEADERS, 0x00000000, 0, 0);
wb_create_control($wb->winproject, CheckBox, 'Use captions as image &names for ImageButtons', 325, 110, 255, 15, IDC_IMAGENAMES, 0x00000000, 0, 0);
wb_create_control($wb->winproject, CheckBox, '&Force controls over tabs to be children of tabs', 325, 135, 260, 15, IDC_INSERTONTABS, 0x00000000, 0, 0);
wb_create_control($wb->winproject, CheckBox, 'Apply &values to ScrollBars, Gauges, and Sliders', 325, 160, 270, 15, IDC_APPLYVALUES, 0x00000000, 0, 0);
wb_create_control($wb->winproject, CheckBox, 'Generate additional PHP code for &localization', 325, 185, 245, 15, IDC_LOCALIZE, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, 'Locali&zation prefix:', 340, 205, 114, 15, 0, 0x00000020, 0, 0);
wb_create_control($wb->winproject, EditBox, '', 465, 205, 65, 20, IDC_LOCPREFIX, 0x00000000, 0, 0);
wb_create_control($wb->winproject, PushButton, 'OK', 210, 325, 90, 25, IDOK, 0x00000000, 0, 0);
wb_create_control($wb->winproject, PushButton, 'Cancel', 315, 325, 90, 25, IDCANCEL, 0x00000000, 0, 0);
wb_create_control($wb->winproject, Label, '(%d above)', 238, 145, 65, 15, IDC_LABEL3001, 0x00000000, 0, 0);

// End controls

?>