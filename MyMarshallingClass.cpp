#include "MyMarshallingClass.h"
// �������������� �� std::string � System::String^
String^ ConvertStdStringToSystemString(string& input)
{
    return gcnew System::String(input.c_str());
}
// �������������� �� System::String^ � std::string
string ConvertSystemStringToStdString(System::String^ input)
{
    msclr::interop::marshal_context context;
    return context.marshal_as<std::string>(input);
}
// �������������� �� const unsigned char* � System::String^
String^ ConvertConstUnsignedCharToSystemString(const unsigned char* input)
{
    return gcnew System::String(reinterpret_cast<const char*>(input));
}
// �������������� �� const undigned char* � std::string
string ConvertConstUnsignedCharToStdString(const unsigned char* input)
{
    return string(reinterpret_cast<const char*>(input));
}
