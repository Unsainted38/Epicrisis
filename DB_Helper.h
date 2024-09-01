#pragma once


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SQLite;

namespace unsaintedWinApp {
    enum class DataFormat {
        JSON,
        String,
        ListStr,
    };

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
        String^ SetQueryByTitle(String^ talble, String^ column, String^ title);
        String^ SetQueryByCondition(String^ table, String^ column, String^ conditionColumn, String^ conditionValue, DataFormat format);
        List<String^>^ SetQueryByConditionLike(String^ table, String^ column, String^ conditionColumn, String^ conditionValue);
        //Void SetQueryByCondition(String^ table, String^ column, String^ conditionColumn, String^ conditionValue, DataFormat format);
        List<String^>^ SetQueryByCondition(String^ table, String^ column, String^ conditionColumn, String^ conditionValue);
        String^ GetJsonString();

        List<String^>^ GetColumnData();
        List<String^>^ GetColumnData(String^ tableName, String^ columnName);
        List<String^>^ GetSortedColumnData(String^ tableName, String^ columnName, int sortType);

        
    };
}