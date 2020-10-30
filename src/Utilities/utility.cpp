#include "../../shared/dependencies/dependencies.hpp"
#include "../../shared/Utilities/Utils.hpp"
#include "../../shared/Utilities/variables/globals.hpp"

using std::cout;
using std::endl;
using std::cin;
using namespace System;
using namespace System::Windows::Forms;

int Utils::error(const char* error_message) {
	String^ errText = gcnew String(error_message);

	if (g.debug)
		cout << "[-] " << error_message << endl;
	else
		MessageBox::Show(errText, L"Error",
			System::Windows::Forms::MessageBoxButtons::OK);
	return safeExit();
}

void Utils::successInput(PCSTR msg)
{
	if (g.debug)
		cout << "[+] " << msg << endl;
	Sleep(1000);
}

void Utils::msgBox(const char* msg) {
	String^ txt = gcnew String(msg);
	MessageBox::Show(txt, L"Info", System::Windows::Forms::MessageBoxButtons::OK);
}

void Utils::getProcId(const char* procName, DWORD& proc_id)
{
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	DWORD process_id = 0;

	//if snapshot is not invalid
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(hSnap, &procEntry))//start
		{
			do
			{
				if (!_stricmp(procEntry.szExeFile, procName))//compare the szExeFile(process name) with our provided one
				{
					process_id = procEntry.th32ProcessID;//here th32ProcessID is the pid
					break;
				}
			} while (Process32Next(hSnap, &procEntry));//go to the next process in the snapshot
		}
	}
	CloseHandle(hSnap);
	proc_id = process_id;//return the process id by reference to proc_id
}

bool Utils::file_exists(std::string file_name)
{
	struct stat buffer;//buffer of stat structure
	return stat(file_name.c_str(), &buffer) == 0;//get info about given file and puts info in buffer -> check if worked if returns 0
	//file exists!
}
