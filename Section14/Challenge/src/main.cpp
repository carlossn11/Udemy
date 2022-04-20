#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include "../include/string.h"

int main() {
  los::String connor {"Connor"};
  std::vector<los::String> strs;

  strs.push_back("PUSSHHHHH");
  connor = "GOAT";
  connor.print();
  strs[0].print();
  return 0;
}