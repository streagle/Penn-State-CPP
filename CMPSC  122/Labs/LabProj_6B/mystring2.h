// Academic Integrity Affidavit:
// I certify that this program code is my work. Others may have
// assisted me with planning and concepts, but the code was written,
// solely, by me.
// I understand that submitting code that is totally or partially
// the product of other individuals is a violation of the Academic
// Integrity Policy and accepted ethical precepts. Falsified
// execution results are also results of improper activities. Such
// violations may result in zero credit for the assignment, reduced
// credit for the assignment, or course failure.
//
// Name: <Ryan Reagle>
// Section: <003L>
// Assignment: Lab 03
//

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
