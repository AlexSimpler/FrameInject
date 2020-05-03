#ifndef _PROC_
#define _PROC_

#define _CRT_SECURE_NO_WARNINGS
#include "dependencies.hpp"
#include "globals.hpp"

namespace GameFuckerUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/**********************************************************************************************//**
	 * @class	processes
	 *
	 * @brief	Summary for processes
	 **************************************************************************************************/
	public ref class processes : public System::Windows::Forms::Form
	{
	private:
		MyForm^ mainForm;//Sends an error here!
	public:
		processes(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		processes(MyForm^ callingForm)
		{
			mainForm = callingForm; //to be fixed
			//mainForm->ProcName->Text;
			InitializeComponent();
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

		/* Function to display the process list */
		BOOL GetProcessList()
		{
			HANDLE hProcessSnap;
			HANDLE hProcess;
			PROCESSENTRY32 pe32;
			DWORD dwPriorityClass;

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
				String^ procName = gcnew String(pe32.szExeFile);
				std::string strPid = std::to_string(pe32.th32ProcessID);
				char const* pcstrPid = strPid.c_str();  //use char const* as target type

				String^ pid = gcnew String(pcstrPid);

				ListViewItem^ proc = gcnew ListViewItem(procName);
				proc->SubItems->Add(pid);
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
			this->SuspendLayout();
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(75, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Please select a process:";
			this->label1->Click += gcnew System::EventHandler(this, &processes::label1_Click);
			//
			// Names
			//
			this->Names->Text = L"Name";
			this->Names->Width = 241;
			//
			// Pids
			//
			this->Pids->Text = L"PID";
			//
			// ProcessList
			//
			this->ProcessList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->Names, this->Pids });
			this->ProcessList->HideSelection = false;
			this->ProcessList->Location = System::Drawing::Point(10, 25);
			this->ProcessList->Name = L"ProcessList";
			this->ProcessList->Size = System::Drawing::Size(311, 269);
			this->ProcessList->Sorting = System::Windows::Forms::SortOrder::Ascending;
			this->ProcessList->TabIndex = 0;
			this->ProcessList->UseCompatibleStateImageBehavior = false;
			this->ProcessList->View = System::Windows::Forms::View::Details;
			this->ProcessList->SelectedIndexChanged += gcnew System::EventHandler(this, &processes::ProccessList_SelectedIndexChanged);
			//
			// processes
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(333, 306);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ProcessList);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"processes";
			this->Text = L"遊戲混蛋";
			this->Load += gcnew System::EventHandler(this, &processes::processes_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ProccessList_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		/*this->mainForm->ProcName->Text = "yo";*/
	}
	private: System::Void processes_Load(System::Object^ sender, System::EventArgs^ e) {
		//here
		GetProcessList();
	}
	};
}

#endif 