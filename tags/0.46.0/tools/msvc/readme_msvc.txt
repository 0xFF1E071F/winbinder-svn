------------------------------------------------------------------------------

README file for MSVC users

------------------------------------------------------------------------------

There are two separate folders, one for PHP4 and the other for PHP5. Each contains a batch file and a makefile. The php?ts.lib file must be obtained in the PHP downloads page (see step 2 below).

------------------------------------------------------------------------------
Step 1. Get a Microsoft compiler.
------------------------------------------------------------------------------

You must have purchased and installed one of the following commercial compilers:

	- Microsoft Visual C++
	- Microsoft Visual Suite
	- Visual C++ 2005 Express Edition

If you already have one of those, skip to step 2. If not, here are the instructions to assemble your own Microsoft "suite" with the following free components, available directly from Microsoft:

	1. Visual C++ Toolkit 2003 (32 MB)
	   http://www.microsoft.com/downloads/details.aspx?familyid=272BE09D-40BB-49FD-9CB0-4BFA122FA91B&displaylang=en

	2. Windows® Server 2003 SP1 Platform SDK (394 MB)
	   http://www.microsoft.com/downloads/details.aspx?FamilyID=eba0128f-a770-45f1-86f3-7ab010b398a3&DisplayLang=en
	   IMPORTANT: when installing the SDK, make sure you either include all the files in the "Microsoft Windows Core SDK" component or perform a full install; otherwise an essential tool, nmake.exe, may be left out of the installation.

	3. Headers and Libraries for Internet Explorer 5.5
	   http://msdn.microsoft.com/archive/default.asp?url=/archive/en-us/samples/internet/libraries/ie55_lib/default.asp
	   You must copy the following files to the /include subdirectory of the Platform SDK:
			mshtml.h
			mshtmhst.h
			mshtmlc.h

------------------------------------------------------------------------------
Step 2. Copy the necessary files from the PHP project.
------------------------------------------------------------------------------

You must download some files from the http://www.php.net/downloads.php page.

For PHP 4.4.1:

	1. PHP 4.4.1 Complete Source Code
	   http://www.php.net/get/php-4.4.1.tar.bz2/from/a/mirror
	   or
	   http://www.php.net/get/php-4.4.1.tar.gz/from/a/mirror
	   Install all these files in some know place, say, C:\Util\PHP\php-4.4.1.

	2. Windows Binaries / PHP 4.4.1 zip package:
	   http://www.php.net/get/php-4.4.1-Win32.zip/from/a/mirror
	   From this package you need the php4ts.lib file. Copy it to C:\@desenv\WinBinder\tools\msvc\php4.

For PHP 5.1.1:

	1. PHP 5.1.1 Complete Source Code
	   http://www.php.net/get/php-5.1.1.tar.bz2/from/a/mirror
	   or
	   http://www.php.net/get/php-5.1.1.tar.gz/from/a/mirror
	   Install all these files in some know place, say, C:\Util\PHP\php-5.1.1.

	2. Windows Binaries / PHP 5.1.1 zip package:
	   http://www.php.net/get/php-5.1.1-Win32.zip/from/a/mirror
	   From this package you need the php5ts.lib file. Copy it to C:\@desenv\WinBinder\tools\msvc\php5.

------------------------------------------------------------------------------
NOTE for PHP version 5.1.1:
------------------------------------------------------------------------------

If you get a compilation error like this:

	c:\Util\PHP\php-5.1.1\main\snprintf.h(114) : fatal error C1017:
	invalid integer constant expression

you will have to make a correction in file snprintf.h. Change line 144 from:

	#if PHP_WIN32

to

	#if defined PHP_WIN32

and the error will go away.

------------------------------------------------------------------------------
Step 3. Build WinBinder.
------------------------------------------------------------------------------

Choose one of the following options according to your installation and preferences:

Option 1. Building WinBinder with the compiler IDE
--------------------------------------------------

(To be written by someone who has a full MSVC IDE)

Option 2. Building WinBinder using a console window
---------------------------------------------------

First you must set up the variables in the appropriate go.bat file (tools\msvc\php4\go.bat or tools\msvc\php4\go.bat) to match the directories you chose for the components and the make utility.

Simply double-click the appropriate batch file located at tools\msvc\php4\go.bat or tools\msvc\php5\go.bat.

Option 3. Building WinBinder with a code editor
-----------------------------------------------

You may want to configure your favorite source code editor to run the batch and makefile. To do so, you must first set up the variables in the appropriate go.bat file (tools\msvc\php4\go.bat or tools\msvc\php4\go.bat) to match the directories you chose for the components and the make utility.

Then follow the steps below:

1) Create a tool that points to the batch file, for example C:\@desenv\WinBinder\tools\msvc\php4\go.bat.
2) If your text editor supports regular expressions to match compilation errors and errors, enter the following RE in the appropriate field:

^\([^(]+\)(\([0-9]+\)):

In this RE, the file is at register 1 and Line is at register 2.

4) Assign a keyboard shortcut to the newly created tool. Now you can build WinBinder simply by pressing one key.
5) You may have to quit your text editor, start it again and recompile your program.
6) Now you can check for errors or warnings, double-click the error/warning in the Command Results window so the text editor will open the file at the appropriate location.

If you use TextPad, see also tools\textpad\readme_textpad.txt for more configuration tips.

------------------------------------------------------------------------------

I'd very much appreciate if you sent me corrections or updated information about this document. Please contact me at:

Rubem Pechansky
http://www.hypervisual.com/winbinder/contact.php
