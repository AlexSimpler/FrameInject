#pragma once

class globals {
public:
	DWORD proc_id = NULL;
	HANDLE h_process = NULL;
	void* allocatedMemory = NULL;
	char* dll_path[MAX_PATH] = {};
	PCSTR procName = NULL;//get the name of the window
	PCSTR dll_name = NULL; //get the dll

	//window checkboxes
	BOOL llib = TRUE;
	BOOL mmap = FALSE;
	BOOL debug = FALSE;
	BOOL closeOnInjection = FALSE;
	BOOL msgBoxes = TRUE;

	//current console window
	HWND console = NULL;
	bool stopped = false;
};

extern globals g;