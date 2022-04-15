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
// Mystring::Mystring(const Mystring &rhs) 
//   : str {nullptr} {
//     std::cout << "Copy Constructor Called\n";
//     str = new char[std::strlen(rhs.str) + 1];
//     std::strcpy(str, rhs.str);
// }
// Mystring::Mystring(Mystring &&rhs) 
//   : str {nullptr} {
//     std::cout << "Move Constructor called for " << rhs.str << "\n";
//     str = rhs.str;
//     rhs.str = nullptr;
// }
void Mystring::displayStr() {
  std::cout << "The String is: " << str << "\n";
}
void Mystring::operator=(const Mystring &rhs) {
  delete []this->str;
  this->str = new char[std::strlen(rhs.str) + 1];
  std::strcpy(this->str, rhs.str);
  std::cout << "Copy assignment called\n";
}
void Mystring::operator=(Mystring &&rhs) {
  delete []this->str;
  this->str = rhs.str;
  rhs.str = nullptr;
  std::cout << "Move assignment called\n";
}

int main() {
  Mystring name {"Carlos"};
  Mystring name2 {"Birian"};
  name.displayStr();
  name2.displayStr();
  name = "Tony";
  name.displayStr();
  name2.displayStr();
  return 0;
}