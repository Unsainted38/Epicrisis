#include "MainWindow.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace unsaintedWinApp;

[STAThreadAttribute]
int main(array<String^>^ args) {
	//Word_Helper^ wordApp = gcnew Word_Helper("C:\\Users\\erik\\develop\\host\\projects\\unsaintedWinApp\\Templates\\НовыйЭпикриз.doc", "C:\\Users\\erik\\develop\\host\\projects\\unsaintedWinApp\\Templates\\Тест.doc");
	//wordApp->OpenDocument();

	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::EnableVisualStyles();
    
	MainWindow form;
	System::Windows::Forms::Application::Run(% form);
}
