#pragma once
#include <vcclr.h>

//#import "C:\Program Files (x86)\Microsoft Office\root\Office16\MSWORD.OLB" rename("ExitWindows", "WordExitWindows") rename("FindText", "WordFindText")

using namespace System;
using namespace System::Collections::Generic;
using namespace Microsoft::Office::Interop;
using namespace Microsoft::Office::Core;
using namespace Newtonsoft::Json;


namespace unsaintedWinApp {
	public ref class Word_Helper {

	public:
		Word_Helper(String^ templateFilePath, String^ outputFilePath);
		~Word_Helper();

		void InsertTableIntoTemplate(String^ json);
		void OpenDocument();

	private:
		String^ templateFile;
		String^ outputFile;
		Object^ missing = Type::Missing;

		void InsertTable(Word::Document^ doc, Dictionary<String^, Object^>^ json);
	};
}