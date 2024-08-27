#include "DB_Helper.h"
namespace unsaintedWinApp {
    DB_Helper::DB_Helper(String^ dbPath)
    {
        connectionString = "Data Source=" + dbPath + ";Version=3;";
    }
    // Функция извлекает данные из столбца(columnName) таблицы(tableName) и возвращает список строк.
    List<String^>^ DB_Helper::GetColumnData(String^ tableName, String^ columnName)
    {
        List<String^>^ results = gcnew List<String^>();

        SQLiteConnection^ connection = gcnew SQLiteConnection(connectionString);
        try
        {
            connection->Open();

            String^ query = " SELECT " + columnName +
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
};