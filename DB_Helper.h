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
        String^ tmp_query;
        String^ tmp_table;
        String^ tmp_column;
        
    public:

        DB_Helper(String^ dbPath);
        ~DB_Helper();

        String^ SetQueryById(String^ table, String^ column, int id);
        String^ GetJsonString();

        List<String^>^ GetColumnData(String^ tableName, String^ columnName);
        List<String^>^ GetColumnData(String^ tableName, String^ columnName, int sortType);
    };
}