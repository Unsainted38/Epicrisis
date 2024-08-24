#include "DB_Helper.h"

bool DB_Helper::OpenDataBase(const string& dbPath)
{
    return sqlite3_open(dbPath.c_str(), &db) == SQLITE_OK;
   
}

void DB_Helper::CloseDataBase()
{
    if (db) {
        sqlite3_close(db);
    }
}

DB_Helper::DB_Helper(string dbPath)
    : db(nullptr) {
    OpenDataBase(dbPath);
}

DB_Helper::~DB_Helper() {
    CloseDataBase();
}

vector<string> DB_Helper::GetColumnData(string table, string column, int columnIndex) {
    vector<string> items;
    sqlite3_stmt* stmt;
    string query = GenerateSqlSelectQuery(table, column);
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char* text = sqlite3_column_text(stmt, columnIndex);
            if (text) {
                items.push_back(string(reinterpret_cast<const char*>(text)));
            }
        }
        sqlite3_finalize(stmt);
    }
    return items;
}

string DB_Helper::GenerateSqlSelectQuery(string table, string column) {
    string query;
    return query = "SELECT " + column + " FROM " + table;
}