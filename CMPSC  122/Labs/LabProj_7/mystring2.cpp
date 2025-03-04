#include <cstring>
#include "mystring2.h"
#pragma warning(disable : 4996)   // disbale the unsafe warning message to use strcpy_s(), etc
String::String(const String &str) // copy constructor
{
    len = str.len;
    contents = new char[len + 1];
    strncpy(contents, str.contents, len);
    contents[len] = '\0';
}
String::~String()
{
    delete[] contents;
}

String &String::operator=(const String &str) // assignment operator
{
    if (this != &str)
    {
        delete[] contents;
        len = str.len;
        contents = new char[len + 1];
        strncpy(contents, str.contents, len);
        contents[len] = '\0';
    }
    return *this;
}

String::String()
{
    contents = new char[1];
    contents[0] = '\0';
    len = 0;
}
String::String(const char s[])
{
    len = strlen(s);
    contents = new char[len + 1];
    strncpy(contents, s, len);
    len = strlen(s);
    strcpy(contents, s);
}
void String::append(const String &str)
{
    strcat(contents, str.contents);
    len += str.len;
}
bool String::operator==(const String &str) const
{
    return strcmp(contents, str.contents) == 0;
}
bool String::operator!=(const String &str) const
{
    return strcmp(contents, str.contents) != 0;
}
bool String::operator>(const String &str) const
{
    return strcmp(contents, str.contents) > 0;
}
bool String::operator<(const String &str) const
{
    return strcmp(contents, str.contents) < 0;
}
bool String::operator>=(const String &str) const
{
    return strcmp(contents, str.contents) >= 0;
}
String String::operator+=(const String &str)
{
    append(str);
    return *this;
}
void String::print(ostream &out) const
{
    out << contents;
}
int String::length() const
{
    return len;
}
char String::operator[](int i) const
{
    if (i < 0 || i >= len)
    {
        cerr << "can't access location " << i
             << " of string \"" << contents << "\"" << endl;
        return '\0';
    }
    return contents[i];
}
ostream &operator<<(ostream &out, const String &s) // overload ostream operator "<<" - External!
{
    s.print(out);
    return out;
}
