#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace Newtonsoft::Json;
using namespace Newtonsoft::Json::Linq;


public ref class Child
{
public:
    property String^ Text;
    property Nullable<bool> Bold;
    property Nullable<bool> Underline;
    property Nullable<int> FontSize;
    property String^ type;
    property Nullable<bool> Inline;
};

public ref class Paragraph
{
public:
    property String^ Type;
    property List<Child^>^ Children;
    property String^ Align;
};

public ref class Column
{
public:
    property String^ Type;
    property String^ Title;
};

public ref class TableCell
{
public:
    property String^ Type;
    property String^ ColumnType;
    property List<Paragraph^>^ Children;
};

public ref class TableRow
{
public:
    property String^ Type;
    property List<TableCell^>^ Children;
};

public ref class Table
{
public:
    property String^ Type;
    property List<Column^>^ Columns;
    property List<TableRow^>^ Children;
};

void GenerateRTFAndDisplay(String^ json);
void CreateTableInRichTextBox(RichTextBox^ richTextBox);
void JsonParsingTest(String^ json, RichTextBox^ richTextBox);
void AnalyzesParser(String^ json, RichTextBox^ richTextBox);

