#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace Newtonsoft::Json;
using namespace Newtonsoft::Json::Linq;

public ref class TableTemplate {
public:
    ref class Column {
    public:
        int Width;
    };

    ref class Table {
    public:
        List<Column^>^ Columns;
        List<List<String^>^>^ Rows;
    };
};

inline TableTemplate::Table^ ParseJson(String^ json) {
    return JsonConvert::DeserializeObject<TableTemplate::Table^>(json);
}

inline String^ GenerateRtfTable(TableTemplate::Table^ table) {
    String^ rtfTable = "{\\rtf1\\ansi\n";

    for each (List<String^> ^ row in table->Rows) {
        rtfTable += "\\trowd ";
        int cellIndex = 0;
        for each (TableTemplate::Column ^ column in table->Columns) {
            rtfTable += "\\cellx" + (column->Width * (++cellIndex)).ToString() + " ";
        }

        for each (String ^ cellContent in row) {
            rtfTable += "\\intbl " + cellContent + "\\cell ";
        }

        rtfTable += "\\row\n";
    }

    rtfTable += "\\pard\n}";
    return rtfTable;
}

inline void CreateTableInRichTextBox(RichTextBox^ richTextBox, String^ json) {
    TableTemplate::Table^ table = ParseJson(json);
    String^ rtfTable = GenerateRtfTable(table);
    richTextBox->Rtf = rtfTable;
}

//int main(array<System::String^>^ args) {
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//
//    Form^ form = gcnew Form();
//    RichTextBox^ richTextBox = gcnew RichTextBox();
//    richTextBox->Dock = DockStyle::Fill;
//
//    // Пример JSON
//    String^ json = R"({
//      "columns": [
//        {"width": 2000},
//        {"width": 2000},
//        {"width": 2000}
//      ],
//      "rows": [
//        ["A1", "B1", "C1"],
//        ["A2", "B2", "C2"],
//        ["A3", "B3", "C3"]
//      ]
//    })";
//
//    // Создаем таблицу в RichTextBox по JSON шаблону
//    CreateTableInRichTextBox(richTextBox, json);
//
//    form->Controls->Add(richTextBox);
//    Application::Run(form);
//
//    return 0;
//}


