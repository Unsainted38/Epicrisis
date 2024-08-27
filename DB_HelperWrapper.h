#pragma once
//#include "DB_Helper.h"
#include <vcclr.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

namespace unsaintedWinApp {

    public ref class DB_HelperWrapper {
    private:
        //DB_Helper* nativeHelper; // ��������� �� ������������� �����

    public:
        DB_HelperWrapper(String^ dbPath);
        ~DB_HelperWrapper();
        !DB_HelperWrapper(); // ���������� ��� ������������ ������������� ��������

        List<String^>^ PopulateComboBox(String^ table, String^ column);

    };
}


