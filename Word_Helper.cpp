#include "Word_Helper.h"
namespace unsaintedWinApp {
    Word_Helper::Word_Helper(String^ templateFilePath, String^ outputFilePath)
    {
        templateFile = templateFilePath;
        outputFile = outputFilePath;
        
    }

    Word_Helper::~Word_Helper()
    {
        
    }

    void Word_Helper::InsertTableIntoTemplate(String^ jsonData)
    {
        auto json = JsonConvert::DeserializeObject<System::Collections::Generic::Dictionary<String^, Object^>^>(jsonData);
        auto columns = safe_cast<System::Collections::Generic::List<String^>^>(json["columns"]);
        auto rows = safe_cast<System::Collections::Generic::List<System::Collections::Generic::List<Object^>^>^>(json["rows"]);

        Word::Application^ wordApp = gcnew Word::ApplicationClass();
        
        Word::Document^ doc = wordApp->Documents->Open(safe_cast<Object^>(templateFile),
            missing,     // ConfirmConversions
            missing,     // ReadOnly
            missing,     // AddToRecentFiles
            missing,     // PasswordDocument
            missing,     // PasswordTemplate
            missing,     // Revert
            missing,     // WritePasswordDocument
            missing,     // WritePasswordTemplate
            missing,     // Format
            missing,     // Encoding
            missing,     // Visible
            missing,     // OpenAndRepair
            missing,     // DocumentDirection
            missing,     // NoEncodingDialog
            missing
            );
        wordApp->Visible = true;
        ///^ table = doc->Tables->Add(doc->Range(0, 0), rows->Count + 1, columns->Count);
    }

    void Word_Helper::OpenDocument()
    {
        Word::Application^ wordApp = gcnew Word::ApplicationClass();
        
        Word::Document^ doc = wordApp->Documents->Open(templateFile,
            missing,     // ConfirmConversions
            missing,     // ReadOnly
            missing,     // AddToRecentFiles
            missing,     // PasswordDocument
            missing,     // PasswordTemplate
            missing,     // Revert
            missing,     // WritePasswordDocument
            missing,     // WritePasswordTemplate
            missing,     // Format
            missing,     // Encoding
            missing,     // Visible
            missing,     // OpenAndRepair
            missing,     // DocumentDirection
            missing,     // NoEncodingDialog
            missing);
        wordApp->Visible = true;
    }
    void Word_Helper::InsertTable(Word::Document^ doc, Dictionary<String^, Object^>^ json) {
        // Проверка наличия закладки для вставки таблицы
        if (doc->Bookmarks->Exists("TablePlaceholder")) {
            Word::Bookmark^ bookmark;
            
            Word::Range^ range = bookmark->Range;
            

            // Получение данных из JSON
            List<String^>^ columns = safe_cast<List<String^>^>(json["columns"]);
            List<List<Object^>^>^ rows = safe_cast<List<List<Object^>^>^>(json["rows"]);

            // Вставка таблицы
            Word::Table^ table = doc->Tables->Add(range, rows->Count + 1, columns->Count, missing, missing);
            
            //// Заполнение заголовков столбцов
            for (int col = 0; col < columns->Count; ++col) {
                table->Cell(1, col + 1)->Range->Text = columns[col];
            }
            
            //// Заполнение строк данных
            //for (int row = 0; row < rows->Count; ++row) {
            //    for (int col = 0; col < columns->Count; ++col) {
            //        table->Cell(row + 2, col + 1)->Range->Text = rows[row][col]->ToString();
            //    }
            //}
        }
        else {
            throw gcnew Exception("Bookmark 'TablePlaceholder' not found in the document.");
        }
    }
    

};