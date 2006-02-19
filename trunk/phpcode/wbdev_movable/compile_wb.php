<?php 
// *******************************************************************************
// WINBINDER - A native Windows binding for PHP
// Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
// Author: Hans
// create makefile and compile for WinBinder
// *******************************************************************************
// debugbreak();
$dir = pathinfo(__FILE__);
define("PATH_BASE", $dir['dirname'] . '\\');
define("PATH_BIN" , PATH_BASE . 'MSVC-util\bin\\');
define("PATH_INC" , PATH_BASE . 'MSVC-util\inc\\');
define("PATH_LIB" , PATH_BASE . 'MSVC-util\lib\\');

// Stefano: renamed genmakeWB.php to compile_wb.php to enable automatic import and function call

function compile_wb($source_dir, $php_vers, $vers_plus)
{ 
    // set variables for makefile
    $obj_tmp_dir = PATH_BASE . 'obj';
    $dll_dir = PATH_BASE . "WinbinderComp\binaries\php-$php_vers\ext";
    $inc_dir = PATH_INC;
    $ms_lib = PATH_LIB;
    $lib_dir = PATH_BASE . "WinbinderComp\csource\php-$php_vers";
    $phplib = $lib_dir . "\php-" . $php_vers . "ts.lib";
    $cl = PATH_BIN . "cl.exe";
    $rc = PATH_BIN . "rc";
    $link = PATH_BIN . "link";
    $nmake = PATH_BIN . "nmake";
    $cl = "cl";
    $rc = "rc";
    $link = "link";
    $nmake = PATH_BIN . "nmake"; 
    // ------------------------------------------------------------------- Compile environment
    $P_path = getenv('PATH');
    if (strstr($P_path, PATH_BIN) === false) {
        $P_path = PATH_BIN . ";" . $P_path;
    } 
    $P_path = putenv("PATH=$P_path");
    $P_path = putenv("INCLUDE=$inc_dir");
    $P_path = putenv("LIB=$ms_lib"); 
    // ------------------------------------------------------------------- Makefile template
    $m_comp = <<<MCOMP


all: $(DLLDIR)\php_winbinder.dll

$(OBJS): $(SOURCES)
	$(cc) /nologo /MT /W3 /GX /O2 /YX /FD /c /QIfist \
	/D "NDEBUG" /D ZEND_DEBUG=0 /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D HAVE_WIN32STD=1 \
	/I "$(LIBDIR)" /I "$(INCDIR)\" /I "$(LIBDIR)\main" /I "$(LIBDIR)\Zend" /I "$(LIBDIR)\win32" /I "$(LIBDIR)\TSRM" /I "$(LIBDIR)\ext\standard" \
	/Fo"$(OUTDIR)\\\" /Fd"$(OUTDIR)\\\" $(SOURCES)

$(OUTDIR)\php_winbinder.dll.res: $(RCFILE)

$(DLLDIR)\php_winbinder.dll: $(OBJS)
	$(rc) /r /fo $(OUTDIR)\php_winbinder.dll.res /i "$(SRCDIR)\" /d $(FD) /d FILE_NAME="\"php_winbinder.dll\"" /d $(PN) /d $(PV) $(RCFILE)

	$(link) /nologo /dll /machine:I386 -out:$(DLLDIR)\php_winbinder.dll \
	$(OBJS) $(LIBS) $(OUTDIR)\php_winbinder.dll.res

#clean temporary files:
	del /q $(OUTDIR)\ *.pch $(DLLDIR)\php_winbinder.exp $(DLLDIR)\php_winbinder.lib
MCOMP;

    if (!is_dir($obj_tmp_dir)) {
        if (!mkdir($obj_tmp_dir)) {
            // Stefano: now returns message to enable warning handling, instead of calling echo
            return 'Warning: could not create ' . $obj_tmp_dir;
        } 
    } else delete_files($obj_tmp_dir . '\\');

    $libs = array("user32.lib",
        "gdi32.lib",
        "comdlg32.lib",
        "comctl32.lib",
        "shell32.lib",
        "ole32.lib ",
        "oleaut32.lib",
        "winmm.lib",
        "advapi32.lib",
        $phplib
        );

    $c_files = array();
    $h_files = array();
    $rc_files = array();
    $sub_dirs = array('.');

    while (($s_dir = array_shift($sub_dirs)) != null) {
        $content = get_all_files($source_dir, $s_dir);
        $sub_dirs = array_merge($sub_dirs, $content['dir']);
        $c_files = array_merge($c_files, $content['c']);
        $h_files = array_merge($h_files, $content['h']);
        $rc_files = array_merge($rc_files, $content['rc']);
    } // while
    if (count($c_files) == 0) {
        // Stefano: now returns message to enable error handling, instead of calling die
        return 'Fatal error: source to compile not found';
    } 
    // assemble SOURCES OBJS
    $sources_str = "SOURCES = " ;
    $objs_str = "OBJS = " ;
    foreach($c_files as $c_f) {
        $sources_str .= "\t\\\n\t" . $source_dir . $c_f ;
        $objs_str .= "\t\\\n\t" . $obj_tmp_dir . "\\" . str_replace('.c', '.obj', basename($c_f));
    } 
    // assemble LIBS
    $libs_str = "LIBS = " ;
    foreach($libs as $l) {
        $libs_str .= "\t\\\n\t" . $l ;
    } 
    // get rc file
    if (count($rc_files) == 1) {
        $rc_file = $source_dir . $rc_files[0]; // should only one!
    } else $rc_file = ""; // def
    $def_str = "OUTDIR = $obj_tmp_dir \n";
    $def_str .= "LIBDIR = $lib_dir \n";
    $def_str .= "DLLDIR = $dll_dir \n";
    $def_str .= "SRCDIR = $source_dir \n";
    $def_str .= "INCDIR = $inc_dir \n";
    $def_str .= "MSLIB = $ms_lib \n";
    $def_str .= "RCFILE = $rc_file \n";
    $def_str .= "cc = $cl \n";
    $def_str .= "rc = $rc \n";
    $def_str .= "link = $link \n";

    $sources_str .= "\n\n";
    $objs_str .= "\n\n";
    $def_str .= "\n\n"; 
    // stitch together makefile
    $make_str = $def_str . $sources_str . $objs_str . $libs_str . $m_comp;

    $res = file_put_contents("makefile", $make_str); 
    // nmake run
    $cmd = PATH_BIN . 'nmake';
    $par = ' -f makefile FD="FILE_DESCRIPTION=\"\\\\\"Windows Binding for PHP ' . $vers_plus . '\\\\\"\"" PN="PRODUCT_NAME=\"\\\\\"PHP ' . $vers_plus . ' php_winbinder.dll\\\\\"\"" PV="P_VERSION=\"\\\\\"' . $vers_plus . '\\\\\"\""';
    $par = ' -f ' . PATH_BASE . 'makefile FD="FILE_DESCRIPTION=\"\\\\\"Windows Binding for PHP ' . $vers_plus . '\\\\\"\"" PN="PRODUCT_NAME=\"\\\\\"PHP ' . $vers_plus . ' php_winbinder.dll\\\\\"\"" PV="P_VERSION=\"\\\\\"' . $vers_plus . '\\\\\"\""';
    // needed for PHPedit + debugger and php-4.3.10
    if ((!empty($_ENV['HTTP_COOKIE']) and (strstr($_ENV['HTTP_COOKIE'], 'DBGSESSID') != false)) or (PHP_VERSION == '4.3.10')) {
        $dspec = array(0 => array("pipe", "r"),
            1 => array("pipe", "w"),
            2 => array("pipe", "w"));
        $pro = proc_open($cmd . $par, $dspec, $pipes);
        if (is_resource($pro)) {
            $result = "";
            while (!feof($pipes[1])) {
                $result .= fgets($pipes[1], 1024);
            } while (!feof($pipes[2])) {
                $result .= fread($pipes[2], 8024);
            } 
            fclose($pipes[0]);
            fclose($pipes[1]);
            fclose($pipes[2]);
        } 
        proc_close($pro);
    } else {
        $WshShell = new COM('WScript.Shell');
        $WshShell->run('cmd /K ' . $cmd . ' ' . $par . ' > ' . PATH_BASE . 'log.txt & exit', 0, true);
        $result = file_get_contents(PATH_BASE . 'log.txt');
        unlink('log.txt');
    } 
    return $result ;
} 
function get_all_files($dir, $sdir)
{
    $res = array('dir' => array(), 'h' => array(), 'c' => array(), 'rc' => array());
    if ($sdir == '.') {
        $sdir = '';
    } 
    if (is_dir($dir . $sdir)) {
        $dirhnd = opendir($dir . $sdir);
        while ($file = readdir ($dirhnd)) {
            if ($file != "." && $file != "..") {
                if (is_file($dir . $sdir . $file)) {
                    $f_x = pathinfo($file);
                    if (array_key_exists('extension', $f_x)) {
                        $f_x = $f_x['extension'];
                        if ($f_x == 'c') {
                            $res['c'][] = $sdir . $file;
                        } 
                        if ($f_x == 'rc') {
                            $res['rc'][] = $sdir . $file;
                        } 
                        if ($f_x == 'h') {
                            $res['h'][] = $sdir . $file;
                        } 
                    } 
                } elseif (is_dir($dir . $sdir . $file)) {
                    if ($file != '.svn') {
                        $res['dir'][] = $sdir . $file . '\\';
                    } 
                } 
            } 
        } 

        closedir($dirhnd);
    }
    return $res;
} 
function delete_files($dir, $ext = '*')
{
    if (is_dir($dir)) {
        $dirhnd = opendir($dir);
        while ($file = readdir ($dirhnd)) {
            if ($file != "." && $file != "..") {
                if (is_file($dir . $file)) {
                    if (strstr($file, $ext) != false) {
                        unlink($dir . $file);
                    } 
                    if ($ext == '*') {
                        unlink($dir . $file);
                    } 
                } 
            } 
        } 

        closedir($dirhnd);
    } 
    return ;
} 
// ------------------------------------------------------------------- END OF FILE

?>