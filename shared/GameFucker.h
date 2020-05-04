#pragma once

#define RELEASE //use to compile the icon

#include "./Injector/Init.hpp"
#include "./Utilities/Utils.hpp"
#include "./Utilities/variables/globals.hpp"
#include "../shared/Utilities/Sorting.hpp"

/* Required libraries to use PostMessageA */
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "shlwapi.lib")

namespace GameFuckerUI {
	//ref class processes;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/**********************************************************************************************//**
	 * @fn	BOOL WINAPI ConsoleHandler(DWORD fdwCtrlType);
	 *
	 * @brief	Handler, called when the console closes
	 *
	 * @param 	fdwCtrlType	Type of the event.
	 *
	 * @returns	A boolean value giving the console behavior.
	 **************************************************************************************************/
	BOOL WINAPI ConsoleHandler(DWORD fdwCtrlType) {
		if (fdwCtrlType == CTRL_CLOSE_EVENT) {
			std::cout << std::endl;
			return TRUE;
		}
		return FALSE;
	}


	/**********************************************************************************************//**
	 * @fn	bool checkNotAlpha(const std::string& str)
	 *
	 * @brief	Check if a string does not contain spaces, letters or numbers.
	 *
	 * @param 	str	The string to check.
	 *
	 * @returns	True if it succeeds, false if it fails.
	 **************************************************************************************************/
	bool checkNotAlpha(const std::string& str) {
		for (int i = 0; i < str.size(); i++) {
			if (!isalnum(str[i]) || !isspace(str[i])) {
				return true;
			}
		}
		return false;
	}

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ ProcName;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::IO::FileSystemWatcher^ fileSystemWatcher1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ DLL;

	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ Mmap;

	private: System::Windows::Forms::CheckBox^ Llib;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ Find;

	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::TextBox^ fullpath;
	private: System::Windows::Forms::Label^ label4;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ProcName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			this->DLL = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Llib = (gcnew System::Windows::Forms::CheckBox());
			this->Mmap = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->Find = (gcnew System::Windows::Forms::Button());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->fullpath = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// ProcName
			// 
			this->ProcName->Location = System::Drawing::Point(12, 31);
			this->ProcName->Name = L"ProcName";
			this->ProcName->Size = System::Drawing::Size(123, 20);
			this->ProcName->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"ProcName:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(30, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"DLL:";
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// DLL
			// 
			this->DLL->Location = System::Drawing::Point(12, 70);
			this->DLL->Name = L"DLL";
			this->DLL->ReadOnly = true;
			this->DLL->Size = System::Drawing::Size(123, 20);
			this->DLL->TabIndex = 4;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(141, 69);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Add_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(27, 213);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Inject";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::INJECT_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(108, 213);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"About";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::ABOUT_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(189, 213);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Discord";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::DISCORD_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(88, 242);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(118, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Made by Flickery#4969";
			// 
			// Llib
			// 
			this->Llib->AutoSize = true;
			this->Llib->Checked = true;
			this->Llib->CheckState = System::Windows::Forms::CheckState::Checked;
			this->Llib->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->Llib->Location = System::Drawing::Point(12, 96);
			this->Llib->Name = L"Llib";
			this->Llib->Size = System::Drawing::Size(48, 17);
			this->Llib->TabIndex = 10;
			this->Llib->Text = L"LLIB";
			this->Llib->UseVisualStyleBackColor = true;
			this->Llib->CheckedChanged += gcnew System::EventHandler(this, &MyForm::LLIB_CheckedChanged);
			// 
			// Mmap
			// 
			this->Mmap->AutoSize = true;
			this->Mmap->Location = System::Drawing::Point(12, 119);
			this->Mmap->Name = L"Mmap";
			this->Mmap->Size = System::Drawing::Size(56, 17);
			this->Mmap->TabIndex = 11;
			this->Mmap->Text = L"MMap";
			this->Mmap->UseVisualStyleBackColor = true;
			this->Mmap->CheckedChanged += gcnew System::EventHandler(this, &MyForm::MMAP_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(12, 142);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(58, 17);
			this->checkBox3->TabIndex = 12;
			this->checkBox3->Text = L"Debug";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::DEBUG_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(12, 165);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(109, 17);
			this->checkBox4->TabIndex = 13;
			this->checkBox4->Text = L"Close on injection";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::CLOSEOINJECT_CheckedChanged);
			// 
			// Find
			// 
			this->Find->Location = System::Drawing::Point(141, 29);
			this->Find->Name = L"Find";
			this->Find->Size = System::Drawing::Size(75, 23);
			this->Find->TabIndex = 14;
			this->Find->Text = L"Find";
			this->Find->UseVisualStyleBackColor = true;
			this->Find->Click += gcnew System::EventHandler(this, &MyForm::Find_Click);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Checked = true;
			this->checkBox5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox5->Location = System::Drawing::Point(12, 188);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(100, 17);
			this->checkBox5->TabIndex = 15;
			this->checkBox5->Text = L"Message boxes";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::MSGBOX_CheckedChanged);
			// 
			// fullpath
			// 
			this->fullpath->Location = System::Drawing::Point(141, 96);
			this->fullpath->Name = L"fullpath";
			this->fullpath->Size = System::Drawing::Size(100, 20);
			this->fullpath->TabIndex = 16;
			this->fullpath->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(272, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(28, 13);
			this->label4->TabIndex = 17;
			this->label4->Text = L"v1.2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 261);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->fullpath);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->Find);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->Mmap);
			this->Controls->Add(this->Llib);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->DLL);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ProcName);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
#ifdef RELEASE
			this->Icon = gcnew System::Drawing::Icon("your_icon_path");
#endif // DEBUG
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"遊戲混蛋";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/**********************************************************************************************//**
	 * @fn	System::Void MyForm::Find_Click(System::Object^ sender, System::EventArgs^ e);
	 *
	 * @brief	Find button click handler.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	public: System::Void Find_Click(System::Object^ sender, System::EventArgs^ e);

	/**********************************************************************************************//**
	* @fn	System::Void MyForm::Add_Click(System::Object^ sender, System::EventArgs^ e)
	*
	* @brief	When the add button is clicked, open dialog prompt.
	*
	* @param 	sender	The sender.
	* @param 	e	  	The System::EventArgs to process.
	**************************************************************************************************/
	private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e) {
		OPENFILENAME ofn;

		char file_name[100];

		ZeroMemory(&ofn, sizeof(OPENFILENAME));

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = file_name;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 100;
		ofn.lpstrFilter = "Dynamic Link Libraries (.dll)\0*.dll";
		ofn.nFilterIndex = 1;

		//open file dialog
		GetOpenFileName(&ofn);

		std::filesystem::path myFile = ofn.lpstrFile;
		std::filesystem::path fullname = myFile.filename();
		String^ filename = gcnew String(fullname.c_str());
		this->DLL->Text = filename;

		String^ full_path = gcnew String(ofn.lpstrFile);
		this->fullpath->Text = full_path;
	};

	/**********************************************************************************************//**
	* @fn	    System::Void MyForm::LLIB_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	*
	* @brief	Llib checkbox switched.
	*
	* @param 	sender	The sender.
	* @param 	e	  	The System::EventArgs to process.
	**************************************************************************************************/
	private: System::Void LLIB_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		g.llib = !g.llib;
		if (this->Llib->Checked) {
			this->Mmap->Checked = false;
		}
	}

	/**********************************************************************************************//**
	 * @fn	System::Void MyForm::MMAP_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Mmap checkbox switched.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void MMAP_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		g.mmap = !g.mmap;
		if (this->Mmap->Checked) {
			this->Llib->Checked = false;
		}
	}


	/**********************************************************************************************//**
	 * @notice  Still needs fixing, sometime does not work
	 *
	 * @fn	    System::Void MyForm::DEBUG_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Debug checkbox switched.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void DEBUG_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		//set the debug flag
		g.debug = !g.debug;
		if (this->checkBox3->Checked == true)
		{
			AllocConsole();
			freopen("CONOUT$", "w", stdout);//use cout
			std::cout << "=========== Debug mode =============" << std::endl;
			SetConsoleCtrlHandler((PHANDLER_ROUTINE)ConsoleHandler, TRUE);
		}
		else {
			g.console = GetConsoleWindow();
			if (!g.console) return;
			PostMessageA(g.console, WM_SYSCOMMAND, SC_CLOSE, 0);//send close message to the allocated console
			FreeConsole();
		}
	}


	/**********************************************************************************************//**
	 * @fn	System::Void MyForm::CLOSEOINJECT_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Close on injection checkbox handler.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void CLOSEOINJECT_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		g.closeOnInjection = !g.closeOnInjection;
	}

    
	/**********************************************************************************************//**
	 * @fn	System::Void MyForm::MSGBOX_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Msgbox checkbox handler.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void MSGBOX_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		g.msgBoxes = !g.msgBoxes;
	}

	/**********************************************************************************************//**
	 * @fn	System::Void MyForm::INJECT_Click(System::Object^ sender, System::EventArgs^ e)
	 *
	 * @brief	Inject button click handler.
	 *
	 * @param 	sender	The sender.
	 * @param 	e	  	The System::EventArgs to process.
	 **************************************************************************************************/
	private: System::Void INJECT_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context oMarshalContext;

		const char* proc = oMarshalContext.marshal_as<const char*>(this->ProcName->Text);
		const char* dll = oMarshalContext.marshal_as<const char*>(this->fullpath->Text);

		if (checkNotAlpha(proc) && checkNotAlpha(dll)) {
			g.procName = proc;
			g.dll_name = dll;
			if (g.procName != NULL && g.dll_name != NULL) {
				if (g.llib && !g.mmap) {
					Injector::Init();
				}
				else {
					Utils::error("Only LLIB injections are available at the moment.");
				}
			}
			else {
				Utils::error("Invalid process name / dll name.");
			}
		}
		else {
			Utils::error("Please enter valid process / dll name.");
		}
	}

	/* Secret Buttons */

	private: System::Void ABOUT_Click(System::Object^ sender, System::EventArgs^ e) {
		ShellExecute(NULL, "open", "https://github.com/AlexSimpler",
			NULL, NULL, SW_SHOWNORMAL);
	}

	private: System::Void DISCORD_Click(System::Object^ sender, System::EventArgs^ e) {
		ShellExecute(NULL, "open", "https://discord.gg/jDuq2rx",
			NULL, NULL, SW_SHOWNORMAL);
	}
	};
}
