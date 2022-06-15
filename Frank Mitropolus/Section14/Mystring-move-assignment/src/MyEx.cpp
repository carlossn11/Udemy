#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "../include/MyEx.h"

Mystring::Mystring() 
    : str {nullptr} {
}

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

Mystring Mystring::operator-() const {
  char* buff = new char[std::strlen(this->str) + 1];
  strcpy(buff, this->str);
  for (int i = 0; i < std::strlen(buff); i++) {
    buff[i] = std::tolower(buff[i]);
  }
  Mystring temp {buff};
  delete []buff;
  return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
  char* buff = new char[std::strlen(this->str) + std::strlen(rhs.str) + 1];
  std::strcpy(buff, this->str);
  std::strcat(buff, rhs.str);
  Mystring temp {buff};
  delete []buff;
  return temp;
}

std::istream &operator>>(std::istream &is, Mystring &rhs) {
  std::string temp;
  is >> temp;
  delete []rhs.str;
  rhs.str = new char[temp.size() + 1];
  std::strcpy(rhs.str, temp.c_str());
  return is;
}

int main() {
  Mystring name;
  std::cout << "enter: ";
  std::cin >> name;
  name.displayStr();
  return 0;
}