:*******************************************************************************
:
: WINBINDER - A native Windows binding for PHP
:
: Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
: Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)
:
: Batch file to build WinBinder for PHP 5
:
:*******************************************************************************

@echo off

:-------------------------------------------------------------------------------

: Users must set up these variables

Set WBIDIR=C:\@desenv\WinBinder
Set VCTDIR=C:\Util\Microsoft Visual C++ Toolkit 2003
Set SDKDIR=C:\Util\Microsoft Platform SDK
Set LIBDIR=C:\Util\PHP\php-5.1.1
Set VER=5
Set MAKE=nmake

: These will be used by the makefile

Set DLLDIR=%WBIDIR%\binaries\php%VER%\ext\
Set PHPLIB=php%VER%ts.lib
Set SRCDIR=%WBIDIR%\csource\core
Set PATH=%SDKDIR%\bin;%VCTDIR%\bin;%PATH%
Set INCLUDE=%SDKDIR%\Include;%VCTDIR%\include;%SRCDIR%;%INCLUDE%
Set LIB=%SDKDIR%\Lib;%VCTDIR%\lib;%LIB%

:-------------------------------------------------------------------------------

: Call Make

cd %WBIDIR%\tools\msvc\php%VER%
%MAKE% -f makefile

:------------------------------------------------------------------- END OF FILE
