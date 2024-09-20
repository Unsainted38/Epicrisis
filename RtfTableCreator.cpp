#include "RtfTableCreator.h"


void GenerateRTFAndDisplay(String^ json, RichTextBox^ richTextBox)
{
    List<JObject^>^ elements = JsonConvert::DeserializeObject<List<JObject^>^>(json);

    StringBuilder^ rtfBuilder = gcnew StringBuilder();
    rtfBuilder->Append(R"({\rtf1\ansi\deff0)");  // Начало RTF документа

    for each (JObject ^ element in elements)
    {
        String^ type = element["type"]->ToString();

        if (type == "paragraph")
        {
            Paragraph^ paragraph = JsonConvert::DeserializeObject<Paragraph^>(element->ToString());

            if (paragraph)
            {
                if (!String::IsNullOrEmpty(paragraph->Align) && paragraph->Align == "center")
                {
                    rtfBuilder->Append(R"(\qc )");
                }

                if (paragraph->Children)
                {
                    for each (Child ^ child in paragraph->Children)
                    {
                        if (child)
                        {
                            if (child->Bold.HasValue && child->Bold)
                            {
                                rtfBuilder->Append(R"(\b )");
                            }
                            if (child->Underline.HasValue && child->Underline)
                            {
                                rtfBuilder->Append(R"(\ul )");
                            }
                            if (child->FontSize.HasValue)
                            {
                                rtfBuilder->Append(R"(\fs)" + (child->FontSize.Value * 2) + " ");
                            }
                            if (child->Anchor.HasValue && child->Anchor)
                            {
                                //rtfBuilder->Append();
                            }

                            if (child->Text)
                            {
                                rtfBuilder->Append(child->Text);
                            }

                            // Окончание форматирования текста
                            if (child->Anchor.HasValue && child->Anchor)
                            {
                                //rtfBuilder->Append();
                            }
                            if (child->Bold.HasValue && child->Bold.Value)
                            {
                                rtfBuilder->Append(R"(\b0 )");
                            }
                            if (child->Underline.HasValue && child->Underline.Value)
                            {
                                rtfBuilder->Append(R"(\ul0 )");
                            }
                        }
                    }
                }
                // Параграф завершен
                rtfBuilder->Append(R"(\par )");
            }
        }
        else if (type == "table")
        {
            Table^ table = JsonConvert::DeserializeObject<Table^>(element->ToString());

            if (table)
            {
                rtfBuilder->Append(R"(\trowd\trgaph108)");  // Начало таблицы

                // Установите ширину столбцов, добавьте ее в ртф код
                int columnWidth = 1000; // Можно задать подходящее значение ширины столбцов
                if (table->Columns)
                {
                    for each (Column ^ column in table->Columns)
                    {
                        rtfBuilder->Append(R"(\cellx)" + (columnWidth * (table->Columns->IndexOf(column) + 1)));
                    }
                }

                if (table->Children)
                {
                    for each (TableRow ^ row in table->Children)
                    {
                        if (row)
                        {
                            rtfBuilder->Append(R"(\trowd)");  // Начало строки

                            if (row->Children)
                            {
                                for each (TableCell ^ cell in row->Children)
                                {
                                    if (cell)
                                    {
                                        rtfBuilder->Append(R"(\cell)");  // Ячейка

                                        if (cell->Paragraphs)
                                        {
                                            for each (Paragraph ^ para in cell->Paragraphs)
                                            {
                                                if (para)
                                                {
                                                    if (para->Children)
                                                    {
                                                        for each (Child ^ paraChild in para->Children)
                                                        {
                                                            if (paraChild && paraChild->Text)
                                                            {
                                                                rtfBuilder->Append(paraChild->Text);
                                                            }
                                                        }
                                                    }
                                                    rtfBuilder->Append(R"(\par )");
                                                }
                                            }
                                        }
                                        else if (cell->Children)
                                        {
                                            for each (Child ^ child in cell->Children)
                                            {
                                                if (child && child->Text)
                                                {
                                                    rtfBuilder->Append(child->Text);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                rtfBuilder->Append(R"(\pard)");  // Завершение таблицы
            }
        }
    }

    rtfBuilder->Append(R"(})");  // Завершение RTF документа
    //Console::WriteLine(rtfBuilder->ToString());
    String^ str = rtfBuilder->ToString();
    richTextBox->Rtf = rtfBuilder->ToString();
}
void CreateTableInRichTextBox(RichTextBox^ richTextBox) {
    // Пример RTF для создания таблицы с 2 строками и 3 столбцами
    String^ rtfTable = R"(
    {\rtf1\ansi\deff0 \trowd \cellx2000 \cellx4000 \cellx6000 \intbl A1\cell B1\cell C1\cell \row \trowd \cellx2000 \cellx4000 \cellx6000 \intbl A2\cell B2\cell C2\cell \row \pard})";

    // Задаем RTF для RichTextBox
    richTextBox->Clear();
    richTextBox->Rtf = rtfTable;
}
void JsonParsingTest(String^ json, RichTextBox^ richTextBox) {

    StringBuilder^ rtfBuilder = gcnew StringBuilder();
    rtfBuilder->Append(R"({\rtf1\ansi\deff0)");

    List<JObject^>^ items = JsonConvert::DeserializeObject<List<JObject^>^>(json);

    for each (JObject ^ item in items) {
        //String^ id = item["id"]->ToString();
        //String^ title = item["title"]->ToString();
        //String^ position = item["position"]->ToString();
        List<JObject^>^ values = JsonConvert::DeserializeObject<List<JObject^>^>(item["value"]->ToString());
        for each (JObject^ value in values) {
            String^ type;
            String^ align;
            if (value["type"]) type = value["type"]->ToString();
            List<JObject^>^ children = JsonConvert::DeserializeObject<List<JObject^>^>(value["children"]->ToString());
            if (value["align"]) align = value["align"]->ToString();
            if (align == "center") {
                rtfBuilder->Append(R"(\qc )");
            }
            if (type == "paragraph") {
                for each (JObject ^ child in children) {
                    if (!child["type"]) {
                        if (child["type"]->ToString() == "dateInput") {
                            if (!child["inline"])
                                rtfBuilder->Append(child["inline"]);
                            if (!child["children"]) {
                                List<JObject^>^ children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                for each (JObject ^ child in children) {
                                    if (child["text"]) {
                                        rtfBuilder->Append(child["text"]->ToString());
                                    }
                                }
                            }
                            if (!child["fontSize"]) {
                                rtfBuilder->Append(R"(\fs)" + (child["fontSize"]->ToObject<int>() * 2) + " ");
                            }
                            if (!child["value"]) {
                                rtfBuilder->Append(child["value"]->ToString());
                            }
                        }   
                    }
                    else {                      
                        if (!child["bold"])
                            rtfBuilder->Append(R"(\b )");
                        if (!child["underline"])
                            rtfBuilder->Append(R"(\ul )");
                        if (!child["fontSize"])
                            rtfBuilder->Append(R"(\fs)" + (child["fontSize"]->ToObject<int>() * 2) + " ");
                        if (!child["text"])
                            rtfBuilder->Append(child["text"]->ToString());
                        if (!child["bold"])
                            rtfBuilder->Append(R"(\b0 )");
                        if (!child["underline"])
                            rtfBuilder->Append(R"(\ul0 )");
                    }
                    
                }
                rtfBuilder->Append(R"(\par )");
                Console::WriteLine(rtfBuilder);
            }
            else if (type == "table") {

            }
        }
        
    }
    rtfBuilder->Append(R"(})");
    richTextBox->Rtf = rtfBuilder->ToString();
}
void AnalyzesParser(String^ json, RichTextBox^ richTextBox) {
    StringBuilder^ rtfBuilder = gcnew StringBuilder();
    rtfBuilder->Append(R"({\rtf1\ansi\deff0)");

    List<JObject^>^ items = JsonConvert::DeserializeObject<List<JObject^>^>(json);

    for each (JObject^ item in items) {
        String^ type;
        String^ align;

        if (item->ContainsKey("type"))
            type = item["type"]->ToString();    
        List<JObject^>^ children = JsonConvert::DeserializeObject<List<JObject^>^>(item["children"]->ToString());

        if (item->ContainsKey("align"))
            align = item["align"]->ToString();

        if (align == "center") {
            rtfBuilder->Append(R"(\qc )");
        }
        if (type == "paragraph") {
            for each (JObject ^ child in children) {
                if (child->ContainsKey("type")) {
                    if (child["type"]->ToString() == "dateInput") {
                        if (child->ContainsKey("inline"))
                            rtfBuilder->Append(child["inline"]);
                        if (child->ContainsKey("children")) {
                            List<JObject^>^ children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                            for each (JObject ^ child in children) {
                                if (child->ContainsKey("text")) {
                                    rtfBuilder->Append(child["text"]->ToString());
                                }
                            }
                        }
                        if (child->ContainsKey("fontSize")) {
                            rtfBuilder->Append(R"(\fs)" + (child["fontSize"]->ToObject<int>() * 2) + " ");
                        }
                        if (child->ContainsKey("value")) {
                            rtfBuilder->Append(child["value"]->ToString());
                        }
                    }   
                }
                else {                      
                    if (child->ContainsKey("bold"))
                        rtfBuilder->Append(R"(\b )");
                    if (child->ContainsKey("underline"))
                        rtfBuilder->Append(R"(\ul )");
                    if (child->ContainsKey("fontSize"))
                        rtfBuilder->Append(R"(\fs)" + (child["fontSize"]->ToObject<int>() * 2) + " ");
                    if (child->ContainsKey("text"))
                        rtfBuilder->Append(child["text"]->ToString());
                    if (child->ContainsKey("bold"))
                        rtfBuilder->Append(R"(\b0 )");
                    if (child->ContainsKey("underline"))
                        rtfBuilder->Append(R"(\ul0 )");
                }
                
            }
            rtfBuilder->Append(R"(\par )");
            Console::WriteLine(rtfBuilder);
        }
        else if (type == "table") {
            Table^ m_table = gcnew Table();
            List<JObject^>^ columns;
            List<JObject^>^ children;
            if (item->ContainsKey("column")) {
                columns = JsonConvert::DeserializeObject<List<JObject^>^>(item["columns"]->ToString());
                m_table->Columns = gcnew List<Column^>();
                for each (JObject ^ column in columns) {
                    Column^ m_column = gcnew Column();
                    String^ type;
                    String^ title;
                    if (column->ContainsKey("type"))
                        type = column["type"]->ToString();
                    if (column->ContainsKey("title"))
                        title = column["title"]->ToString();
                    m_column->Title = title;
                    m_column->Type = type;
                    m_table->Columns->Add(m_column);
                }
            }
            if (item->ContainsKey("children")) {
                children = JsonConvert::DeserializeObject<List<JObject^>^>(item["children"]->ToString());
                m_table->Children = gcnew List<TableRow^>();
                for each (JObject ^ child in children) {
                    String^ type;
                    List<JObject^>^ children;
                    TableRow^ m_tableRow = gcnew TableRow();
                    m_tableRow->Children = gcnew List<TableCell^>();
                    if (child->ContainsKey("type"))
                        type = child["type"]->ToString();
                    m_tableRow->Type = type;
                    
                    if (type == "tableRow") {
                        children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                        
                        for each (JObject ^ child in children) {
                            TableCell^ m_tableCell = gcnew TableCell();
                            
                            int fontSize = 9 * 2;
                            String^ type;
                            List<JObject^>^ children;
                            if (child->ContainsKey("type"))
                                type = child["type"]->ToString();
                            m_tableCell->Type = type;
                            if (type == "tableHeaderCell") {
                            
                                children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                m_tableCell->Children = gcnew List<Child^>();
                                for each (JObject ^ child in children) {
                                    Child^ m_child = GenerateChild(child);
                                    if (m_child->Bold)
                                        rtfBuilder->Append(R"(\b )");
                                    if (m_child->Underline)
                                        rtfBuilder->Append(R"(\ul )");
                                    rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                    rtfBuilder->Append(m_child->Text);
                                    rtfBuilder->Append(R"(\b0 )");
                                    rtfBuilder->Append(R"(\ul0 )");
                                    rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                    m_tableCell->Children->Add(m_child);
                                }
                            }
                            else if (type == "tableDataCell") {
                                String^ columnType;
                                List<JObject^>^ children;
                                m_tableCell->Paragraphs = gcnew List<Paragraph^>();
                                if (child->ContainsKey("columnType"))
                                    columnType = child["columnType"]->ToString();
                                m_tableCell->ColumnType = columnType;
                                if (columnType == "date") {
                                    children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                    for each (JObject ^ child in children) {
                                        String^ type;
                                        List<JObject^>^ children;
                                        Paragraph^ m_paragraph = gcnew Paragraph();
                                        m_paragraph->Children = gcnew List<Child^>();
                                        if (child->ContainsKey("type"))
                                            type = child["type"]->ToString();
                                        m_paragraph->Type = type;
                                        if (type == "dateInput") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                if (m_child->Bold)
                                                    rtfBuilder->Append(R"(\b )");
                                                if (m_child->Underline)
                                                    rtfBuilder->Append(R"(\ul )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                rtfBuilder->Append(m_child->Text);
                                                rtfBuilder->Append(R"(\b0 )");
                                                rtfBuilder->Append(R"(\ul0 )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        else if (type == "paragraph") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                if (m_child->Bold)
                                                    rtfBuilder->Append(R"(\b )");
                                                if (m_child->Underline)
                                                    rtfBuilder->Append(R"(\ul )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                rtfBuilder->Append(m_child->Text);
                                                rtfBuilder->Append(R"(\b0 )");
                                                rtfBuilder->Append(R"(\ul0 )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        m_tableCell->Paragraphs->Add(m_paragraph);
                                    }
                                }
                                else if (columnType == "text") {
                                    children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                    for each (JObject ^ child in children) {
                                        String^ type;
                                        List<JObject^>^ children;
                                        Paragraph^ m_paragraph = gcnew Paragraph();
                                        m_paragraph->Children = gcnew List<Child^>();
                                        if (child->ContainsKey("type"))
                                            type = child["type"]->ToString();
                                        m_paragraph->Type = type;
                                        if (type == "dateInput") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                if (m_child->Bold)
                                                    rtfBuilder->Append(R"(\b )");
                                                if (m_child->Underline)
                                                    rtfBuilder->Append(R"(\ul )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                rtfBuilder->Append(m_child->Text);
                                                rtfBuilder->Append(R"(\b0 )");
                                                rtfBuilder->Append(R"(\ul0 )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        else if (type == "paragraph") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                
                                                if (m_child->Bold)
                                                    rtfBuilder->Append(R"(\b )");
                                                if (m_child->Underline)
                                                    rtfBuilder->Append(R"(\ul )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                rtfBuilder->Append(m_child->Text);
                                                rtfBuilder->Append(R"(\b0 )");
                                                rtfBuilder->Append(R"(\ul0 )");
                                                rtfBuilder->Append(R"(\fs)" + m_child->FontSize + " ");
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        m_tableCell->Paragraphs->Add(m_paragraph);
                                    }
                                    
                                }
                            }
                            m_tableRow->Children->Add(m_tableCell);
                        }
                    }
                    m_table->Children->Add(m_tableRow);
                    //rtfBuilder->Append(CreateTable(m_table));
                }
            }
        }
    }
    rtfBuilder->Append(R"(})");
    richTextBox->Rtf = rtfBuilder->ToString();
}

Child^ GenerateChild(JObject^ child) {
    Child^ m_child = gcnew Child();
    bool bold = false;
    bool underline = false;
    bool anchor = false;
    bool inLine = false;
    int fontSize = 9 * 2;
    String^ text = "";
    if (child->ContainsKey("bold"))
        bold = child["bold"]->ToObject<bool>();
    if (child->ContainsKey("text"))
        text = child["text"]->ToString();
    if (child->ContainsKey("underline"))
        underline = child["underline"]->ToObject<bool>();    
    if (child->ContainsKey("fontSize"))
        fontSize = child["fontSize"]->ToObject<int>() * 2;
    if (child->ContainsKey("anchor"))
        anchor = child["anchor"]->ToObject<bool>();
    if (child->ContainsKey("inline"))
        inLine = child["inline"]->ToObject<bool>();

    m_child->Bold = bold;
    m_child->FontSize = fontSize;
    m_child->Underline = underline;
    m_child->Text = text;
    m_child->Inline = inLine;
    m_child->Anchor = anchor;
    return m_child;
}
Parser^ ConvertJsonToParser(String^ json) {
    Parser^ parser = gcnew Parser();
    parser->DeserializedItems = gcnew List<Object^>();
    List<JObject^>^ items = JsonConvert::DeserializeObject<List<JObject^>^>(json);

    for each (JObject ^ item in items) {
        String^ type;
        String^ align;
        if (item->ContainsKey("type"))
            type = item["type"]->ToString();
        if (item->ContainsKey("align"))
            align = item["align"]->ToString();
        if (type == "paragraph") {
            Paragraph^ m_paragraph = gcnew Paragraph();
            List<JObject^>^ children;
            m_paragraph->Type = type;
            m_paragraph->Align = align;
            if (item->ContainsKey("children")) {
                m_paragraph->Children = gcnew List<Child^>();
                children = JsonConvert::DeserializeObject<List<JObject^>^>(item["children"]->ToString());
                for each (JObject ^ child in children) {
                    Child^ m_child = GenerateChild(child);
                    m_paragraph->Children->Add(m_child);
                }
            }
            parser->DeserializedItems->Add(m_paragraph);
        }
        else if (type == "table") {
            Table^ m_table = gcnew Table();
            List<JObject^>^ columns;
            List<JObject^>^ children;
            if (item->ContainsKey("columns")) {
                columns = JsonConvert::DeserializeObject<List<JObject^>^>(item["columns"]->ToString());
                m_table->Columns = gcnew List<Column^>();
                for each (JObject ^ column in columns) {
                    Column^ m_column = gcnew Column();
                    String^ type;
                    String^ title;
                    if (column->ContainsKey("type"))
                        type = column["type"]->ToString();
                    if (column->ContainsKey("title"))
                        title = column["title"]->ToString();
                    m_column->Title = title;
                    m_column->Type = type;
                    m_table->Columns->Add(m_column);
                }
            }
            if (item->ContainsKey("children")) {
                children = JsonConvert::DeserializeObject<List<JObject^>^>(item["children"]->ToString());
                m_table->Children = gcnew List<TableRow^>();
                for each (JObject ^ child in children) {
                    String^ type;
                    List<JObject^>^ children;
                    TableRow^ m_tableRow = gcnew TableRow();
                    m_tableRow->Children = gcnew List<TableCell^>();
                    if (child->ContainsKey("type"))
                        type = child["type"]->ToString();
                    m_tableRow->Type = type;

                    if (type == "tableRow") {
                        children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());

                        for each (JObject ^ child in children) {
                            TableCell^ m_tableCell = gcnew TableCell();

                            int fontSize = 9 * 2;
                            String^ type;
                            List<JObject^>^ children;
                            if (child->ContainsKey("type"))
                                type = child["type"]->ToString();
                            m_tableCell->Type = type;
                            if (type == "tableHeaderCell") {
                                children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                m_tableCell->Children = gcnew List<Child^>();
                                for each (JObject ^ child in children) {
                                    Child^ m_child = GenerateChild(child);
                                    m_tableCell->Children->Add(m_child);
                                }
                            }
                            else if (type == "tableDataCell") {
                                String^ columnType;
                                List<JObject^>^ children;
                                m_tableCell->Paragraphs = gcnew List<Paragraph^>();
                                if (child->ContainsKey("columnType"))
                                    columnType = child["columnType"]->ToString();
                                m_tableCell->ColumnType = columnType;
                                if (columnType == "date") {
                                    children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                    for each (JObject ^ child in children) {
                                        String^ type;
                                        List<JObject^>^ children;
                                        Paragraph^ m_paragraph = gcnew Paragraph();
                                        m_paragraph->Children = gcnew List<Child^>();
                                        if (child->ContainsKey("type"))
                                            type = child["type"]->ToString();
                                        m_paragraph->Type = type;
                                        if (type == "dateInput") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        else if (type == "paragraph") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        m_tableCell->Paragraphs->Add(m_paragraph);
                                    }
                                }
                                else if (columnType == "text") {
                                    children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                    for each (JObject ^ child in children) {
                                        String^ type;
                                        List<JObject^>^ children;
                                        Paragraph^ m_paragraph = gcnew Paragraph();
                                        m_paragraph->Children = gcnew List<Child^>();
                                        if (child->ContainsKey("type"))
                                            type = child["type"]->ToString();
                                        m_paragraph->Type = type;
                                        if (type == "dateInput") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        else if (type == "paragraph") {
                                            children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                            for each (JObject ^ child in children) {
                                                Child^ m_child = GenerateChild(child);
                                                m_paragraph->Children->Add(m_child);
                                            }
                                        }
                                        m_tableCell->Paragraphs->Add(m_paragraph);
                                    }

                                }
                            }
                            m_tableRow->Children->Add(m_tableCell);
                        }
                    }
                    m_table->Children->Add(m_tableRow);
                }
            }
            parser->DeserializedItems->Add(m_table);
        }
    }
    return parser;
}
String^ ConvertParserToJson(Parser^ parser)
{
    String^ json;
    json = JsonConvert::SerializeObject(parser->DeserializedItems);
    Console::WriteLine(json);
    return json;
    // TODO: вставьте здесь оператор return
}
String^ ConvertParserToRTF(Parser^ parser) {
    StringBuilder^ rtfBuilder = gcnew StringBuilder();
    rtfBuilder->Append(R"({\rtf1\ansi\deff0)");
    for each (Object ^ item in parser->DeserializedItems) {
        Type^ type = item->GetType();
        if (type->Name == "Paragraph") {
            Paragraph^ para = safe_cast<Paragraph^>(item);
            if (para->Align == "center")
                rtfBuilder->Append(R"(\qc)");
            else if (para->Align == "left")
                rtfBuilder->Append(R"(\ql)");
            else if (para->Align == "right")
                rtfBuilder->Append(R"(\qr)");
            if (para->Children) {
                for each (Child ^ child in para->Children) {
                    rtfBuilder->Append(ChildToRtf(child));
                }
            }
            rtfBuilder->Append(R"(\par\pard)");
        }
        else if (type->Name == "Table") {
            Table^ table = safe_cast<Table^>(item);
            int TotalWidth = 18800;
            if (table->Columns) {
                rtfBuilder->Append(R"(\trowd\trqc\trgaph108\trrh400\qc)");
                Dictionary<String^,int>^ widths = CalculateColumnsWidths(table->Columns, TotalWidth);
                for each (Column ^ column in table->Columns) {
                    rtfBuilder->Append(R"(\clvertalc\cellx)");
                    int width = widths[column->Title];
                    if (column->Type == "text") {
                        rtfBuilder->Append(width);
                    }
                    else if (column->Type == "date") {
                        rtfBuilder->Append(width);
                    }
                }
            }
            if (table->Children) {
                rtfBuilder->Append(R"(\intbl)");
                for each (TableRow ^ row in table->Children) {
                    if (row->Type == "tableRow") {
                        for each (TableCell ^ cell in row->Children) {
                            if (cell->Type == "tableHeaderCell") {
                                rtfBuilder->Append(R"(\b)");
                                if (cell->Children) {
                                    for each (Child ^ child in cell->Children) {
                                        rtfBuilder->Append(ChildToRtf(child));
                                    }                                
                                }
                                rtfBuilder->Append(R"(\b0\cell)");
                            }
                            else if (cell->Type == "tableDataCell") {
                                if (cell->ColumnType == "text") {
                                    for each (Paragraph ^ para in cell->Paragraphs) {
                                        if (para->Type == "paragraph") {
                                            for each (Child ^ child in para->Children) {
                                                rtfBuilder->Append(ChildToRtf(child));
                                            }
                                        }
                                        else if (para->Type == "dateInput") {
                                            // Дописать логику заполнения даты
                                            for each (Child ^ child in para->Children) {
                                                rtfBuilder->Append(ChildToRtf(child));
                                            }
                                        }
                                    }
                                }
                                rtfBuilder->Append(R"(\cell)");
                            }
                        }
                        rtfBuilder->Append(R"(\row)");
                    }                    
                }
            }
            rtfBuilder->Append(R"(\par\pard)");
        }
    }
    rtfBuilder->Append(R"(})");
    return rtfBuilder->ToString();
}

Parser^ ConvertRtfToParser(String^ rtf)
{
    Parser^ parser = gcnew Parser();
    parser->DeserializedItems = gcnew List<Object^>();
    if (rtf->Contains(RTF::BEGIN)) {
        rtf = rtf->Remove(rtf->IndexOf(RTF::BEGIN), RTF::BEGIN->Length);
        while (rtf != R"(})") {
            if (rtf->StartsWith(RTF::TABLE)) {
                Table^ table = gcnew Table();
                table->Columns = gcnew List<Column^>();
                table->Children = gcnew List<TableRow^>();
                rtf = rtf->Remove(rtf->IndexOf(RTF::TABLE), RTF::TABLE->Length);                
                while (!rtf->StartsWith(R"(\intbl)")) {
                    rtf = rtf->Remove(rtf->IndexOf(rtf->Split('\\')[1]), rtf->Split('\\')[1]->Length + 1);                   
                    rtf = rtf->Remove(rtf->IndexOf(R"(\intbl)"), R"(\intbl)"->Length);
                }

                while (!rtf->StartsWith(R"(par\pard)")) {
                    bool columnRow = true;
                    while (!rtf->StartsWith(R"(\row)")) {
                        TableRow^ row = gcnew TableRow();
                        Column^ column = gcnew Column();                        
                        if (columnRow) {
                            while (!rtf->StartsWith(R"(\cell)")) {

                            }
                            columnRow = false;
                        }
                        else {
                            while (!rtf->StartsWith(R"(\cell)")) {

                            }
                        }
                        table->Children->Add(row);
                    }
                    rtf = rtf->Remove(rtf->IndexOf(RTF::ROW), RTF::ROW->Length);
                }
                rtf = rtf->Remove(rtf->IndexOf(R"(\par\pard)"), R"(\par\pard)"->Length);
            }
            else {
                Paragraph^ para = gcnew Paragraph();
                para->Type = "paragraph";
                para->Children = gcnew List<Child^>();
                if (rtf->StartsWith(RTF::ALIGN)) {
                    rtf = rtf->Remove(rtf->IndexOf(RTF::ALIGN), RTF::ALIGN->Length);
                    if (rtf[0] == 'c')
                        para->Align = "center";
                    else if (rtf[0] == 'l')
                        para->Align = "left";
                    else if (rtf[0] == 'r')
                        para->Align = "right";
                    else if (rtf[0] == 'j')
                        para->Align = "justify";
                    rtf = rtf->Remove(0, 1);
                }
                if (rtf->Contains(R"(\def)")) {
                    while (!rtf->StartsWith(R"(\par\pard)")) {
                        Child^ child = RtfToChild(rtf);
                        rtf = RtfAfterChildGen(rtf);
                        para->Children->Add(child);
                    }
                }   
                if (rtf->Contains(RTF::PARAGRAPH_END)) {
                    rtf = rtf->Remove(rtf->IndexOf(RTF::PARAGRAPH_END), RTF::PARAGRAPH_END->Length);
                    parser->DeserializedItems->Add(para);
                }                    
            }
        }
        rtf = rtf->Remove(rtf->IndexOf(RTF::END), RTF::END->Length);
    }
    else {

        parser = nullptr;
    }

    return parser;
    // TODO: вставьте здесь оператор return
}
String^ ChildToRtf(Child^ child) {
    StringBuilder^ rtfBuilder = gcnew StringBuilder();
    int defFontSize = 11 * 2;
    if (child->Anchor.HasValue && child->Anchor)
        rtfBuilder->Append(R"()");
    if (child->Bold.HasValue && child->Bold)
        rtfBuilder->Append(R"(\b)");
    if (child->Inline.HasValue && child->Inline)
        rtfBuilder->Append(R"()");
    if (child->Underline.HasValue && child->Underline)
        rtfBuilder->Append(R"(\ul)");
    if (child->FontSize.HasValue && child->FontSize.Value > 0)
        rtfBuilder->Append(R"(\fs)" + child->FontSize + " ");
    if (child->Text)
        rtfBuilder->Append(child->Text);

    if (child->Anchor.HasValue && child->Anchor)
        rtfBuilder->Append(R"()");
    if (child->Bold.HasValue && child->Bold)
        rtfBuilder->Append(R"(\b0)");
    if (child->Inline.HasValue && child->Inline)
        rtfBuilder->Append(R"()");
    if (child->Underline.HasValue && child->Underline)
        rtfBuilder->Append(R"(\ul0)");
    if (child->FontSize.HasValue && child->FontSize.Value > 0)
        rtfBuilder->Append(R"(\fs)" + defFontSize);
    rtfBuilder->Append(R"(\def)");
    return rtfBuilder->ToString();
}
Child^ RtfToChild(String^ rtf) {
    Child^ child = gcnew Child();
    String^ defFontSize = "22";
    while (!rtf->StartsWith(RTF::CHILD_END)) {
        if (rtf->StartsWith(RTF::BOLD_START)) {
            child->Bold = true;
            rtf = rtf->Remove(rtf->IndexOf(RTF::BOLD_START), RTF::BOLD_START->Length);
        }
        if (rtf->StartsWith(RTF::UNDERLINE_START)) {
            child->Underline = true;
            rtf = rtf->Remove(rtf->IndexOf(RTF::UNDERLINE_START), RTF::UNDERLINE_START->Length);
        }
        if (rtf->StartsWith(RTF::ITALIC_START)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::ITALIC_START), RTF::ITALIC_START->Length);
        }
        if (rtf->StartsWith(RTF::FONTSIZE)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::FONTSIZE), RTF::FONTSIZE->Length);
            child->FontSize = Convert::ToInt16(rtf->Split(' ')[0]);
            rtf = rtf->Remove(rtf->IndexOf(rtf->Split(' ')[0]), (rtf->Split(' ')[0] + " ")->Length);
        }
        if (!rtf->StartsWith(RTF::BACKSLASH)) {
            child->Text = rtf->Split('\\')[0];
            rtf = rtf->Remove(rtf->IndexOf(child->Text), child->Text->Length);
        }
        else if (!child->Text){
            child->Text = "";
        }
        if (rtf->StartsWith(RTF::BOLD_END)) {
            child->Bold = true;
            rtf = rtf->Remove(rtf->IndexOf(RTF::BOLD_END), RTF::BOLD_END->Length);
        }
        if (rtf->StartsWith(RTF::UNDERLINE_END)) {
            child->Underline = true;
            rtf = rtf->Remove(rtf->IndexOf(RTF::UNDERLINE_END), RTF::UNDERLINE_END->Length);
        }
        if (rtf->StartsWith(RTF::ITALIC_END)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::ITALIC_END), RTF::ITALIC_END->Length);
        }
        if (rtf->StartsWith(RTF::FONTSIZE + defFontSize)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::FONTSIZE), (RTF::FONTSIZE + defFontSize)->Length);
            rtf = rtf->Remove(rtf->IndexOf(rtf->Split(' ')[0]), (rtf->Split(' ')[0] + " ")->Length);
        }
    }
    rtf = rtf->Remove(rtf->IndexOf(RTF::CHILD_END), RTF::CHILD_END->Length);
    return child;
}
String^ CreateRtfDocumentFromJson(String^ json) {
    String^ rtf = ConvertParserToRTF(ConvertJsonToParser(json));
    return rtf;
}
Dictionary<String^,int>^ CalculateColumnsWidths(List<Column^>^ columns, int TotalWidth) {
    Dictionary<String^,int>^ widths = gcnew Dictionary<String^,int>();

    double TotalTextLength = 0;
    double k;
    for each (Column ^ column in columns) {
        int length = column->Title->Length;
        k = K(length);
        TotalTextLength += column->Title->Length * k;
    }
    // Ширина ячеек
    int currpos = 0;
    double s = 0;
    for each (Column^ column in columns) {
        int CellTextLength = column->Title->Length;
        int CellWidth;
        int length = column->Title->Length;
        k = K(length);
        CellWidth = (k * CellTextLength / TotalTextLength) * TotalWidth;
        s += k * CellTextLength / TotalTextLength;
        if (column->Type == "date")
            currpos += CellWidth + 1000;
        else
            currpos += CellWidth;
        widths->Add(column->Title, currpos);
    }
    return widths;
}
double K(int length) {
    double k;
    if (length <= 2)
        k = 1.35;
    else if (length <= 3)
        k = 1.1;
    else if (length <= 4)
        k = 1;
    else if (length <= 5)
        k = 0.8;
    else
        k = 0.7;
    return k;
}
String^ RtfAfterChildGen(String^ rtf) {
    String^ defFontSize = "22";
    while (!rtf->StartsWith(RTF::CHILD_END)) {
        if (rtf->StartsWith(RTF::BOLD_START)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::BOLD_START), RTF::BOLD_START->Length);
        }
        if (rtf->StartsWith(RTF::UNDERLINE_START)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::UNDERLINE_START), RTF::UNDERLINE_START->Length);
        }
        if (rtf->StartsWith(RTF::ITALIC_START)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::ITALIC_START), RTF::ITALIC_START->Length);
        }
        if (rtf->StartsWith(RTF::FONTSIZE)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::FONTSIZE), RTF::FONTSIZE->Length);
            rtf = rtf->Remove(rtf->IndexOf(rtf->Split(' ')[0]), (rtf->Split(' ')[0] + " ")->Length);
        }
        if (!rtf->StartsWith(RTF::BACKSLASH)) {
            rtf = rtf->Remove(rtf->IndexOf(rtf->Split('\\')[0]), rtf->Split('\\')[0]->Length);
        }
        if (rtf->StartsWith(RTF::BOLD_END)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::BOLD_END), RTF::BOLD_END->Length);
        }
        if (rtf->StartsWith(RTF::UNDERLINE_END)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::UNDERLINE_END), RTF::UNDERLINE_END->Length);
        }
        if (rtf->StartsWith(RTF::ITALIC_END)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::ITALIC_END), RTF::ITALIC_END->Length);
        }
        if (rtf->StartsWith(RTF::FONTSIZE + defFontSize)) {
            rtf = rtf->Remove(rtf->IndexOf(RTF::FONTSIZE), (RTF::FONTSIZE + defFontSize)->Length);
            rtf = rtf->Remove(rtf->IndexOf(rtf->Split(' ')[0]), (rtf->Split(' ')[0] + " ")->Length);
        }
    }
    rtf = rtf->Remove(rtf->IndexOf(RTF::CHILD_END), RTF::CHILD_END->Length);
    return rtf;
}