#pragma once
#include <vcclr.h>

using namespace System;
using namespace System::Collections::Generic;
namespace word = Microsoft::Office::Interop::Word;
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

		void InsertTable(word::Document^ doc, Dictionary<String^, Object^>^ json);
	};
}