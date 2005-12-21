<?php

/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Menu editor

*******************************************************************************/

//-------------------------------------------------------------------- FUNCTIONS

function create_menu_editor($parent)
{
	global $menulist;

	// Remove the line below while not under development

	file_put_contents("le_menu_editor.rc.php", "<?php\n\n" . parse_rc(file_get_contents("le_menu_editor.rc"),
	  '$dlg', '$parent', 'ModalDialog') . "\n?>");

	include("le_menu_editor.rc.php");

	wb_set_handler($dlg, "process_menu_editor");

	$menulist = wb_get_control($dlg, IDC_MENULIST);

	wb_set_text($menulist, array(
		array("Caption", 130),
		array("Value", 80),
		array("Flags", 80),
		array("Accel", 90),
	));
	wb_set_image($menulist, PATH_RES . "treeview.bmp", 0, GREEN, 10);

	wb_set_text(wb_get_control($dlg, IDC_LEVEL), array(
		"First-level menu",
		"Menu item",
		"Separator",
		"Sub-menu",
	));

	return $dlg;
}

function process_menu_editor($window, $id, $ctrl=0)
{
	global $settings, $w;
	global $menulist;
	static $item = 0;

	switch($id) {

		case IDC_CAPTION:
			$enabled = (wb_get_text($ctrl) != "");
			wb_set_enabled(wb_get_control($window, IDC_INSERT), $enabled);
			wb_set_enabled(wb_get_control($window, IDC_CHANGE), $enabled);
			break;

		case IDC_INSERT:
			wb_create_items($menulist, array(array(
				wb_get_text(wb_get_control($window, IDC_CAPTION)),
				wb_get_text(wb_get_control($window, IDC_VALUE)),
				wb_get_value(wb_get_control($window, IDC_CHECKED)) ? "Checked" : "",
				wb_get_text(wb_get_control($window, IDC_ACCEL)),
			)));
			break;

		case IDC_CHANGE:
			$line = wb_get_selected($menulist);
			if(is_array($line) && count($line) == 1) {
				$line = $line[0];
			wb_set_item($menulist, $line, array(
				wb_get_text(wb_get_control($window, IDC_CAPTION)),
				wb_get_text(wb_get_control($window, IDC_VALUE)),
				wb_get_value(wb_get_control($window, IDC_CHECKED)) ? "Checked" : "",
				wb_get_text(wb_get_control($window, IDC_ACCEL)),
			));
			}
			break;

		case IDOK:
		case IDCANCEL:
			wb_destroy_window($window);
			break;
	}
}

//------------------------------------------------------------------ END OF FILE

?>
