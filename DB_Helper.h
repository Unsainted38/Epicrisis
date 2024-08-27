#pragma once


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SQLite;

namespace unsaintedWinApp {

    public ref class DB_Helper {

    private:
        String^ connectionString;
        
    public:

        DB_Helper(String^ dbPath);

        List<String^>^ GetColumnData(String^ tableName, String^ columnName);
    };
}