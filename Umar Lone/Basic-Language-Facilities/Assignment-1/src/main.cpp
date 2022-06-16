#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>

int add(int* a, int* b);
void swap(int* a, int* b);

int main() {
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
