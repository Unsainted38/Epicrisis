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
        return jsonData;
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

        return results;
    }
    List<String^>^ DB_Helper::GetColumnData(String^ tableName, String^ columnName, int sortOrder)
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

        return results;
    }
};