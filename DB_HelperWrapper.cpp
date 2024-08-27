#include "DB_HelperWrapper.h"
#include <msclr/marshal_cppstd.h>
#include "MyMarshallingClass.h"

using namespace msclr::interop;

namespace unsaintedWinApp {

    DB_HelperWrapper::DB_HelperWrapper(String^ dbPath) {
        //string dbPathStr = marshal_as<string>(dbPath);
        nativeHelper = new DB_Helper(dbPath);
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
        List<String^>^ managedItems = gcnew List<String^>();
        managedItems = nativeHelper->GetColumnData(table, column);
        return managedItems;
    }
}


