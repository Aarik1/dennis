// ==================[Copyright Aarik R. 2023]==================
// Purpose : Dennis installer
//
//
// =============================================================

#include <Windows.h>
#include <ShlObj_core.h>
#include <string>
#include <iostream>
#include <fstream>

// Dennis executable in header form.

// DennisCore executable
#include "DennisCore.exe.h"

// Dectalk dll
#include "dtspeak.dll.h"

// uninstallDennis batch file
#include "uninstallDennis.bat.h"

// Dont care.
#define _CRT_SECURE_NO_WARNINGS

std::wstring getUserDocuments() {
	// Get the documents folder.
	wchar_t* path = 0;
	SHGetKnownFolderPath(FOLDERID_Documents, NULL, NULL, &path);

	std::wstring str;
	str = path;

	return str;
}

#ifdef _WIN64
int DennisBox(std::string caption, std::string message, UINT type) {
	return MessageBox(NULL, std::wstring(message.begin(), message.end()).c_str(), std::wstring(caption.begin(), caption.end()).c_str(), type);
}
#else
int DennisBox(std::string caption, std::string message, UINT type) {
	return MessageBox(NULL, message.c_str(), caption.c_str(), type);
}
#endif

void installDennis() {
	// Get Documents path.
	std::wstring userDocPathW = getUserDocuments();

	// Get the path where dennis will be dropped
	std::string dropPath(userDocPathW.begin(), userDocPathW.end());
	dropPath = dropPath + "\\DennisFiles";

	// Create the directory for dennis
#ifdef _WIN64
	CreateDirectory(std::wstring(dropPath.begin(), dropPath.end()).c_str(), NULL);
#else
	CreateDirectory(dropPath.c_str(), NULL);
#endif
	// Everything that will be dropped
	std::string executable = dropPath + "\\DennisCore.exe";
	std::string uninstallBat = dropPath + "\\uninstallDennis.bat";
	std::string dtSpeakDLL = dropPath + "\\dtspeak.dll";

	// Incase dennis needs to be patched kill it.
	WinExec("taskkill /IM DennisCore.exe /F", SW_HIDE);

	// Wait a bit
	Sleep(150);

	// Drop our files
	std::fstream fs;
	fs.open(executable, std::fstream::out | std::fstream::binary);
	fs.write((char*)&DennisCore_exe, sizeof(DennisCore_exe));
	fs.close();

	// Drop dtspeak dll
	fs.open(dtSpeakDLL, std::fstream::out | std::fstream::binary);
	fs.write((char*) & dtspeak_dll, sizeof(dtspeak_dll));
	fs.close();

	// Drop Uninstaller
	fs.open(uninstallBat, std::fstream::out);
	fs.write((char*)&uninstallDennis_bat, sizeof(uninstallDennis_bat));
	fs.close();

	// Drop persisitance key
	HKEY hkey = NULL;
#ifdef _WIN64
	LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey); //Creates a key       
	LONG status = RegSetValueEx(hkey, L"DennisCore.exe", 0, REG_SZ, (BYTE*)std::wstring(executable.begin(), executable.end()).c_str(), (std::wstring(executable.begin(), executable.end()).size() + 1) * sizeof(wchar_t));
#else
	LONG createStatus = RegCreateKey(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey); //Creates a key       
	LONG status = RegSetValueEx(hkey, "DennisCore.exe", 0, REG_SZ, (BYTE*)std::wstring(executable.begin(), executable.end()).c_str(), (std::wstring(executable.begin(), executable.end()).size() + 1) * sizeof(wchar_t));
#endif
	// Execute Dennis
#ifdef _WIN64
	ShellExecute(NULL, L"open", std::wstring(executable.begin(), executable.end()).c_str(), NULL, std::wstring(dropPath.begin(), dropPath.end()).c_str(), 0);
#else
	ShellExecute(NULL, "open", executable.c_str(), NULL, dropPath.c_str(), 0);
#endif

	DennisBox("Dennis Installer", "Dennis has been installed.\n You can uninstall it by running the batch file located in Documents\\DennisFiles", MB_OK | MB_ICONINFORMATION);

}

// Main function
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	
	// Ask the user if they want to install dennis.
	const int msgBox = MessageBox(NULL, "Would you like to install Dennis to your system?", "Dennis Installer", MB_YESNO);

	switch (msgBox) {
		case IDYES:
		{
			installDennis();
			break;
		}
		default:
		{
			DennisBox("Dennis Installer", "Dennis install has been canceled.", MB_OK | MB_ICONINFORMATION);
			return 0;
		}
	}

	return 0;
}

