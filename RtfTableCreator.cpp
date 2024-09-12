#include "RtfTableCreator.h"


void GenerateRTFAndDisplay(String^ json)
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
                            if (child->Bold.HasValue && child->Bold.Value)
                            {
                                rtfBuilder->Append(R"(\b )");
                            }
                            if (child->Underline.HasValue && child->Underline.Value)
                            {
                                rtfBuilder->Append(R"(\ul )");
                            }
                            if (child->FontSize.HasValue)
                            {
                                rtfBuilder->Append(R"(\fs)" + (child->FontSize.Value * 2) + " ");
                            }

                            if (child->Text)
                            {
                                rtfBuilder->Append(child->Text);
                            }

                            // Окончание форматирования текста
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
                            rtfBuilder->Append(R"(\row)");  // Начало строки

                            if (row->Children)
                            {
                                for each (TableCell ^ cell in row->Children)
                                {
                                    if (cell)
                                    {
                                        rtfBuilder->Append(R"(\cell)");  // Ячейка

                                        if (cell->Children)
                                        {
                                            //for each (Paragraph ^ para in cell->Children)
                                            //{
                                            //    if (para)
                                            //    {
                                            //        if (para->Children)
                                            //        {
                                            //            for each (Child ^ paraChild in para->Children)
                                            //            {
                                            //                if (paraChild && paraChild->Text)
                                            //                {
                                            //                    rtfBuilder->Append(paraChild->Text);
                                            //                }
                                            //            }
                                            //        }
                                            //        rtfBuilder->Append(R"(\par )");
                                            //    }
                                            //}
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
    Console::WriteLine(rtfBuilder->ToString());
    //richTextBox->Rtf = rtfBuilder->ToString();
}
void CreateTableInRichTextBox(RichTextBox^ richTextBox) {
    // Пример RTF для создания таблицы с 2 строками и 3 столбцами
    String^ rtfTable = R"(
    {\rtf1\ansi \trowd \cellx2000 \cellx4000 \cellx6000 \intbl A1\cell B1\cell C1\cell \row \trowd \cellx2000 \cellx4000 \cellx6000 \intbl A2\cell B2\cell C2\cell \row \pard})";

    // Задаем RTF для RichTextBox
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
                                    Child^ m_child = GetChildKeys(child);
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
                                                Child^ m_child = GetChildKeys(child);
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
                                                Child^ m_child = GetChildKeys(child);
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
                                                Child^ m_child = GetChildKeys(child);
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
                                                Child^ m_child = GetChildKeys(child);
                                                
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
                }
            }
        }
    }
    rtfBuilder->Append(R"(})");
    richTextBox->Rtf = rtfBuilder->ToString();
}
String^ DeserializeTable(Table^ table) {
    StringBuilder^ rtfBuilder = gcnew StringBuilder();
    rtfBuilder->Append(R"({\rtf1\ansi\deff0)");
    


}

Child^ GetChildKeys(JObject^ child) {
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