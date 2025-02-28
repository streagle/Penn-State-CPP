#pragma once
#include <iostream>
#include <cstring>  // for strlen(), etc.
using namespace std;

#define MAX_STR_LENGTH  200

class String {
public:
  String();
  String(const char s[]);  // a conversion constructor   
  void append(const String &str);

  // Relational operators
  bool operator ==(const String &str) const;    
  bool operator !=(const String &str) const;   
  bool operator >(const String &str) const;    
  bool operator <(const String &str) const;    
  bool operator >=(const String &str) const; 
  String operator +=(const String &str);      

  void print(ostream &out) const;    
  int length() const;

  char operator [](int i) const;  // subscript operator  

private:
    char contents[MAX_STR_LENGTH+1];
    int len;
};

ostream & operator<<(ostream &out, const String & r); // overload ostream operator "<<" - External!  
