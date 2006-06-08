<?php

/*******************************************************************************

WINBINDER - form editor PHP file (generated automatically)

*******************************************************************************/

// Control identifiers

if(!defined('IDC_TABCONTROL1001')) define('IDC_TABCONTROL1001', 1001);
if(!defined('IDC_EDITBOX1002')) define('IDC_EDITBOX1002', 1002);
if(!defined('IDC_EDITBOX1003')) define('IDC_EDITBOX1003', 1003);
if(!defined('IDC_LABEL1001')) define('IDC_LABEL1001', 1001);
if(!defined('IDC_LABEL1001')) define('IDC_LABEL1001', 1001);
if(!defined('IDC_RADIOBUTTON1001')) define('IDC_RADIOBUTTON1001', 1001);
if(!defined('IDC_CHECKBOX1001')) define('IDC_CHECKBOX1001', 1001);
if(!defined('IDC_COMBOBOX1003')) define('IDC_COMBOBOX1003', 1003);
if(!defined('IDC_EDITBOX1004')) define('IDC_EDITBOX1004', 1004);
if(!defined('IDC_LISTVIEW1001')) define('IDC_LISTVIEW1001', 1001);
if(!defined('IDC_IMAGEBUTTON1001')) define('IDC_IMAGEBUTTON1001', 1001);
if(!defined('IDC_EDITBOX1001')) define('IDC_EDITBOX1001', 1001);
if(!defined('IDC_SLIDER1002')) define('IDC_SLIDER1002', 1002);
if(!defined('IDC_SCROLLBAR1003')) define('IDC_SCROLLBAR1003', 1003);
if(!defined('IDC_GAUGE1004')) define('IDC_GAUGE1004', 1004);

// Create window

$winmain = wb_create_window(null, ModalDialog, '(Empty Form)', WBC_CENTER, WBC_CENTER, 389, 315, 0x00000000, 0);

// Insert controls

$tab = $control = wb_create_control($winmain, TabControl, 'Tab1,Tab2,Tab3', 5, 20, 155, 240, IDC_TABCONTROL1001, 0x00000000, 0, 0);
$control = wb_create_control($tab, EditBox, 'EditBox2', 20, 13, 90, 20, IDC_EDITBOX1002, 0x00000000, 0, 0);
$control = wb_create_control($tab, EditBox, 'EditBox3', 20, 38, 90, 20, IDC_EDITBOX1003, 0x00000000, 0, 0);
$control = wb_create_control($tab, Label, 'Label4', 20, 73, 90, 15, IDC_LABEL1001, 0x00000000, 0, 0);
$control = wb_create_control($tab, Label, 'Label5', 20, 93, 90, 15, IDC_LABEL1001, 0x00000000, 0, 0);
$control = wb_create_control($tab, RadioButton, 'RadioButton6', 20, 123, 120, 15, IDC_RADIOBUTTON1001, 0x00000000, 0, 0);
$control = wb_create_control($winmain, CheckBox, 'CheckBox7', 185, 20, 120, 15, IDC_CHECKBOX1001, 0x00000000, 0, 0);
$ctrl = $control = wb_create_control($winmain, ComboBox, 'ComboBox8', 185, 40, 120, 60, IDC_COMBOBOX1003, 0x00000040, 0, 0);
wb_set_text($ctrl, explode(',', 'ComboBox8'));
$control = wb_create_control($winmain, EditBox, 'EditBox9', 185, 70, 90, 20, IDC_EDITBOX1004, 0x00000000, 0, 0);
$control = wb_create_control($winmain, ListView, 'ListView10,List12', 185, 100, 185, 75, IDC_LISTVIEW1001, 0x00000000, 0, 0);
$control = wb_create_control($winmain, ImageButton, 'resources\ctrl_listbox3.bmp', 185, 190, 24, 24, IDC_IMAGEBUTTON1001, 0x00000000, 3, 0);
$control = wb_create_control($tab, EditBox, 'EditBox12', 25, 163, 90, 20, IDC_EDITBOX1001, 0x00000000, 0, 0);
$ctrl = $control = wb_create_control($winmain, Slider, 'Slider13', 260, 185, 100, 20, IDC_SLIDER1002, 0x00000000, 50, 0);
wb_set_value($ctrl, 50);
$ctrl = $control = wb_create_control($winmain, ScrollBar, 'ScrollBar14', 225, 185, 18, 82, IDC_SCROLLBAR1003, 0x00000000, 50, 0);
wb_set_value($ctrl, 50);
$ctrl = $control = wb_create_control($winmain, Gauge, 'Gauge15', 260, 215, 100, 20, IDC_GAUGE1004, 0x00000000, 50, 0);
wb_set_value($ctrl, 50);

// End controls

?>