#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace Newtonsoft::Json;
using namespace Newtonsoft::Json::Linq;

public ref class RTF {

public:
    static String^ BEGIN = R"({\rtf1\ansi\deff0)";
    static String^ END = R"(})";
    static String^ PARAGRAPH_BEGIN = R"()";
    static String^ PARAGRAPH_END = R"(\par\pard)";
    static String^ PARAGRAPH = "";
    static String^ TABLE = R"(\trowd\trqc\trgaph108\trrh400\qc)";
    static String^ ROW = R"(\row)";
    static String^ CELL = R"(\cell)";
    static String^ ALIGN = R"(\q)";
    static String^ CHILD_END = R"(\def)";
    static String^ BOLD_START = R"(\b)";
    static String^ BOLD_END = R"(\b0)";
    static String^ UNDERLINE_START = R"(\ul)";
    static String^ UNDERLINE_END = R"(\ul0)";
    static String^ ITALIC_START = R"(\i)";
    static String^ ITALIC_END = R"(\i0)";
    static String^ BACKSLASH = R"(\)";
    static String^ FONTSIZE = R"(\fs)";
};

public ref class Child
{
private:
    String^ text;
    Nullable<bool> underline;
    Nullable<bool> bold;
    Nullable<int> fontsize;
    Nullable<bool> inLine;
    Nullable<bool> anchor;

public:
    property String^ Text {
        void set(String^ value) {
            text = value;
        }
        String^ get() {
            return text;
        }
    }
    property Nullable<bool> Bold {
        void set(Nullable<bool> value) {
            bold = value;
        }
        Nullable<bool> get() {
            return bold;
        }
    }
    property Nullable<bool> Underline {
        void set(Nullable<bool> value) {
            underline = value;
        }
        Nullable<bool> get() {
            return underline;
        }
    }
    property Nullable<int> FontSize {
        void set(Nullable<int> value) {
            fontsize = value;
        }
        Nullable<int> get() {
            return fontsize;
        }
    }
    property Nullable<bool> Inline {
        void set(Nullable<bool> value) {
            inLine = value;
        }
        Nullable<bool> get() {
            return inLine;
        }
    }
    property Nullable<bool> Anchor {
        void set(Nullable<bool> value) {
            anchor = value;
        }
        Nullable<bool> get() {
            return anchor;
        }
    }
};

public ref class Paragraph
{
private: 
    String^ type;
    List<Child^>^ children;
    String^ align;
public:
    property String^ Type {
        void set(String^ value) {
            type = value;
        }
        String^ get() {
            return type;
        }
    }
    property List<Child^>^ Children {
        void set(List<Child^>^ value) {
            children = value;
        }
        List<Child^>^ get() {
            return children;
        }
    }
    property String^ Align {
        void set(String^ value) {
            align = value;
        }
        String^ get() {
            return align;
        }
    }

};

public ref class Column
{
private:
    String^ type;
    String^ title;
public:
    property String^ Type {
        void set(String^ value) {
            type = value;
        }
        String^ get() {
            return type;
        }
    }
    property String^ Title {
        void set(String^ value) {
            title = value;
        }
        String^ get() {
            return title;
        }
    }
};

public ref class TableCell
{
    String^ type;
    String^ columntype;
    List<Paragraph^>^ paragraphs;
    List<Child^>^ children;
public:
    property String^ Type {
        void set(String^ value) {
            type = value;
        }
        String^ get() {
            return type;
        }
    }
    property String^ ColumnType;
    property List<Paragraph^>^ Paragraphs {
        void set(List<Paragraph^>^ value) {
            paragraphs = value;
        }
        List<Paragraph^>^ get() {
            return paragraphs;
        }
    }
    property List<Child^>^ Children {
        void set(List<Child^>^ value) {
            children = value;
        }
        List<Child^>^ get() {
            return children;
        }
    }
};

public ref class TableRow
{
private: 
    String^ type;
    List<TableCell^>^ children;
public:
    property String^ Type {
        void set(String^ value) {
            type = value;
        }
        String^ get() {
            return type;
        }
    }
    property List<TableCell^>^ Children {
        void set(List<TableCell^>^ value) {
            children = value;
        }
        List<TableCell^>^ get() {
            return children;
        }
    }
};

public ref class Table
{
private:
    String^ Type;
    List<Column^>^ columns;
    List<TableRow^>^ children;
public:
    property List<Column^>^ Columns {
        void set(List<Column^>^ value) {
            columns = value;
        }
        List<Column^>^ get() {
            return columns;
        }
    }
    property List<TableRow^>^ Children {
        void set(List<TableRow^>^ value) {
            children = value;
        }
        List<TableRow^>^ get() {
            return children;
        }
    }
};
public ref class Parser {
private:
    List<Object^>^ deserializeditems;
public:
    property List<Object^>^ DeserializedItems;
    
};

void GenerateRTFAndDisplay(String^ json, RichTextBox^ richTextBox);
void CreateTableInRichTextBox(RichTextBox^ richTextBox);
Child^ GenerateChild(JObject^ child);
String^ ConvertParserToJson(Parser^ parser);
Parser^ ConvertJsonToParser(String^ json);
String^ ConvertParserToRTF(Parser^ parser);
Parser^ ConvertRtfToParser(String^ rtf);
String^ CreateRtfDocumentFromJson(String^ json);
String^ ChildToRtf(Child^ child);
Dictionary<String^, int>^ CalculateColumnsWidths(List<Column^>^ columns, int TotalWidth);
double K(int length);
Child^ RtfToChild(String^ rtf);
String^ RtfAfterChildGen(String^ rtf);