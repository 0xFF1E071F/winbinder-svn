<?php

/*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Form editor - File I/O functions

*******************************************************************************/

//-------------------------------------------------------------------- CONSTANTS

define("SYS_INIFILE",	"fe_main.ini");
define("PROJ_HEADER",	";*******************************************************************************\r\n;\r\n; WINBINDER - form editor project\r\n;\r\n;*******************************************************************************\r\n");
define("PHP_HEADER",	"/*******************************************************************************\r\n\r\nWINBINDER - form editor PHP file (generated automatically)\r\n\r\n*******************************************************************************/\r\n\r\n");

//-------------------------------------------------------------------- FUNCTIONS

/* Read project data from file */

function read_project($filename)
{
	global $wb;

	$wb->project = parse_ini(file_get_contents($filename), false);

	// Read form data (section "Form"))

	$wb->currentform = 0;
	$section = $wb->project["Form"];
	$title = $section["caption"];
	$style = (int)$section["style"];
	$value = (int)$section["value"];
	$class = $section["class"];
	$geom = preg_split("/\s+/", $section["geom"]);
	reset_form($class, $wb->mainwin, $title, max(1, (int)$geom[2]), max(1, (int)$geom[3]), $style, $value);
	$ncontrols = (int)$section["controls"];

	// Loop to read control data from project file

	for($i = 0; $i < $ncontrols; $i++) {

		// Read a section with the form data

		$section = @$wb->project["Form_ctrl" . (string)($i + 1)];
		if(!$section)
			break;

		// Read control data

		$class = $section["class"];
		$caption = $section["caption"];
		$geom = preg_split("/\s+/", $section["geom"]);
		$id = $section["id"];
		$style = $section["style"];
		$value = $section["value"];
		create_control($class, $caption,
			max(1, (int)$geom[2]),
			max(1, (int)$geom[3]),
			max(0, (int)$geom[0]),
			max(0, (int)$geom[1]),
			$id, $style, $value, false);
	}
	wb_set_text($wb->statusbar, "Created $i controls");

	$wb->form[$wb->currentform]->ncurrent_control = -1;

	foreach($wb->project_array as $var) {
		$var = strtolower($var);
		$wb->form[$wb->currentform]->$var = $wb->project["Projectsettings"][$var];
		if(!$wb->form[$wb->currentform]->$var)
			$wb->form[$wb->currentform]->$var = constant("DEFAULT_" . strtoupper($var));
	}
/*
	$wb->form[$wb->currentform]->formvar = $wb->project["Projectsettings"]["formvar"];
	if(!$wb->form[$wb->currentform]->formvar)
		$wb->form[$wb->currentform]->formvar = DEFAULT_FORMVAR;
	$wb->form[$wb->currentform]->parent = $wb->project["Projectsettings"]["parent"];
	if(!$wb->form[$wb->currentform]->parent)
		$wb->form[$wb->currentform]->parent = DEFAULT_PARENT;
*/

	wb_set_selected($wb->tree, 0);
	update_control_data(true);
}


/* Save project data to file */

function save_project($filename)
{
	global $wb;

	// Set project properties (section "Projectsettings")

//	$wb->project["Projectsettings"]["formvar"] = $wb->form[$wb->currentform]->formvar ? $wb->form[$wb->currentform]->formvar : DEFAULT_FORMVAR;
//	$wb->project["Projectsettings"]["parent"] = $wb->form[$wb->currentform]->parent ? $wb->form[$wb->currentform]->parent : DEFAULT_PARENT;

	foreach($wb->project_array as $var)
		$wb->project["Projectsettings"][$var] = $wb->form[$wb->currentform]->$var ? $wb->form[$wb->currentform]->$var : constant("DEFAULT_" . strtoupper($var));

	// Set form data (section "Form")

	$wb->project["Form"]["class"] = $wb->form[$wb->currentform]->cclass;
	$wb->project["Form"]["caption"] = $wb->form[$wb->currentform]->caption;
	$wb->project["Form"]["geom"] = "WBC_CENTER WBC_CENTER " .
		(string)$wb->form[$wb->currentform]->width . " " .
		(string)$wb->form[$wb->currentform]->height;
	$wb->project["Form"]["style"] = $wb->form[$wb->currentform]->style;
	$wb->project["Form"]["value"] = $wb->form[$wb->currentform]->value;
	$wb->project["Form"]["controls"] = $wb->form[$wb->currentform]->numcontrols;

	// Loop to read control data from project file

	$ncontrols = $wb->form[$wb->currentform]->numcontrols;

	for($i = 0; ; $i++) {

		// Set a section with the form data

		$section = "Form_ctrl" . (string)($i + 1);

		// Read control data

		$ct = @$wb->form[$wb->currentform]->ct[$i];

		if($ct && ($i < $ncontrols)) {

			// Set existing controls

			$wb->project[$section]["class"] = $ct->cclass;
			$wb->project[$section]["caption"] = $ct->caption;
			$wb->project[$section]["geom"] =
				(string)$ct->left . " " .
				(string)$ct->top . " " .
				(string)$ct->width . " " .
				(string)$ct->height;
			$wb->project[$section]["style"] = $ct->style;
			$wb->project[$section]["value"] = $ct->value;
			$wb->project[$section]["id"] = $ct->id;

		} else {

			// Remove deleted controls

			if(is_array($wb->project) && array_key_exists($section, $wb->project)) {
				unset($wb->project[$section]);
			} else {
				break;							// Exit loop
			}
		}
	}

	// Save project file to disk

	file_put_contents($filename, generate_ini($wb->project, PROJ_HEADER));
	wb_set_text($wb->statusbar, "Project saved");
	wb_set_text($wb->mainwin, basename($filename) . " - " . APPNAME);
	$wb->proj_filename = $filename;
}


/* Save PHP code to file */

function save_phpcode($filename)
{
	global $wb;

	// Set project variables

	foreach($wb->project_array as $var) {
		$$var = $wb->form[$wb->currentform]->$var;
		if(!$var) {
			$var = constant("DEFAULT_" . strtoupper($var));
		}
	}

	// Set up some useful variables

	$form = $wb->form[$wb->currentform];
	$valueid = $wb->form[$wb->currentform]->startval;
	$ctrlid = $wb->form[$wb->currentform]->startctrlval;
	$ncontrols = $form->numcontrols;
	$tabnumber = 0;

	// Start PHP code

	if($filename)
		$phpcode = "<?php\r\n\r\n" . PHP_HEADER;
	else
		$phpcode = "";

	// Create code to define the IDC_ constants

	$phpcode .= "// Control identifiers\r\n\r\n";
	for($i = 0; $i < $ncontrols; $i++) {
		$ct = @$wb->form[$wb->currentform]->ct[$i];

		// Create a define() call for each string identifier

		if(!preg_match("/^-?[0-9]+$/", $ct->id)) {
			if(preg_match("/^" . $wb->form[$wb->currentform]->prefix . "[a-z]+([0-9]+)$/i", $ct->id, $matches)) {
				$value = $matches[1];
			} else {
				$value = $valueid++;
			}

			// Don't generate code for preset constants

			if($ct->id) {
				switch($ct->id) {
					case 'IDABORT':
					case 'IDCANCEL':
					case 'IDCLOSE':
					case 'IDDEFAULT':
					case 'IDHELP':
					case 'IDIGNORE':
					case 'IDNO':
					case 'IDOK':
					case 'IDRETRY':
					case 'IDYES':
						break;

					default:
						$phpcode .= "if(!defined('{$ct->id}')) define('{$ct->id}', $value);\r\n";
				}
			}
		}
	}

	// Create code to generate the form

	if(!$wb->form[$wb->currentform]->istabpage) {
		$phpcode .= "\r\n// Create window\r\n\r\n";
		$phpcode .= "$formvar = wb_create_window($parent, " .
			($form->cclass == "TabPage" ? "AppWindow" : $form->cclass) . ', ' .
			($wb->form[$wb->currentform]->localize && $filename ?
			make_valid_id(str_replace('.prj', '', basename($filename))) : "'{$form->caption}'") .
			", WBC_CENTER, WBC_CENTER, {$form->width}, {$form->height}, " .
			sprintf("0x%08X", $form->style) . ", {$form->value});\r\n";
	} else {
		$tabnumber = $wb->form[$wb->currentform]->tabnumber;
	}

	//--------------------- Control loop: create code to generate the controls

	$phpcode .= "\r\n// Insert controls\r\n\r\n";

	$last_tab = null;
	for($i = 0; $i < $ncontrols; $i++) {
		$ct = @$wb->form[$wb->currentform]->ct[$i];
		$cid = (!$ct->id ? '0' : $ct->id);

		$ctrlparent = $formvar;
		$ctrlcode = '';
		$xoff = 0;
		$yoff = 0;

		//--------------------- Adds optional code for tabs

		if($wb->form[$wb->currentform]->insertontabs) {

			// If a control is over a tab control, force its parent to be the tab

			static $xtaboffset = 0;
			static $ytaboffset = 0;

			if($ct->cclass == 'TabControl') {
				$ctrlcode = '$tab = ';
				$ctrlparent = $formvar;
				$tabctrl = $ct;
				$xtaboffset = $tabctrl->left;
				$ytaboffset = $tabctrl->top + 22;	// Height of a tab, should be read from API
			} else {
				$ctrlcode = '';

				// Is the control inside the tab?

				if(isset($tabctrl) && (($ct->left >= $tabctrl->left) &&
				   ($ct->left <= $tabctrl->left + $tabctrl->width) &&
				   ($ct->top >= $tabctrl->top) &&
				   ($ct->top <= $tabctrl->top + $tabctrl->height))) {
					$ctrlparent = '$tab';
					$xoff = $xtaboffset;
					$yoff = $ytaboffset;
				} else {
					$ctrlparent = $formvar;
					$xoff = 0;
					$yoff = 0;
				}
			}
			}

		//--------------------- Adds optional code (before control creation)

		if($wb->form[$wb->currentform]->filllists)
			switch($ct->cclass) {
				case 'ComboBox':
				case 'ListBox':
					$ctrlcode .= '$ctrl = ';
					break;
			}

		if($wb->form[$wb->currentform]->fillheaders)
			switch($ct->cclass) {
				case 'ListView':
				case 'ImageButton':
					$ctrlcode .= '$ctrl = ';
					break;
			}

		if($wb->form[$wb->currentform]->imagenames)
			switch($ct->cclass) {
				case 'ImageButton':
					$ctrlcode .= '$ctrl = ';
					break;
			}

		if($wb->form[$wb->currentform]->applyvalues)
			switch($ct->cclass) {
				case 'ScrollBar':
				case 'Slider':
				case 'Gauge':
					$ctrlcode .= '$ctrl = ';
					break;
			}

		//---------------------  Add variable name (if any)

		$var = $wb->form[$wb->currentform]->ctrlvar;
		if($var) {
			if($var[0] != '$')
				$var = '$' . $var;
			$ctrlcode .= sprintf($var, $ctrlid) . ' = ';
			$ctrlid++;
		}

		//---------------------  Add code to create control

		$phpcode .= $ctrlcode . "wb_create_control($ctrlparent, {$ct->cclass}, " .
			($wb->form[$wb->currentform]->localize && $filename && $ct->caption ?
			make_valid_id($ct->caption) : "'{$ct->caption}'") .
			", " . ($ct->left - $xoff) . ", " . ($ct->top - $yoff) .
			", {$ct->width}, {$ct->height}, {$cid}, " .
			sprintf("0x%08X", $ct->style) . ", {$ct->value}, $tabnumber);\r\n";

		//--------------------- Adds optional code (after control creation)

		switch($ct->cclass) {

			case 'ImageButton':

				if($wb->form[$wb->currentform]->imagenames) {
					if((substr($ct->caption, -4) == '.bmp') && file_exists($ct->caption))
						$imgfile = "'$ct->caption'";
					else
						$imgfile = "'resources\\symb_imagebutton.bmp'";

					$phpcode .=
						"\$img = wb_load_image($imgfile);\n" .
						"  wb_set_image(\$ctrl, \$img, NOCOLOR, 0, $ct->value);\n" .
						"  wb_destroy_image(\$img);"
					;
				}
				break;

			case 'ListView':
				if($wb->form[$wb->currentform]->fillheaders)
					$phpcode .= "wb_set_text(\$ctrl, '$ct->caption');\n";
				break;

			case 'ComboBox':
			case 'ListBox':
				if($wb->form[$wb->currentform]->filllists)
					$phpcode .= "wb_set_text(\$ctrl, explode(',', '$ct->caption'));\n";
				break;

			case 'ScrollBar':
			case 'Slider':
			case 'Gauge':
				if($wb->form[$wb->currentform]->applyvalues)
					$phpcode .= "wb_set_value(\$ctrl, $ct->value);\n";
				break;
		}
	} // end control loop

	if(!$filename)
		$phpcode = str_replace('$this->', '$', $phpcode);	// Prevents errors in PHP 5 -- Stefano

	$phpcode .= "\r\n// End controls\r\n";

	//--------------------- Add ending PHP code and save file

	if($filename) {
		$phpcode .= "\r\n?>";
		$filename = str_replace(".prj", ".form.php", $filename);
		file_put_contents($filename, $phpcode);

		// Generate localization file

		if($wb->form[$wb->currentform]->localize) {
			$phpcode = "<?php\r\n\r\n" . PHP_HEADER;

			$phpcode .= "// Identifiers for localization\r\n\r\n";

			// Generate line for dialog box title

			if(!$wb->form[$wb->currentform]->istabpage) {
				$id = make_valid_id(str_replace('.form.php', '', basename($filename)));
				$phpcode .= "define('$id'," .
				  str_repeat(' ', 26 - strlen($id)) . "'{$form->caption}');\n\n";
			}

			// Create a define() call for each localization identifier

			for($i = 0; $i < $ncontrols; $i++) {
				$ct = @$wb->form[$wb->currentform]->ct[$i];
				$cid = (!$ct->id ? '0' : $ct->id);

				if($ct->caption) {
					$id = make_valid_id($ct->caption);
					if(strlen($id) < 26)
						$phpcode .= "define('$id'," .
						  str_repeat(' ', 26 - strlen($id)) . "'{$ct->caption}');\n";
					else
						$phpcode .= "define('$id', '{$ct->caption}');\n";
				}
			}
			$phpcode .= "\r\n?>";
			$filename = str_replace(".form", ".lang", $filename);
			file_put_contents($filename, $phpcode);
		}

	} else {
		return $phpcode;
	}
}

function read_settings()
{
	global $wb;

	// Read data from INI file

	$wb->settings = parse_ini(file_get_contents(SYS_INIFILE));

	if(!isset($wb->settings['Settings'])) {
		$wb->settings = parse_ini("[Settings]\nmain_geom = \"100 100 730 575\"\nfilepath = \"\"\n wireframe = 0\n grid = 1\n ghost = 1\n showhex = 1\n autophp = 1\n constructionlines = 1\n showgrid = 1\n autopath = 1");
	}

	// 	Read various settings

	foreach($wb->options_array as $var) {
		$ctrl = @wb_get_control($wb->mainwin, constant("IDC_" . strtoupper($var)));
		if($ctrl) {
			$var = strtolower($var);
			$wb->$var = @$wb->settings["Settings"][$var];
			if($wb->$var !== '' && preg_match("/[\d\.\,]+/", $wb->$var))
				wb_set_value($ctrl, $wb->$var);
			else
				wb_set_text($ctrl, $wb->$var);
		}
	}

	read_window_geom($wb->mainwin, "main", true);
}

function save_settings()
{
	global $wb;

	wb_set_text($wb->statusbar, "Saving configuration...");

	// Get values

	save_window_geom($wb->mainwin, "main", true);

	// Get various settings

	foreach($wb->options_array as $var) {
		$var = strtolower($var);
		if($wb->$var === '')
			$wb->settings["Settings"][$var] = '';
		elseif(preg_match("/[\d\.\,]+/", $wb->$var))
			$wb->settings["Settings"][$var] = (int)$wb->$var;
		else
			$wb->settings["Settings"][$var] = $wb->$var;
	}

	// Save options to INI file

	$contents = generate_ini($wb->settings, "; Make Release INI file\r\n");
	if($contents) {
		file_put_contents(SYS_INIFILE, $contents);
		wb_set_text($wb->statusbar, "Configuration saved.");
	} else
		wb_message_box($wb->mainwin, "Problem saving file " . SYS_INIFILE);

}

// Read window geometry data from INI file

function read_window_geom($window, $prefix, $resize=false)
{
	global $wb;

	if(!@$window)
		return;
	$geom = $wb->settings["Settings"][$prefix . "_geom"];
	$geom = preg_split("/\s+/", $geom);

	$desk = wb_get_system_info('workarea');
	$desk = preg_split("/\s+/", $desk);

	wb_set_position($window,
		max(min((int)$desk[2] - $geom[2], $geom[0]), 0),
		max(min((int)$desk[3] - $geom[3], $geom[1]), 0)
	);

	if($resize) {
		wb_set_size($window,
			min(max(MIN_WIDTH, (int)$geom[2]), (int)$desk[2]),
			min(max(MIN_HEIGHT, (int)$geom[3]), (int)$desk[3])
		);
	}
}

// Save window geometry data to INI file

function save_window_geom($window, $prefix, $resize=false)
{
	global $wb;

	if(!@$window)
		return;
	$pos = wb_get_position($window);
	$size = wb_get_size($window);
	if($resize)
		$wb->settings["Settings"][$prefix . "_geom"] = "{$pos[0]} {$pos[1]} {$size[0]} {$size[1]}";
	else
		$wb->settings["Settings"][$prefix . "_geom"] = "{$pos[0]} {$pos[1]}";
}

function make_valid_id($str)
{
	global $wb;

	$id = '';
	$len = strlen($str);
	for($i = 0; $i < $len; $i++) {
		if( ($str[$i] >= '0' && $str[$i] <= '9') ||
			($str[$i] >= 'A' && $str[$i] <= 'Z') ||
			($str[$i] >= 'a' && $str[$i] <= 'z') ||
			($str[$i] == '_'))
			$id .= strtoupper($str[$i]);
	}
	return $wb->form[$wb->currentform]->locprefix . $id;
}

//------------------------------------------------------------------ END OF FILE
