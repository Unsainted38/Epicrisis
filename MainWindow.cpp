#include "MainWindow.h"

using namespace unsaintedWinApp;
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args) {

	//JsonParsingTest(R"([{"id":1, "title" : "RW крови", "value" : [{"type":"paragraph", "children" : [{"text":"RW крови от ", "bold" : true, "underline" : true, "fontSize" : 11}, {"type":"dateInput","inline" : true,"children" : [{"text":""}] ,"fontSize" : 10,"value" : "2022-04-22"}, {"text":":","bold" : true,"underline" : true,"fontSize" : 11}, {"text":" Отрицательная;","fontSize" : 11}] }] , "position" : 5}])", richTextBox);
	//GenerateRTFAndDisplay(R"([{"id":1, "title" : "RW крови", "value" : [{"type":"paragraph", "children" : [{"text":"RW крови от ", "bold" : true, "underline" : true, "fontSize" : 11}, {"type":"dateInput","inline" : true,"children" : [{"text":""}] ,"fontSize" : 10,"value" : "2022-04-22"}, {"text":":","bold" : true,"underline" : true,"fontSize" : 11}, {"text":" Отрицательная;","fontSize" : 11}] }] , "position" : 5}])");
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	System::Windows::Forms::Application::EnableVisualStyles();
    
	MainWindow form;
	System::Windows::Forms::Application::Run(% form);
}
