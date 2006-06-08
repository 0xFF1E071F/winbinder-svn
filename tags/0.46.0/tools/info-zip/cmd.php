<?

// Constants for Info-zip

define("ZIPPER", '"' . ZIPAPP . '"' . " -r %s . -i@" . WB_ROOT . "tools\\info-zip\\%s_zipme.txt -x@" . WB_ROOT . "tools\\info-zip\\%s_zipmenot.txt%s");

?>