#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
  std::fstream inFile("romeoandjuliet", std::ios::in);
  std::fstream oFile("Formatted_romeoandjuliet.txt", std::ios::out);
  std::string line;
  int index = 0;
  if (!inFile && !oFile) {
    return 1;
  }
  while (std::getline(inFile, line)) {
    ++index;
    if (line == "") {
      oFile << std::endl;
    }else {
      oFile << std::setw(6) << std::left << index << line;
    }
  }

  inFile.close();
  oFile.close();
  return 0;
}

