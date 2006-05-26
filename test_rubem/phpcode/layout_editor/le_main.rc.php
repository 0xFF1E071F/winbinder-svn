<?php

// Control identifiers

if(!defined("IDD_DLG101")) define("IDD_DLG101", 101);
if(!defined("IDC_CONTROL")) define("IDC_CONTROL", 1002);
if(!defined("IDC_FASTDRAW")) define("IDC_FASTDRAW", 1005);

// Create window

$wb->mainwin = wb_create_window(NULL, 101, "WinBinder Layout Editor", WBC_CENTER, WBC_CENTER, 732, 555, 268435473, 17344);

// Insert controls

wb_create_control($wb->mainwin, Frame, "", 0, 66, 1498, 3, 0, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($wb->mainwin, Frame, "", 0, 27, 1498, 3, 0, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($wb->mainwin, ListBox, "", 4, 95, 140, 370, IDC_CONTROL, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($wb->mainwin, CheckBox, "&Wireframe (fast screen redraw)", 7, 71, 181, 21, IDC_FASTDRAW, WBC_VISIBLE | WBC_ENABLED, 0);

// End controls

?>