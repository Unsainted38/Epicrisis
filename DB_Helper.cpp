#include "DB_Helper.h"
namespace unsaintedWinApp {
    DB_Helper::DB_Helper(String^ dbPath)
    {
        connectionString = "Data Source=" + dbPath + ";Version=3;";
    }
    DB_Helper::~DB_Helper()
    {
    }
    // Функция создает строку sql запроса с условием подходящего id таблицы 
    String^ DB_Helper::SetQueryById(String^ table, String^ column, int id)
    {
        tmp_column = column;
        tmp_table = table;
        tmp_query = " SELECT DISTINCT " + column +
                " FROM " + table + " WHERE id = " + id;
        
        return tmp_query;
    }
    // Функция создает строку sql запроса с условием подходящего title таблицы 
    String^ DB_Helper::SetQueryByTitle(String^ table, String^ column, String^ title)
    {
        tmp_column = column;
        tmp_table = table;
        tmp_query = " SELECT DISTINCT " + column +
            " FROM " + table + " WHERE title = " + title;

        return tmp_query;
    }
    // Функция 
    String^ DB_Helper::SetQueryByCondition(String^ table, String^ column, String^ conditionColumn, String^ conditionValue, DataFormat format)
    {
        String^ result = gcnew String("");
        if (table == "" || column == "" || conditionColumn == "" || conditionValue == "") {
            return result;
        }
        tmp_column = column;
        tmp_table = table;
        tmp_query = " SELECT DISTINCT " + column +
            " FROM " + table + " WHERE " + conditionColumn + " = " + "'" + conditionValue + "'";
        switch (format)
        {
        case DataFormat::JSON:
            return GetJsonString();
            break;
        case DataFormat::String:
            
            break;
        case DataFormat::ListStr:
            break;
        default:
            break;
        }
        return result;
    }
    // Функция создает строку sql запроса с условием подходящего значения выбранного столбца и выполняет его
    // Возвращает полученные значения в виде списка строк 
    List<String^>^ DB_Helper::SetQueryByCondition(String^ table, String^ column, String^ conditionColumn, String^ conditionValue)
    {
        if (table == "" || column == "" || conditionColumn == "" || conditionValue == "") {
            List<String^>^ result = gcnew List<String^>();
            result->Add("");
            return result;

        }
        tmp_column = column;
        tmp_table = table;
        tmp_query = " SELECT DISTINCT " + column +
            " FROM " + table + " WHERE " + conditionColumn + " = " + "'" + conditionValue + "'";
        
        return GetColumnData();
    }
    // Функция извлекает строку в формате json из таблицы
    String^ DB_Helper::GetJsonString()
    {
        SQLiteConnection^ connection = gcnew SQLiteConnection(connectionString);
        String^ jsonData;
        try {
            connection->Open();
            SQLiteCommand^ cmd = gcnew SQLiteCommand(tmp_query, connection);
            SQLiteDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                jsonData = reader[tmp_column]->ToString();
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error: " + ex->Message);
            return jsonData;
        }
        finally {
            connection->Close();
        }
        tmp_column = "";
        tmp_query = "";
        tmp_table = "";
        return jsonData;
    }
    // Функция создает tmp_query типа "SELECT DISTINCT column FROM table WHERE conditionalColumn LIKE 'conditionValue%'"
    List<String^>^ DB_Helper::SetQueryByConditionLike(String^ table, String^ column, String^ conditionColumn, String^ conditionValue)
    {
        List<String^>^ result;
        if (table == "" || column == "" || conditionColumn == "" || conditionValue == "") {
            result = gcnew List<String^>();
            result->Add("");
            return result;
        }
        tmp_column = column;
        tmp_table = table;
        tmp_query = " SELECT DISTINCT " + column +
            " FROM " + table + " WHERE " + conditionColumn + " LIKE " + "'" + conditionValue + "%" + "'";

        return GetColumnData();
    }
    // Функция выполняет sql запрос tmp_query, которую надо предварительно инициализировать
    // Возвращает список строк из колонки таблицы
    List<String^>^ DB_Helper::GetColumnData()
    {
        List<String^>^ results = gcnew List<String^>();

        SQLiteConnection^ connection = gcnew SQLiteConnection(connectionString);
        try
        {
            connection->Open();


            SQLiteCommand^ command = gcnew SQLiteCommand(tmp_query, connection);
            SQLiteDataReader^ reader = command->ExecuteReader();

            while (reader->Read())
            {
                results->Add(reader[tmp_column]->ToString());
            }

            reader->Close();
        }
        catch (Exception^ ex)
        {
            Console::WriteLine("Error: " + ex->Message);
        }
        finally
        {
            connection->Close();
        }
        tmp_column = "";
        tmp_query = "";
        tmp_table = "";
        if (results->Count == 0) results->Add("");
        return results;
    }
    // Функция извлекает данные из столбца(columnName) таблицы(tableName) и возвращает список строк.
    List<String^>^ DB_Helper::GetColumnData(String^ tableName, String^ columnName)
    {
        List<String^>^ results = gcnew List<String^>();

        SQLiteConnection^ connection = gcnew SQLiteConnection(connectionString);
        try
        {
            connection->Open();

            String^ query = " SELECT DISTINCT " + columnName +
                " FROM " + tableName;
                            

            SQLiteCommand^ command = gcnew SQLiteCommand(query, connection);
            SQLiteDataReader^ reader = command->ExecuteReader();
            
            while (reader->Read())
            {
                results->Add(reader[columnName]->ToString());
            }

            reader->Close();
        }
        catch (Exception^ ex)
        {
            Console::WriteLine("Error: " + ex->Message);
        }
        finally
        {
            connection->Close();
        }
        tmp_column = "";
        tmp_query = "";
        tmp_table = "";
        return results;
    }
    // Функция возвращает отсортированный список строк по убыванию или возрастанию
    List<String^>^ DB_Helper::GetSortedColumnData(String^ tableName, String^ columnName, int sortOrder)
    {
        List<String^>^ results = gcnew List<String^>();

        SQLiteConnection^ connection = gcnew SQLiteConnection(connectionString);
        try
        {
            connection->Open();
            String^ query;
            switch (sortOrder) {
            case 0:
                query = " SELECT DISTINCT " + columnName +
                    " FROM " + tableName;
                break;
            case 1:
                query = " SELECT DISTINCT " + columnName +
                    " FROM " + tableName +
                    " ORDER BY " + columnName + " ASC ";
                break;
            case 2:
                query = " SELECT DISTINCT " + columnName +
                    " FROM " + tableName +
                    " ORDER BY " + columnName + " DESC ";
                break;
            default:
                break;
            }


            SQLiteCommand^ command = gcnew SQLiteCommand(query, connection);
            SQLiteDataReader^ reader = command->ExecuteReader();

            while (reader->Read())
            {
                results->Add(reader[columnName]->ToString());
            }

            reader->Close();
        }
        catch (Exception^ ex)
        {
            Console::WriteLine("Error: " + ex->Message);
        }
        finally
        {
            connection->Close();
        }
        tmp_column = "";
        tmp_query = "";
        tmp_table = "";
        return results;
    }
    String^ DB_Helper::GetMinMaxColumnData(String^ table, String^ column, MinMax min_max)
    {
        SQLiteConnection^ connection = gcnew SQLiteConnection(connectionString);
        String^ Data;
        
        tmp_table = table;
        switch (min_max)
        {
        case unsaintedWinApp::MinMax::Min:
            tmp_query = "SELECT DISTINCT MIN(" + column + ")" + " FROM " + table;
            tmp_column = "MIN(" + column + ")";
            break;
        case unsaintedWinApp::MinMax::Max:
            tmp_query = "SELECT DISTINCT MAX(" + column + ")" + " FROM " + table;
            tmp_column = "MAX(" + column + ")";
            break;
        default:
            break;
        }
        
        try {
            connection->Open();
            SQLiteCommand^ cmd = gcnew SQLiteCommand(tmp_query, connection);
            SQLiteDataReader^ reader = cmd->ExecuteReader();

            if (reader->Read()) {
                Data = reader[tmp_column]->ToString();
            }
            reader->Close();
        }
        catch (Exception^ ex) {
            Console::WriteLine("Error: " + ex->Message);
            return Data;
        }
        finally {
            connection->Close();
        }
        tmp_column = "";
        tmp_query = "";
        tmp_table = "";
        return Data;
    }
};