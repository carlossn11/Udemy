#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

int add(int* a, int* b);
void swap(int* a, int* b);

int main() {
  int a = 1;
  int b = 5;
  std::cout << std::left;
  std::cout << std::setw(2) << a << b << '\n';
  swap(&a, &b);
  std::cout << std::setw(2) << a << b << '\n';
  std::cout << std::right;

  return 0;
}

int add(int* a, int* b) {
  return (*a + *b);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
