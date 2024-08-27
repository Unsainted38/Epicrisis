#pragma once
#include <string>
#include <cstdio>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace std;
namespace unsaintedWinApp {
    public ref class MyMarshallingClass
    {
    public:
        MyMarshallingClass();
        ~MyMarshallingClass();


        String^ ConvertStdStringToSystemString(string& input);
        string ConvertSystemStringToStdString(String^ input);
        String^ ConvertConstUnsignedCharToSystemString(const unsigned char* input);
        string ConvertConstUnsignedCharToStdString(const unsigned char* input);
    };
};
    String^ ConvertStdStringToSystemString(string& input);
    string ConvertSystemStringToStdString(String^ input);
    String^ ConvertConstUnsignedCharToSystemString(const unsigned char* input);
    string ConvertConstUnsignedCharToStdString(const unsigned char* input);
