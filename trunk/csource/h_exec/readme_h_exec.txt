********************************************************************************

H_EXEC for WinBinder - A native Windows binding for PHP

Copyright © 2004-2005 Hypervisual - see LICENSE.TXT for details
Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

********************************************************************************

Use this utility to run a WinBinder script (or any other application) without
installing anything or messing with the registry.


Quick instructions
------------------------------------------------------------------------------

- The executable looks for a INI file with the same name. So you may change
  the executable file and the INI file name at the same time to, say, run.exe
  and run.ini. This way you may have several utilities in the same folder, one
  for each application.
- The name of the data section in the INI file must be always "h_exec".
- "run" is the path and name of the executable, usually <path>\php-win.exe. It
  can be relative to the current path or an absolute path.
- "run" can also be the name of a non-executable file with a known association
  like readme.txt, winbinder.chm or faq.html.
- "param" is the name of the phpw script to run, like, say, calc.phpw.
- Use searchpath=1 to prepend the path of the h_exec.exe utility to the name
  of the application to run. This is generally not necessary.
- See the included INI file examples.

There are other undocumented features like command line parameters and reading
data from the registry but I still have to properly review and test those.


Error codes
------------------------------------------------------------------------------

 0   The operating system is out of memory or resources.
 2   The specified file was not found.
 3   The specified path was not found.
 5   The operating system denied access to the specified file.
 8   There was not enough memory to complete the operation.
11   The .EXE file is invalid (non-Win32 .EXE or error in .EXE image).
26   A sharing violation occurred.
27   The filename association is incomplete or invalid.
28   The DDE transaction could not be completed because the request timed out.
29   The DDE transaction failed.
30   DDE transaction not completed: other transactions were being processed.
31   There is no application associated with the given filename extension.
32   The specified dynamic-link library was not found.


------------------------------------------------------------------------------

Rubem Pechansky
http://www.hypervisual.com/winbinder/contact.php
