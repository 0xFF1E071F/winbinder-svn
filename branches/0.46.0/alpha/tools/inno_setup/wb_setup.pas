{*******************************************************************************

 WINBINDER - A native Windows binding for PHP

 Copyright © 2004-2006 Hypervisual - see LICENSE.TXT for details
 Author: Rubem Pechansky (http://www.hypervisual.com/winbinder/contact.php)

 Code section for Inno Setup

*******************************************************************************}

//----------------------------------------------- CONSTANTS AND GLOBAL VARIABLES

const
	WB_DEBUG = False;	// Set to True for debugging, set to False for release
	CRLF = #13#10;
	php50file = 'php50_minimal.zip';
	php50exts = 'php50_libs.zip';
	php51file = 'php51_minimal.zip';
	php51exts = 'php51_libs.zip';
var
  ServerPage: TInputOptionWizardPage;
  nCode: Integer;
  unzippgm: String;
  cmd: String;
  ServerURL: String;

//------------------------------------------------------------------- PROTOTYPES

// Isxdl function prototypes (from isxdl.iss)

function isxdl_Download(hWnd: Integer; URL, Filename: PChar): Integer;
external 'isxdl_Download@files:isxdl.dll stdcall';

procedure isxdl_AddFile(URL, Filename: PChar);
external 'isxdl_AddFile@files:isxdl.dll stdcall';

procedure isxdl_AddFileSize(URL, Filename: PChar; Size: Cardinal);
external 'isxdl_AddFileSize@files:isxdl.dll stdcall';

function isxdl_DownloadFiles(hWnd: Integer): Integer;
external 'isxdl_DownloadFiles@files:isxdl.dll stdcall';

procedure isxdl_ClearFiles;
external 'isxdl_ClearFiles@files:isxdl.dll stdcall';

function isxdl_IsConnected: Integer;
external 'isxdl_IsConnected@files:isxdl.dll stdcall';

function isxdl_SetOption(Option, Value: PChar): Integer;
external 'isxdl_SetOption@files:isxdl.dll stdcall';

function isxdl_GetFileName(URL: PChar): PChar;
external 'isxdl_GetFileName@files:isxdl.dll stdcall';

//----------------------------------------------------- FUNCTIONS AND PROCEDURES

// Setup initialization function

function InitializeSetup: Boolean;
begin
	isxdl_SetOption('title', 'Setup - WinBinder');
	isxdl_SetOption('label', 'Download PHP runtime files');
	isxdl_SetOption('resume', 'true');
	Result := true;
end;

// Used by UnzipFiles below

procedure GoUnzip(source: String; targetdir: String);
  begin
    source := ExpandConstant('{tmp}\' + source);
	if not FileExists(unzippgm) then MsgBox('Could not find file ' + unzippgm, mbError, MB_OK)
	else if not FileExists(source) then MsgBox('Could not find file ' + source, mbError, MB_OK)
	else begin
		cmd := '-o -qq "' + source + '" -d "' + targetdir + '"';
		if Exec(unzippgm, cmd, '', SW_HIDE, ewWaitUntilIdle, nCode) = false then begin
			MsgBox('Could not run', mbError, MB_OK);
		end;
	end;
end;

// Unzip files

procedure UnzipFiles(Ver: String);
var
  sComp: String;
begin
  sComp := WizardSelectedComponents(false);
  unzippgm := ExpandConstant('{tmp}\unzip.exe');
  if Pos('php_50', sComp) > 0 then GoUnzip(php50file, ExpandConstant('{app}\binaries\php50'));
  if Pos('addlib50', sComp) > 0 then GoUnzip(php50exts, ExpandConstant('{app}\binaries\php50\ext'));
  if Pos('php_51', sComp) > 0 then GoUnzip(php51file, ExpandConstant('{app}\binaries\php51'));
  if Pos('addlib51', sComp) > 0 then GoUnzip(php51exts, ExpandConstant('{app}\binaries\php51\ext'));
end;

// Build server selection page

procedure BuildSelectionPage();
begin
	// Create the page

	if WB_DEBUG then begin
		ServerPage := CreateInputOptionPage(wpSelectComponents,
			'DEBUG (test) setup',
			'',
			'Optional files will be copied from a local folder ignoring the option selected below.',
			True, True);
	end else begin
		ServerPage := CreateInputOptionPage(wpSelectComponents,
			'Setup - WinBinder',
			'Select a server to download the additional files you requested.',
			'Choose the server nearest to your location from one of the options below:',
			True, True);
	end

	// Add items

	ServerPage.Add('Puzzle (Switzerland)');
	ServerPage.Add('EasyNews (USA)');
	ServerPage.Add('DreamHost (USA)');
	ServerPage.Add('HEAnet (Ireland)');
	ServerPage.Add('University of Kent (UK)');
	ServerPage.Add('OptusNet (Australia)');
	ServerPage.Add('Voxel (USA)');
	ServerPage.Add('Surfnet (Netherlands)');
	ServerPage.Add('Mesh Solutions (Germany)');
	ServerPage.Add('OVH (France)');
	ServerPage.Add('UFPR (Brazil)');
	ServerPage.Add('NCHC (Taiwan)');
	ServerPage.Add('Internap (USA)');
	ServerPage.Add('Jaist (Japan)');
	ServerPage.Add('Citkit (Russia)');
	ServerPage.Add('Switch (Switzerland)');
	ServerPage.Add('Keihanna (Japan)');

	// Set initial values

	ServerPage.SelectedValueIndex := 0;

end;

// Retrieve selected server

procedure GetSelectedServer();
begin

	// Read values into variables

	case ServerPage.SelectedValueIndex of
		0: ServerURL := 'puzzle';
		1: ServerURL := 'easynews';
		2: ServerURL := 'http://hypervisual.com/winbinder/files/';
		3: ServerURL := 'heanet';
		4: ServerURL := 'kent';
		5: ServerURL := 'optusnet';
		6: ServerURL := 'voxel';
		7: ServerURL := 'surfnet';
		8: ServerURL := 'mesh';
		9: ServerURL := 'ovh';
		10: ServerURL := 'ufpr';
		11: ServerURL := 'nchc';
		12: ServerURL := 'internap';
		13: ServerURL := 'jaist';
		14: ServerURL := 'citkit';
		15: ServerURL := 'switch';
		16: ServerURL := 'keihanna';
	end;

	if(Pos('http://', ServerURL) = 0) then begin
		ServerURL := 'http://' + ServerURL + '.dl.sourceforge.net/sourceforge/winbinder/';
	end;

end;

// Download files

function NextButtonClick(CurPage: Integer): Boolean;
var
	hWnd: Integer;
	sComp: String;
	sFileName: String;
begin
	Result := true;

    hWnd := StrToInt(ExpandConstant('{wizardhwnd}'));
    sComp := WizardSelectedComponents(false);
    isxdl_ClearFiles;

	// Builds the server selection page

	if CurPage = wpSelectComponents then begin
		if (Pos('php_5', sComp) > 0) or (Pos('addlib_5', sComp) > 0) or
		   (Pos('php_51', sComp) > 0) or (Pos('addlib_51', sComp) > 0) then begin
			BuildSelectionPage();
		end;
	end;

	if CurPage = wpReady then begin

		// Get server

		if (Pos('php_50', sComp) > 0) or (Pos('addlib_50', sComp) > 0) then begin
			GetSelectedServer();
			isxdl_SetOption('description', 'Server: ' + ServerURL + CRLF + 'Please wait, downloading...');
		end;

		// Add files

		if Pos('php_50', sComp) > 0 then begin
		  sFileName := ExpandConstant('{tmp}\' + php50file);
		  isxdl_AddFile(ServerURL + php50file, sFileName);
		end;
		if Pos('php_51', sComp) > 0 then begin
		  sFileName := ExpandConstant('{tmp}\' + php51file);
		  isxdl_AddFile(ServerURL + php51file, sFileName);
		end;

		if Pos('addlib50', sComp) > 0 then begin
		  sFileName := ExpandConstant('{tmp}\' + php50exts);
		  isxdl_AddFile(ServerURL + php50exts, sFileName);
		end;

		if Pos('addlib51', sComp) > 0 then begin
		  sFileName := ExpandConstant('{tmp}\' + php51exts);
		  isxdl_AddFile(ServerURL + php51exts, sFileName);
		end;

		// Download

		if (Pos('php_50', sComp) > 0) or (Pos('addlib_50', sComp) > 0) then begin
			if WB_DEBUG then begin
				FileCopy('C:\@desenv\WinBinder\@Privado\Arquivo\2005\php5_minimal.zip', ExpandConstant('{tmp}\php5_minimal.zip'), False);
				FileCopy('C:\@desenv\WinBinder\@Privado\Arquivo\2005\php5_libs.zip', ExpandConstant('{tmp}\php5_libs.zip'), False);
			end else begin
				if isxdl_DownloadFiles(hWnd) = 0 then begin
					MsgBox('Download failed. Please review your setup options or try again later.', mbError, MB_OK);
					Result := false;
				end;
			end;
		end

		if (Pos('php_51', sComp) > 0) or (Pos('addlib_51', sComp) > 0) then begin
			if WB_DEBUG then begin
				FileCopy('C:\@desenv\WinBinder\@Privado\Arquivo\2005\php51_minimal.zip', ExpandConstant('{tmp}\php5_minimal.zip'), False);
				FileCopy('C:\@desenv\WinBinder\@Privado\Arquivo\2005\php51_libs.zip', ExpandConstant('{tmp}\php5_libs.zip'), False);
			end else begin
				if isxdl_DownloadFiles(hWnd) = 0 then begin
					MsgBox('Download failed. Please review your setup options or try again later.', mbError, MB_OK);
					Result := false;
				end;
			end;
		end

	end;

end;

//------------------------------------------------------------------ END OF FILE
