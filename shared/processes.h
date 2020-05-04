#pragma once

#include "GameFucker.h"
#include "./dependencies/dependencies.hpp"
#include "./Utilities/variables/globals.hpp"
#include "./Utilities/Utils.hpp"

namespace GameFuckerUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections;

	typedef BOOL(WINAPI* LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
	bool sort = true;
	LPFN_ISWOW64PROCESS fnIsWow64Process;

	/**********************************************************************************************//**
	 * @class	processes
	 *
	 * @brief	Summary for processes
	 **************************************************************************************************/
	public ref class processes : public System::Windows::Forms::Form
	{
	private:
		//create the temp mainForm object
		MyForm^ mainForm;
		ListViewColumnSorter^ lvwColumnSorter = nullptr;
	public:
		processes(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		/**********************************************************************************************//**
		 * @fn	processes::processes(MyForm^ callingForm)
		 *
		 * @brief	Overloaded constructor to pass a myForm object by reference.
		 *
		 * @param 	callingForm	The calling form.
		 **************************************************************************************************/
		processes(MyForm^ callingForm)
		{
			mainForm = callingForm; 
			InitializeComponent();
			lvwColumnSorter = gcnew ListViewColumnSorter();
			this->ProcessList->ListViewItemSorter = lvwColumnSorter;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~processes()
		{
			if (components)
			{
				delete components;
			}
		}

		/**********************************************************************************************//**
		 * @fn	bool processes::CheckProcessType(HANDLE hprocess)
		 *
		 * @brief	Check process type (x86 or x64).
		 *
		 * @param 	hprocess	Handle of the process.
		 *
		 * @returns	True if it succeeds, false if it fails.
		 **************************************************************************************************/
		BOOL CheckProcessType(HANDLE hProcess)
		{
				BOOL is64 = FALSE;

				fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
					GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

				if (NULL != fnIsWow64Process)
				{
					if (!fnIsWow64Process(hProcess, &is64))
					{
						//handle error
					}
				}
				return is64;
		}

		/**********************************************************************************************//**
		 * @fn	BOOL processes::GetProcessList()
		 *
		 * @brief	Takes a snapshot of all processes, itterates over them and adds them in list view.
		 *
		 * @info    Snippet inspired by msdocs.
		 * 
		 * @returns	True if it succeeds, false if it fails.
		 **************************************************************************************************/
		BOOL GetProcessList()
		{
			HANDLE hProcessSnap;
			HANDLE hProcess;
			PROCESSENTRY32 pe32;

			// Take a snapshot of all processes in the system.
			hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hProcessSnap == INVALID_HANDLE_VALUE)
			{
				return(FALSE);
			}

			// Set the size of the structure before using it.
			pe32.dwSize = sizeof(PROCESSENTRY32);

			// Retrieve information about the first process,
			// and exit if unsuccessful
			if (!Process32First(hProcessSnap, &pe32))
			{
				Utils::msgBox("Failed to CreateToolhelp32Snapshot");
				CloseHandle(hProcessSnap);          // clean the snapshot object
				return(FALSE);
			}

			// Now walk the snapshot of processes, and
			// display information about each process in turn
			do
			{
				hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe32.th32ProcessID);
				String^ procName = gcnew String(pe32.szExeFile);
				std::string strPid = std::to_string(pe32.th32ProcessID);
				char const* pcstrPid = strPid.c_str();  //use char const* as target type

				String^ pid = gcnew String(pcstrPid);

				ListViewItem^ proc = gcnew ListViewItem(procName);
				proc->SubItems->Add(pid);
				proc->SubItems->Add(CheckProcessType(hProcess) ? "x86" : "x64");
				proc->Tag = procName;
				this->ProcessList->Items->Add(proc);

			} while (Process32Next(hProcessSnap, &pe32));

			CloseHandle(hProcessSnap);
			return(TRUE);
		}

	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ColumnHeader^ Names;
	private: System::Windows::Forms::ColumnHeader^ Pids;
	private: System::Windows::Forms::ListView^ ProcessList;
	private: System::Windows::Forms::Button^ Select;
	private: System::Windows::Forms::ColumnHeader^ Type;
	private: System::Windows::Forms::Button^ refresh;


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Names = (gcnew System::Windows::Forms::ColumnHeader());
			this->Pids = (gcnew System::Windows::Forms::ColumnHeader());
			this->ProcessList = (gcnew System::Windows::Forms::ListView());
			this->Type = (gcnew System::Windows::Forms::ColumnHeader());
			this->Select = (gcnew System::Windows::Forms::Button());
			this->refresh = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(105, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Please select a process:";
			// 
			// Names
			// 
			this->Names->Text = L"Name";
			this->Names->Width = 177;
			// 
			// Pids
			// 
			this->Pids->Text = L"PID";
			// 
			// ProcessList
			// 
			this->ProcessList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->Names, this->Pids,
					this->Type
			});
			this->ProcessList->HideSelection = false;
			this->ProcessList->Location = System::Drawing::Point(10, 25);
			this->ProcessList->Name = L"ProcessList";
			this->ProcessList->Size = System::Drawing::Size(311, 269);
			this->ProcessList->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->ProcessList->TabIndex = 0;
			this->ProcessList->UseCompatibleStateImageBehavior = false;
			this->ProcessList->View = System::Windows::Forms::View::Details;
			this->ProcessList->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &processes::COLUMN_Click);
			this->ProcessList->SelectedIndexChanged += gcnew System::EventHandler(this, &processes::ProccessList_SelectedIndexChanged);
			// 
			// Type
			// 
			this->Type->Text = L"Type";
			// 
			// Select
			// 
			this->Select->Location = System::Drawing::Point(170, 297);
			this->Select->Name = L"Select";
			this->Select->Size = System::Drawing::Size(121, 32);
			this->Select->TabIndex = 2;
			this->Select->Text = L"Select";
			this->Select->UseVisualStyleBackColor = true;
			this->Select->Click += gcnew System::EventHandler(this, &processes::SELECT_Click);
			// 
			// refresh
			// 
			this->refresh->Location = System::Drawing::Point(43, 297);
			this->refresh->Name = L"refresh";
			this->refresh->Size = System::Drawing::Size(121, 32);
			this->refresh->TabIndex = 3;
			this->refresh->Text = L"Refresh";
			this->refresh->UseVisualStyleBackColor = true;
			this->refresh->Click += gcnew System::EventHandler(this, &processes::REFRESH_Click);
			// 
			// processes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 330);
			this->Controls->Add(this->refresh);
			this->Controls->Add(this->Select);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ProcessList);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"processes";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"遊戲混蛋";
			this->Load += gcnew System::EventHandler(this, &processes::processes_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/**********************************************************************************************//**
	 * @fn	System::Void processes::processes_Load(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Invoked when the winform has loaded.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void processes_Load(System::Object^ sender, System::EventArgs^ e) {
		GetProcessList();
		//this->ProcessList->Columns[1]->Width = -2; automatically resize columns according to their content length
	}


	/**********************************************************************************************//**
	 * @fn	System::Void processes::COLUMN_Click(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e)
	 *
	 * @brief   Triggers on  header click.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::Windows::Forms::ColumnClickEventArgs to process.
	 **************************************************************************************************/
	private: System::Void COLUMN_Click(System::Object^ sender, System::Windows::Forms::ColumnClickEventArgs^ e) {
		
		//TOFIX: to be fixed soon
		if (e->Column == lvwColumnSorter->SortColumn)
		{
			// Reverse the current sort direction for this column.
			if (lvwColumnSorter->SortOrder == SortOrder::Ascending)
			{
				lvwColumnSorter->SortOrder = SortOrder::Descending;
			}
			else
			{
				lvwColumnSorter->SortOrder = SortOrder::Ascending;
			}
		}
		else
		{
			// Set the column number that is to be sorted; default to ascending.
			lvwColumnSorter->SortColumn = e->Column;
			lvwColumnSorter->SortOrder = SortOrder::Ascending;
		}

		//// Perform the sort with these new sort options.
		this->ProcessList->Sort();

	}

	/**********************************************************************************************//**
	 * @fn	System::Void processes::ProccessList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Maybe add dynamic selection - future feature?
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void ProccessList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
    

	/**********************************************************************************************//**
	 * @fn	System::Void processes::REFRESH_Click(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	When refresh button is clicked refresh Processes.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void REFRESH_Click(System::Object^ sender, System::EventArgs^ e) {
		this->ProcessList->Items->Clear();
		GetProcessList();
	}

	/**********************************************************************************************//**
	 * @fn	System::Void processes::SELECT_Click(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Triggered when the Select button is clicked.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void SELECT_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ProcessList->SelectedItems->Count > 0)
		{
			this->mainForm->ProcName->Text = ProcessList->SelectedItems[0]->SubItems[0]->Text;
			this->Close();
		}
		else {
			Utils::msgBox("Please select a process.");
		}
	}
  };
}
