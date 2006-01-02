;*******************************************************************************
;
; WINBINDER - A native Windows binding for PHP
;
; Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
; Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)
;
; WinBinder setup configuration for Inno Setup
;
;*******************************************************************************

[Files]
Source: readme.txt; DestDir: {app}; Flags: ignoreversion isreadme
Source: docs\*.*; DestDir: {app}\docs; Flags: ignoreversion; Excludes: copy of*.*
Source: phpcode\*.*; DestDir: {app}\phpcode; Flags: recursesubdirs ignoreversion createallsubdirs; Excludes: copy of*.*,*.a,*.bak,*.dep,*.err,*.lib,*.lnk,*.o,*.obj,*.res,*.tws,*.xrf,tp*.bat; Components: WinBinder/Examples
Source: binaries\php4\*.*; DestDir: {app}\binaries\php4; Components: PHP/PHP_4; Excludes: copy of*.*,*.dll,*.a,*.bak,*.dep,*.err,*.lib,*.lnk,*.o,*.obj,*.res,*.tws,*.xrf,tp*.bat
Source: binaries\php4\php4ts.dll; DestDir: {app}\binaries\php4; Components: PHP/PHP_4
Source: binaries\php4\ext\php_winbinder.dll; DestDir: {app}\binaries\php4\ext; Components: PHP/PHP_4
Source: binaries\php4\ext\php_sqlite.dll; DestDir: {app}\binaries\php4\ext; Components: PHP/PHP_4/AddLib4
Source: binaries\php4\ext\freeimage.dll; DestDir: {app}\binaries\php4\ext; Components: PHP/PHP_4/AddLib4
Source: binaries\php50\*.*; DestDir: {app}\binaries\php50; Components: PHP/PHP_50; Excludes: copy of*.*,*.exe,*.dll,*.a,*.bak,*.dep,*.err,*.lib,*.lnk,*.o,*.obj,*.res,*.tws,*.xrf,tp*.bat
Source: binaries\php50\ext\php_winbinder.dll; DestDir: {app}\binaries\php50\ext; Components: PHP/PHP_50
Source: {app}\binaries\php4\ext\freeimage.dll; DestDir: {app}\binaries\php50\ext; Components: PHP/PHP_50; Flags: external
Source: binaries\php51\*.*; DestDir: {app}\binaries\php51; Components: PHP/PHP_51; Excludes: copy of*.*,*.exe,*.dll,*.a,*.bak,*.dep,*.err,*.lib,*.lnk,*.o,*.obj,*.res,*.tws,*.xrf,tp*.bat
Source: binaries\php51\ext\php_winbinder.dll; DestDir: {app}\binaries\php51\ext; Components: PHP/PHP_51
Source: {app}\binaries\php4\ext\freeimage.dll; DestDir: {app}\binaries\php51\ext; Components: PHP/PHP_51; Flags: external
Source: ..\..\Util\Info-Zip\unzip\unzip.exe; DestDir: {tmp}; Components: PHP/PHP_51; AfterInstall: UnzipFiles('51'); Flags: dontcopy
Source: ..\..\Util\Download DLL\isxdl.dll; DestDir: {tmp}; Flags: dontcopy

[Icons]
Name: {group}\Welcome to WinBinder; Filename: {app}\binaries\php4\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Components: PHP/PHP_4; WorkingDir: {app}\phpcode\examples; IconFilename: {app}\phpcode\resources\hyper.ico
Name: {group}\Welcome to WinBinder; Filename: {app}\binaries\php50\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Components: PHP/PHP_50; WorkingDir: {app}\phpcode\examples; IconFilename: {app}\phpcode\resources\hyper.ico
Name: {group}\Welcome to WinBinder; Filename: {app}\binaries\php51\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Components: PHP/PHP_51; WorkingDir: {app}\phpcode\examples; IconFilename: {app}\phpcode\resources\hyper.ico
Name: {group}\WinBinder Manual; Filename: {app}\docs\winbinder.chm
Name: {group}\Readme; Filename: {app}\readme.txt
Name: {group}\Uninstall; Filename: {uninstallexe}
Name: {group}\Docs\License; Filename: {app}\docs\license.txt
Name: {group}\Docs\Release notes; Filename: {app}\docs\release_notes.txt
Name: {group}\Docs\Changelog; Filename: {app}\docs\changelog.txt
Name: {userdesktop}\Welcome to WinBinder; Filename: {app}\binaries\php4\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Components: PHP/PHP_4; WorkingDir: {app}\phpcode\examples; IconFilename: {app}\phpcode\resources\hyper.ico
Name: {userdesktop}\Welcome to WinBinder; Filename: {app}\binaries\php50\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Components: PHP/PHP_50; WorkingDir: {app}\phpcode\examples; IconFilename: {app}\phpcode\resources\hyper.ico
Name: {userdesktop}\Welcome to WinBinder; Filename: {app}\binaries\php51\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Components: PHP/PHP_51; WorkingDir: {app}\phpcode\examples; IconFilename: {app}\phpcode\resources\hyper.ico

[Setup]
OutputDir=C:\@desenv\WinBinder\@Privado\Arquivo
OutputBaseFilename=winbinder_setup
VersionInfoCompany=Hypervisual
VersionInfoDescription=WinBinder
AppCopyright=Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
AppName=WinBinder
LicenseFile=C:\@desenv\WinBinder\docs\license.txt
RestartIfNeededByRun=false
DefaultGroupName=WinBinder
ShowLanguageDialog=no
DefaultDirName={sd}\WinBinder
MinVersion=4.1.1998,5.0.2195
UsePreviousAppDir=true
UninstallDisplayName=
AppComments=
AppID={{EF0FB390-6815-4BC3-A070-C7525D5625C4}
UninstallFilesDir={app}\uninstall
AppMutex=winbinder-app
EnableDirDoesntExistWarning=false
FlatComponentsList=false
DisableStartupPrompt=false
AlwaysShowComponentsList=true
DirExistsWarning=auto
ChangesAssociations=true
MergeDuplicateFiles=false
SourceDir=C:\@desenv\WinBinder
UseSetupLdr=true

AppVerName=WinBinder version 0.44.172
VersionInfoVersion=0.44.172
SolidCompression=true
Compression=lzma/max
InternalCompressLevel=normal
AppPublisher=Hypervisual
AppPublisherURL=http://hypervisual.com/
AppSupportURL=http://hypervisual.com/winbinder/
AppUpdatesURL=http://hypervisual.com/winbinder/

[Run]
Filename: {app}\binaries\PHP4\php-win.exe; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Flags: nowait postinstall; Description: Run Welcome application; WorkingDir: {app}\phpcode; Components: PHP/PHP_4
Filename: {app}\binaries\PHP50\php-win.exe; Components: PHP/PHP_50 and not PHP/PHP_4; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Flags: nowait postinstall; Description: Run Welcome application; WorkingDir: {app}\phpcode
Filename: {app}\binaries\PHP51\php-win.exe; Components: PHP/PHP_51 and not PHP/PHP_4; Parameters: """{app}\phpcode\examples\welcome.phpw"""; Flags: nowait postinstall; Description: Run Welcome application; WorkingDir: {app}\phpcode

[Components]
Name: WinBinder; Description: WinBinder; Types: Complete Default Update_WB
Name: WinBinder/Examples; Description: Help and examples; Types: Complete Default Update_WB
Name: PHP; Description: PHP; Types: Complete Default Update_PHP
Name: PHP/PHP_4; Description: PHP 4; Types: Complete Default Update_PHP
Name: PHP/PHP_4/AddLib4; Description: Additional libraries (SQLite, FreeImage); Types: Complete Default Update_PHP
Name: PHP/PHP_50; Description: PHP 5.0 (download); ExtraDiskSpaceRequired: 3600000; Types: Complete Update_PHP
Name: PHP/PHP_50/AddLib50; Description: Additional libraries (MySQL, FreeImage); Types: Complete Update_PHP
Name: PHP/PHP_51; Description: PHP 5.1 (download); ExtraDiskSpaceRequired: 3600000; Types: Complete Update_PHP
Name: PHP/PHP_51/AddLib51; Description: Additional libraries (MySQL, FreeImage); Types: Complete Update_PHP

[Types]
Name: Default; Description: Default installation
Name: Update_WB; Description: Update an existing WinBinder installation
Name: Update_PHP; Description: Update PHP version only
Name: Complete; Description: Complete installation
Name: Custom_install; Description: Custom; Flags: iscustom

[Registry]
Root: HKCR; SubKey: .phpw; ValueType: string; ValueData: WinBinder script; Flags: uninsdeletekey
Root: HKCR; SubKey: WinBinder script file; ValueType: string; ValueData: WinBinder script; Flags: uninsdeletekey
Root: HKCR; SubKey: WinBinder script\Shell\Open\Command; ValueType: string; ValueData: """{app}\binaries\php4\php-win.exe"" ""%1"""; Flags: uninsdeletevalue; Components: PHP/PHP_4
Root: HKCR; Subkey: WinBinder script\DefaultIcon; ValueType: string; ValueData: {app}\binaries\php4\php-win.exe,0; Flags: uninsdeletevalue; Components: PHP/PHP_4
Root: HKCR; SubKey: WinBinder script\Shell\Open\Command; ValueType: string; ValueData: """{app}\binaries\php50\php-win.exe"" ""%1"""; Flags: uninsdeletevalue; Components: PHP/PHP_50
Root: HKCR; Subkey: WinBinder script\DefaultIcon; ValueType: string; ValueData: {app}\binaries\php50\php-win.exe,0; Flags: uninsdeletevalue; Components: PHP/PHP_50
Root: HKCR; SubKey: WinBinder script\Shell\Open\Command; ValueType: string; ValueData: """{app}\binaries\php51\php-win.exe"" ""%1"""; Flags: uninsdeletevalue; Components: PHP/PHP_51
Root: HKCR; Subkey: WinBinder script\DefaultIcon; ValueType: string; ValueData: {app}\binaries\php51\php-win.exe,0; Flags: uninsdeletevalue; Components: PHP/PHP_51
Root: HKCU; Subkey: Software\WinBinder; ValueType: string; ValueName: InstallDir; ValueData: {app}; Flags: uninsdeletekeyifempty uninsdeletevalue

[LangOptions]
DialogFontName=Tahoma
DialogFontSize=8

[Tasks]

[INI]
;Filename: {app}\binaries\PHP4\php.ini; Section: PHP; Key: extension; String: php_sqlite.dll; Components: PHP/PHP_4/AddLib4
;Filename: {app}\binaries\PHP50\php.ini; Section: PHP; Key: extension; String: php_mysql.dll; Components: PHP/PHP_50/AddLib50
;Filename: {app}\binaries\PHP51\php.ini; Section: PHP; Key: extension; String: php_mysql.dll; Components: PHP/PHP_51/AddLib51

[UninstallDelete]
Name: {app}\binaries; Type: filesandordirs; Components: 

[_ISTool]
LogFile=C:\@desenv\WinBinder\tools\inno_setup\wb_setup_log.txt
LogFileAppend=false

[Code]
#include "wb_setup.pas"
