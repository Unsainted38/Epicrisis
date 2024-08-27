#pragma once
//#include "DB_Helper.h"
#include <vcclr.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace unsaintedWinApp {

    public ref class DB_HelperWrapper {
    private:
        //DB_Helper* nativeHelper; // Указатель на неуправляемый класс

    public:
        DB_HelperWrapper(String^ dbPath);
        ~DB_HelperWrapper();
        !DB_HelperWrapper(); // Деструктор для освобождения неуправляемых ресурсов

        List<String^>^ PopulateComboBox(String^ table, String^ column);

    };
}


