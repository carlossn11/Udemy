#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include <string>
#include <bitset>

template<typename T>
int add(int* a, int* b, T src);
void swap(int* a, int* b);
void factorial(int* num, int* result);

int main() {
  // uint32_t n = 0b00100010000000000000000000001011;
  // std::bitset<32> s(n);
  // std::cout << s.to_string() << '\n';
  // std::cout << std::count_if(s.to_string().begin(), s.to_string().end(), [](char c){
  //   return (c == '1');
  // });
  return 0;
}

void factorial(int* num, int* result) {
  *result = 1;
  for (auto i = 1; i <= *num; ++i) {
    *result *= i;
  }
}

template<typename T>
int add(int* a, int* b, T src) {
  return (*a + *b);
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
