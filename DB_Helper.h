#pragma once

#include <sqlite3.h>
#include <string>
#include <vector>
#include <stdio.h>


using namespace System;
using namespace System::Windows::Forms;
using namespace std;

public class DB_Helper {

private:    
    sqlite3* db;
    bool OpenDataBase(const string& dbPath);
    void CloseDataBase();
    
public:
    // ����������� ������
    DB_Helper(string dbPath);

    //���������� ������
    ~DB_Helper();
  

    // M���� ��� ���������� ComboBox ������� �� ������� �������
    vector<string> GetColumnData(string table, string column, int columnIndex = 0);
private:
    string GenerateSqlSelectQuery(string table, string column);
};