<?php

/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Layout editor - Controls dialog

*******************************************************************************/

//-------------------------------------------------------------------- FUNCTIONS

function create_control_dlg($parent)
{
	// Remove the line below while not under development

	file_put_contents("dlg_controls.rc.php", "<?php\n\n" . parse_rc(file_get_contents("dlg_controls.rc"),
	  '$dlg', '$parent', 'ModelessDialog') . "\n?>");

	include("dlg_controls.rc.php");

	wb_set_handler($dlg, "process_control");
	return $dlg;
}

function process_control($window, $id)
{
	global $w;

	list_controls($w["mainwin"]);
}

function _list_controls($window)
{
	global $settings, $w, $ctrl_list;

	$ctrls = wb_get_item_list($w["controldlg"]);

	$list = wb_get_control($window, IDC_CONTROL);
	wb_delete_items($list);
	foreach($ctrls as $ctrl) {
		foreach($ctrl_list as $test)
			if($test[0] == wb_get_class($ctrl))
				wb_create_items($list, $test[1] . " " . wb_get_id($ctrl));
	}
}

//------------------------------------------------------------------ END OF FILE

?>
