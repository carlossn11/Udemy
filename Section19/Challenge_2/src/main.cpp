// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
  std::fstream inFile("responses.txt", std::ios::in);
  std::string Answer_Key;
  std::string name;
  std::string studentAnswerKey;
  int studentCorrectResponses = 0;
  float averageScore;

  std::cout << std::setw(15) << std::left << "Student" << "Score\n";
  std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
  std::cout << std::setfill(' ');

  if (!inFile.is_open())
    return 1;
  inFile >> Answer_Key;
  while (inFile >> name >> studentAnswerKey) {
    for (int i = 0; i < studentAnswerKey.size(); ++i) {
      if (studentAnswerKey.at(i) == Answer_Key.at(i))
        ++studentCorrectResponses;
    }
    std::cout << std::left << std::setw(17) << name << std::right << studentCorrectResponses << '\n';
    averageScore += studentCorrectResponses;
    studentCorrectResponses = 0;
  }
  std::cout << std::setfill('-') << std::setw(20) << "" << std::left << std::endl;
  std::cout << std::setfill(' ');
  std::cout << std::setw(16) << "Average:" << averageScore/5.0 << '\n';
  inFile.close();
  return 0;
}

