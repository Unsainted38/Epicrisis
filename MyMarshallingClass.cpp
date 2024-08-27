#include "MyMarshallingClass.h"
// Преобразование из std::string в System::String^
String^ ConvertStdStringToSystemString(string& input)
{
    return gcnew System::String(input.c_str());
}
// Преобразование из System::String^ в std::string
string ConvertSystemStringToStdString(System::String^ input)
{
    msclr::interop::marshal_context context;
    return context.marshal_as<std::string>(input);
}
// Преобразование из const unsigned char* в System::String^
String^ ConvertConstUnsignedCharToSystemString(const unsigned char* input)
{
    return gcnew System::String(reinterpret_cast<const char*>(input));
}
// Преобразование из const undigned char* в std::string
string ConvertConstUnsignedCharToStdString(const unsigned char* input)
{
    return string(reinterpret_cast<const char*>(input));
}
namespace unsaintedWinApp {
    MyMarshallingClass::MyMarshallingClass()
    {
        throw gcnew System::NotImplementedException();
    }

    MyMarshallingClass::~MyMarshallingClass()
    {
        throw gcnew System::NotImplementedException();
    }

    String^ MyMarshallingClass::ConvertStdStringToSystemString(string& input)
    {
        return gcnew System::String(input.c_str());
    }
    // Преобразование из System::String^ в std::string
    string MyMarshallingClass::ConvertSystemStringToStdString(System::String^ input)
    {
        msclr::interop::marshal_context context;
        return context.marshal_as<std::string>(input);
    }
    // Преобразование из const unsigned char* в System::String^
    String^ MyMarshallingClass::ConvertConstUnsignedCharToSystemString(const unsigned char* input)
    {
        return gcnew System::String(reinterpret_cast<const char*>(input));
    }
    // Преобразование из const unsigned char* в std::string
    string MyMarshallingClass::ConvertConstUnsignedCharToStdString(const unsigned char* input)
    {
        return string(reinterpret_cast<const char*>(input));
    }
};