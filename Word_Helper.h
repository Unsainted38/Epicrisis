#pragma once

using namespace System;
using namespace ::System::Collections::Generic;
using namespace Microsoft::Office::Interop::Word;
using namespace Newtonsoft::Json;

namespace unsaintedWinApp {
	public ref class Word_Helper {

	public:
		Word_Helper(String^ templateFilePath, String^ outputFilePath);
		~Word_Helper();

		void InsertTableIntoTemplate(String^ json);

	private:
		String^ templateFile;
		String^ outputFile;
	};
}