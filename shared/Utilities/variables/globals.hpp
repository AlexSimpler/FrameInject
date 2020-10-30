#pragma once

class globals {
public:
	DWORD proc_id = NULL;
	HANDLE h_process = NULL;
	void* allocatedMemory = NULL;
	PCSTR procName = NULL;//get the name of the window

	//Dll related stuff
	char* dll_path = NULL; //get the dll path
	const char* dll_name = NULL;

	//window checkboxes
	BOOL llib = TRUE;
	BOOL mmap = FALSE;
	BOOL debug = FALSE;
	BOOL closeOnInjection = FALSE;
	BOOL msgBoxes = TRUE;

	//current window
	DWORD myWind = NULL;

	//current console window
	HWND console = NULL;
	bool stopped = false;
};

extern globals g;