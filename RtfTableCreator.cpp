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
                                            for each (Paragraph ^ para in cell->Children)
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

        if (item["type"]) type = item["type"]->ToString();
        
        List<JObject^>^ children = JsonConvert::DeserializeObject<List<JObject^>^>(item["children"]->ToString());
        
        if (item["align"]) align = item["align"]->ToString();

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
                        if (child["fontSize"]) {
                            rtfBuilder->Append(R"(\fs)" + (child["fontSize"]->ToObject<int>() * 2) + " ");
                        }
                        if (child["value"]) {
                            rtfBuilder->Append(child["value"]->ToString());
                        }
                    }   
                }
                else {                      
                    if (!child["bold"])
                        rtfBuilder->Append(R"(\b )");
                    if (child["underline"])
                        rtfBuilder->Append(R"(\ul )");
                    if (child["fontSize"])
                        rtfBuilder->Append(R"(\fs)" + (child["fontSize"]->ToObject<int>() * 2) + " ");
                    if (child["text"])
                        rtfBuilder->Append(child["text"]->ToString());
                    if (child["bold"])
                        rtfBuilder->Append(R"(\b0 )");
                    if (child["underline"])
                        rtfBuilder->Append(R"(\ul0 )");
                }
                
            }
            rtfBuilder->Append(R"(\par )");
            Console::WriteLine(rtfBuilder);
        }
        else if (type == "table") {
            List<JObject^>^ columns;
            List<JObject^>^ children;
            if (item["column"]) {
                columns = JsonConvert::DeserializeObject<List<JObject^>^>(item["columns"]->ToString());
                for each (JObject ^ column in columns) {
                    String^ type;
                    String^ title;
                    if (column["type"])
                        type = column["type"]->ToString();
                    if (column["title"])
                        title = column["title"]->ToString();
                }
            }
            if (item["children"]) {
                children = JsonConvert::DeserializeObject<List<JObject^>^>(item["children"]->ToString());
                for each (JObject ^ child in children) {
                    String^ type;
                    List<JObject^>^ children;
                    if (!child["type"])
                        type = child["type"]->ToString();
                    if (type == "tableRow") {
                        children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                        for each (JObject ^ child in children) {
                            String^ type;
                            List<JObject^>^ children;
                            if (!child["type"])
                                type = child["type"]->ToString();
                            if (type == "tableHeaderCell") {
                                children = JsonConvert::DeserializeObject<List<JObject^>^>(child["children"]->ToString());
                                for each (JObject ^ child in children) {
                                    bool bold = false;
                                    bool underline = false;
                                    int fontSize = 11;
                                    String^ text = "";
                                    if (!child["bold"])
                                        bold = child["bold"]->ToObject<bool>();
                                    if (!child["underline"])
                                        underline = child["underline"]->ToObject<bool>();
                                    if (!child["fontSize"])
                                        fontSize = child["fontSize"]->ToObject<int>();
                                    if (!child["text"])
                                        text = child["text"]->ToString();
                                    if (bold)
                                        rtfBuilder->Append(R"(\b )");
                                    if (underline)
                                        rtfBuilder->Append(R"(\ul )");
                                    rtfBuilder->Append(R"(\fs)" + fontSize.ToString() + " ");
                                    rtfBuilder->Append(child["text"]->ToString());
                                    rtfBuilder->Append(R"(\b0 )");
                                    rtfBuilder->Append(R"(\ul0 )");
                                    rtfBuilder->Append(R"(\fs)" + fontSize.ToString() + " ");
                                }
                            }
                            else if (type == "tableDataCell") {

                            }
                        }
                    }
                }
            }
        }
    }
    rtfBuilder->Append(R"(})");
    richTextBox->Rtf = rtfBuilder->ToString();
}
