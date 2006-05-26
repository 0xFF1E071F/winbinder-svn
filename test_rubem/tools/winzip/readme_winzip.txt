------------------------------------------------------------------------------

README file for WinZip command-line users

------------------------------------------------------------------------------

To create source code snapshots, it is preferable to use the MAKE_RELEASE utility, located in folder Code\make_release, because it automates the process. Nevertheless, if you want to use the command line to create source code snapshots or public releases, you may use the WinZip Command Line Support Add-On (WZZIP). Please follow the steps below.

1) Check the zipme.txt and zipmenot.txt files. They are configured for very economical snapshots. Edit them as needed to include or remove files.
2) Create a Windows shortcut (or a tool in your favorite text editor) as follows:

	"C:\Program Files\WinZip\WZZIP.EXE" Archive\_RenameMe_.zip -r -p @Tools\winzip\snapshot_zipme.txt -x@Tools\winzip\snapshot_zipmenot.txt

	Replace the parameters with the actual files and folders in your disk.

3) Go to the Archive folder and rename the new _RenameMe_.zip file to something like winbinder_1.23.045_src.zip.

------------------------------------------------------------------------------

I'd very much appreciate if you sent me corrections or updated information about this document, or a procedure for a different tool. Please contact me at:

Rubem Pechansky
http://www.hypervisual.com/winbinder/contact.php
