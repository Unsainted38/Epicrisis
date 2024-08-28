#include "Word_Helper.h"
namespace unsaintedWinApp {
    Word_Helper::Word_Helper(String^ templateFilePath, String^ outputFilePath)
    {
        templateFile = templateFilePath;
        outputFile = outputFilePath;
    }

    Word_Helper::~Word_Helper()
    {
        
    }

    void Word_Helper::InsertTableIntoTemplate(String^ jsonData)
    {
        auto json = JsonConvert::DeserializeObject<::System::Collections::Generic::Dictionary<String^, Object^>^>(jsonData);
        auto columns = safe_cast<::System::Collections::Generic::List<String^>^>(json["columns"]);
        auto rows = safe_cast<::System::Collections::Generic::List<::System::Collections::Generic::List<Object^>^>^>(json["rows"]);

        //Application^ wordApp = gcnew Application();
        //Document^ doc = wordApp->Documents->Open(templateFile);
        //Table^ table = doc->Tables->Add(doc->Range(0, 0), rows->Count + 1, columns->Count);
    }

};