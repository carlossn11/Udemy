#include <iostream>
#include <vector>
#include <memory>

int add(int* a, int* b);

int main() {
  int a = 10;
  int b = 10;
  int result = 0;
  result = add(&a, &b);
  std::cout << result;
  return 0;
}

int add(int* a, int* b) {
  return (*a + *b);
}
