#include "DB_HelperWrapper.h"
//#include <msclr/marshal_cppstd.h>
#include "MyMarshallingClass.h"

//using namespace msclr::interop;

namespace unsaintedWinApp {

    DB_HelperWrapper::DB_HelperWrapper(String^ dbPath) {
        string dbPathStr = ConvertSystemStringToStdString(dbPath);
        //string dbPathStr = marshal_as<string>(dbPath);
        nativeHelper = new DB_Helper(dbPathStr);
    }

    DB_HelperWrapper::~DB_HelperWrapper() {
        this->!DB_HelperWrapper(); // явный вызов финализатора
    }

    DB_HelperWrapper::!DB_HelperWrapper() {
        delete nativeHelper;
        nativeHelper = nullptr;
    }

    List<String^>^ DB_HelperWrapper::PopulateComboBox(String^ table, String^ column)
    {
        string nativeTable = ConvertSystemStringToStdString(table);
        string nativeColumn = ConvertSystemStringToStdString(column);
        vector<string> nativeItems = nativeHelper->GetColumnData(nativeTable, nativeColumn);
        List<String^>^ managedItems = gcnew List<String^>();
        for (const string& item : nativeItems) {
            managedItems->Add(gcnew String(item.c_str()));
        }
        return managedItems;
    }
}


