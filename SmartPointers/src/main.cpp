#include <iostream>
#include <memory>
#include <vector>

class Test {
 private:
 public:
  int m_Num;
  Test() : m_Num(0) {}
  Test(const int &num) : m_Num(num) {}
  ~Test() { std::cout << "Destructor\n"; }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
  return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int numOfTestObj) {
  int num;
  for (int i = 0; i < numOfTestObj; ++i) {
    std::cout << "Enter data point [" << i+1 << "]: ";
    std::cin >> num;
    vec.push_back(std::make_shared<Test>(num));
  }
}

void display(std::unique_ptr<std::vector<std::shared_ptr<Test>>> &vec_ptr) {
  for (const auto &test : *vec_ptr) {
    std::cout << "m_Num: " << test->m_Num << '\n';
  }
}

int main() {
  auto vec_ptr = make();
  fill(*vec_ptr, 5);
  display(vec_ptr);
  return 0;
}