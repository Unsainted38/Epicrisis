#include "MainWindow.h"

using namespace unsaintedWinApp;
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args) {

	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::EnableVisualStyles();
    
	MainWindow form;
	System::Windows::Forms::Application::Run(% form);
}
