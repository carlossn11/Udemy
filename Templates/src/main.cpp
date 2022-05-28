#include <iostream>
#include <string>

template<typename T>
class Array {
 public:
  Array(int ArraySize) 
      : m_Array(new T[ArraySize] {0}) {}
  ~Array() { delete []m_Array; }
  T at(int index) {
    return m_Array[index];
  }
 private:
  T* m_Array;
};

int main() {
  Array<std::string> My_Array(5);
  std::cout << My_Array.at(3);
  return 0;
}