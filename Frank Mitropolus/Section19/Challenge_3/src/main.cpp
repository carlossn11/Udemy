// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
  std::fstream inFile("romeoandjuliet.txt", std::ios::in);
  std::string word;
  int matchCount = 0;
  int wordCount = 0;

  while (inFile >> word) {
    if (word.contains("love")) {
      ++matchCount;
    }
    ++wordCount;
  }
  std::cout << matchCount << " " << wordCount;
  return 0;
}

