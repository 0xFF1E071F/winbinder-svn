<?php

// Control identifiers

if(!defined("IDD_DLG1001")) define("IDD_DLG1001", 1001);
if(!defined("IDC_MENULIST")) define("IDC_MENULIST", 1002);
if(!defined("IDC_VALUE")) define("IDC_VALUE", 1003);
if(!defined("IDC_CAPTION")) define("IDC_CAPTION", 1004);
if(!defined("IDCANCEL")) define("IDCANCEL", 1006);
if(!defined("IDC_LEVEL")) define("IDC_LEVEL", 1007);
if(!defined("IDOK")) define("IDOK", 1008);
if(!defined("IDC_MOVEUP")) define("IDC_MOVEUP", 1009);
if(!defined("IDC_MOVEDOWN")) define("IDC_MOVEDOWN", 1010);
if(!defined("IDC_INSERT")) define("IDC_INSERT", 1011);
if(!defined("IDC_CHECKED")) define("IDC_CHECKED", 1012);
if(!defined("IDC_ACCEL")) define("IDC_ACCEL", 1014);
if(!defined("IDC_STATIC1015")) define("IDC_STATIC1015", 1015);
if(!defined("IDC_CHANGE")) define("IDC_CHANGE", 1016);
if(!defined("IDC_STATIC1017")) define("IDC_STATIC1017", 1017);
if(!defined("IDC_STATIC1018")) define("IDC_STATIC1018", 1018);
if(!defined("IDC_DISABLED")) define("IDC_DISABLED", 1019);
if(!defined("IDC_IMAGE")) define("IDC_IMAGE", 1020);
if(!defined("IDC_STATIC1021")) define("IDC_STATIC1021", 1021);

// Create window

$dlg = wb_create_window($parent, 103, "Menu Editor", WBC_CENTER, WBC_CENTER, 402, 424, 0, 0);

// Insert controls

wb_create_control($dlg, ListView, "", 4, 151, 384, 204, IDC_MENULIST, WBC_VISIBLE | WBC_ENABLED | WBC_SORT, 0);
wb_create_control($dlg, EditBox, "", 79, 69, 179, 21, IDC_VALUE, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, EditBox, "", 79, 45, 179, 21, IDC_CAPTION, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, PushButton, "Cancel", 314, 365, 74, 21, IDCANCEL, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, ComboBox, "", 79, 19, 179, 146, IDC_LEVEL, WBC_VISIBLE | WBC_ENABLED | WBC_READONLY, 0);
wb_create_control($dlg, PushButton, "OK", 235, 365, 74, 21, IDOK, WBC_VISIBLE | WBC_ENABLED, 0);
$_tmp_ctrl_ = wb_create_control($dlg, PushButton, "up_arrow.bmp", 368, 68, 20, 21, IDC_MOVEUP, WBC_VISIBLE | WBC_ENABLED, 0);
wb_set_image($_tmp_ctrl_, 'C:\@desenv\WinBinder\phpcode\layout_editor/../resources/up_arrow.bmp', GREEN); unset($_tmp_ctrl_);
$_tmp_ctrl_ = wb_create_control($dlg, PushButton, "dn_arrow.bmp", 368, 92, 20, 21, IDC_MOVEDOWN, WBC_VISIBLE | WBC_ENABLED, 0);
wb_set_image($_tmp_ctrl_, 'C:\@desenv\WinBinder\phpcode\layout_editor/../resources/dn_arrow.bmp', GREEN); unset($_tmp_ctrl_);
wb_create_control($dlg, PushButton, "&Insert", 314, 16, 74, 21, IDC_INSERT, WBC_VISIBLE | WBC_DISABLED, 0);
wb_create_control($dlg, CheckBox, "&Checked", 269, 68, 70, 16, IDC_CHECKED, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, EditBox, "", 79, 94, 179, 21, IDC_ACCEL, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, Label, "&Accelerator:", 1, 92, 70, 14, IDC_STATIC1015, WBC_VISIBLE | WBC_ENABLED | WBC_RIGHT, 0);
wb_create_control($dlg, PushButton, "&Change", 314, 40, 74, 21, IDC_CHANGE, WBC_VISIBLE | WBC_DISABLED, 0);
wb_create_control($dlg, Label, "Ca&ption:", 1, 42, 70, 14, IDC_STATIC1017, WBC_VISIBLE | WBC_ENABLED | WBC_RIGHT, 0);
wb_create_control($dlg, Label, "Identi&fier:", 1, 66, 70, 14, IDC_STATIC1018, WBC_VISIBLE | WBC_ENABLED | WBC_RIGHT, 0);
wb_create_control($dlg, CheckBox, "&Disabled", 269, 89, 70, 16, IDC_DISABLED, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, EditBox, "", 79, 120, 179, 21, IDC_IMAGE, WBC_VISIBLE | WBC_ENABLED, 0);
wb_create_control($dlg, Label, "&Image:", 1, 120, 70, 14, IDC_STATIC1021, WBC_VISIBLE | WBC_ENABLED | WBC_RIGHT, 0);

// End controls

?>