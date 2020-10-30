 //     ______                          ____        _           __ 
//    / ____/________ _____ ___  ___  /  _/___    (_)__  _____/ /_
//   / /_  / ___/ __ `/ __ `__ \/ _ \ / // __ \  / / _ \/ ___/ __/
//  / __/ / /  / /_/ / / / / / /  __// // / / / / /  __/ /__/ /_  
// /_/   /_/   \__,_/_/ /_/ /_/\___/___/_/ /_/_/ /\___/\___/\__/  
                                         /___/                 
#include "../shared/dependencies/dependencies.hpp"
#include "../shared/processes.h"
#include "../shared/FrameInject.h"

using namespace System;
using namespace System::Windows::Forms;

/**********************************************************************************************//**
 * @fn	System::Void FrameInject::MyForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
 *
 * @brief	When the Find button is clicked, open the proceses winform.
 *
 * @param 	sender	The sender.
 * @param 	e	  	The System::EventArgs to process.
 **************************************************************************************************/
System::Void FrameInject::MyForm::Find_Click(System::Object^ sender, System::EventArgs^ e)
{
	FrameInject::processes^ processSelect = gcnew FrameInject::processes(this);
	processSelect->ShowDialog();
}


/**********************************************************************************************//**
 * @fn	int main(array<String^>^ args)
 *
 * @brief	Main entry-point for this application.
 *
 * @param 	args	An array of command-line argument strings.
 *
 * @returns	Exit-code for the process - 0 for success, else an error code.
 **************************************************************************************************/
[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	FrameInject::MyForm form;
	Application::Run(% form);

	return 0;
}
