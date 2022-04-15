#include <iostream>
#include <cstring>
#include <vector>
#include "../include/MyEx.h"

Mystring::Mystring(const char* s) 
 : str {nullptr} {
   str = new char[std::strlen(s)+1];
   std::strcpy(this->str, s);
}
Mystring::~Mystring() {
  delete []str;
}
Mystring::Mystring(const Mystring &rhs) 
  : str {nullptr} {
    std::cout << "Copy Constructor Called\n";
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
}
Mystring::Mystring(Mystring &&rhs) 
  : str {nullptr} {
    std::cout << "Move Constructor called for " << rhs.str << "\n";
    str = rhs.str;
    rhs.str = nullptr;
}
void Mystring::displayStr() {
  std::cout << "The String is: " << str << "\n";
}

int main() {
  Mystring name {"Carlos"};
  name.displayStr();
  std::vector<Mystring> vecString;
  vecString.push_back("Bob");
  vecString.push_back(name);
  return 0;
}