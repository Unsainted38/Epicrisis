#include "MainWindow.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace unsaintedWinApp;

[STAThreadAttribute]
int main(array<String^>^ args) {
	
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MainWindow form;
	Application::Run(% form);
}
