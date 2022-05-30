#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <iterator>
 
int main() {
  std::vector<int> vec { 1, 3, 4, 6 };
  std::vector<int>::iterator it = vec.end();
  std::cout << it;
  return 0;
}
