#pragma once
#include <iostream>
#include <cstring> // for strlen(), etc.
using namespace std;

class String {
public:
  String();
  String(const char s[]); // a conversion constructor
  String(const String &str); // copy constructor
  ~String(); // destructor

  void append(const String &str);
  // Relational operators
  bool operator ==(const String &str) const;
  bool operator !=(const String &str) const;
  bool operator >(const String &str) const;
  bool operator <(const String &str) const;
  bool operator >=(const String &str) const;
  String& operator =(const String &str); // assignment operator
  String operator +=(const String &str);
  void print(ostream &out) const;
  int length() const;
  char operator [](int i) const; // subscript operator

private:
  char *contents; // pointer to dynamically allocated array of characters
  int len; // current length of the string
};

ostream & operator<<(ostream &out, const String & r); // overload ostream operator "<<" - External!
