#pragma once
#include "dependencies.hpp"
#include "processes.h"
#include "GameFucker.h"

using std::cout;
using std::endl;
using std::cin;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GameFuckerUI::MyForm form;
	Application::Run(% form);

	return 0;
}
