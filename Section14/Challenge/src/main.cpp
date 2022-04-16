#include <iostream>
#include <cstring>
#include <vector>
#include "../include/string.h"

int main() {
  los::String carlos {"Carlos "};
  los::String connor {"& Connor"};

  std::cout << carlos << "\n";
  std::cin >> carlos;
  std::cout << carlos << "\n";
  return 0;
}