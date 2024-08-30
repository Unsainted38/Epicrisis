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

            if (paragraph != nullptr)
            {
                if (!String::IsNullOrEmpty(paragraph->Align) && paragraph->Align == "center")
                {
                    rtfBuilder->Append(R"(\qc )");
                }

                if (paragraph->Children != nullptr)
                {
                    for each (Child ^ child in paragraph->Children)
                    {
                        if (child != nullptr)
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

                            if (child->Text != nullptr)
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

            if (table != nullptr)
            {
                rtfBuilder->Append(R"(\trowd\trgaph108)");  // Начало таблицы

                // Установите ширину столбцов, добавьте ее в ртф код
                int columnWidth = 1000; // Можно задать подходящее значение ширины столбцов
                if (table->Columns != nullptr)
                {
                    for each (Column ^ column in table->Columns)
                    {
                        rtfBuilder->Append(R"(\cellx)" + (columnWidth * (table->Columns->IndexOf(column) + 1)));
                    }
                }

                if (table->Children != nullptr)
                {
                    for each (TableRow ^ row in table->Children)
                    {
                        if (row != nullptr)
                        {
                            rtfBuilder->Append(R"(\row)");  // Начало строки

                            if (row->Children != nullptr)
                            {
                                for each (TableCell ^ cell in row->Children)
                                {
                                    if (cell != nullptr)
                                    {
                                        rtfBuilder->Append(R"(\cell)");  // Ячейка

                                        if (cell->Children != nullptr)
                                        {
                                            for each (Paragraph ^ para in cell->Children)
                                            {
                                                if (para != nullptr)
                                                {
                                                    if (para->Children != nullptr)
                                                    {
                                                        for each (Child ^ paraChild in para->Children)
                                                        {
                                                            if (paraChild != nullptr && paraChild->Text != nullptr)
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

    richTextBox->Rtf = rtfBuilder->ToString();
}
void CreateTableInRichTextBox(RichTextBox^ richTextBox) {
    // Пример RTF для создания таблицы с 2 строками и 3 столбцами
    String^ rtfTable = R"(
    {\rtf1\ansi \trowd \cellx2000 \cellx4000 \cellx6000 \intbl A1\cell B1\cell C1\cell \row \trowd \cellx2000 \cellx4000 \cellx6000 \intbl A2\cell B2\cell C2\cell \row \pard})";

    // Задаем RTF для RichTextBox
    richTextBox->Rtf = rtfTable;
}
