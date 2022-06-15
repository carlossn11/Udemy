// Section 20
// Challenge 3  
// Maps and Sets

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <cctype>
#include <string>
#include <iomanip>

void display_words(const std::map<std::string, int> &words) {
    std::cout << std::left;
    for (auto it = words.cbegin(); it != words.cend(); ++it) {
        std::cout << std::setw(15) << it->first << it->second << std::endl;
    }
    std::cout << std::right;
}

void display_words(const std::map<std::string, std::set<int>> &words)
{
     std::cout << std::setw(12) << std::left << "\nWord"
                << "Occurrences"<< std::endl;
    std::cout << "=====================================================================" << std::endl;
    for (auto pair: words) {
        std::cout << std::setw(12) << std::left << pair.first 
                       << std::left << "[ ";
        for (auto i: pair.second) 
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

// This function removes periods, commas, semicolons and colon in 
// a string and returns the clean version
std::string clean_string(const std::string &s) {
    std::string result;
    for (char c: s) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else
            result += tolower(c);
    }
    result.at(0) = toupper(result.at(0));
    return result;
}

// Part1 process the file and builds a map of words and the 
// number of times they occur in the file

void part1() {
    std::map<std::string, int> words;
    std::string word;   
    std::ifstream in_file {"words.txt"};
    if (in_file) {
        while (in_file >> word) {
            word = clean_string(word);
            words[word] += 1;
        }
        in_file.close();
        display_words(words);
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}
    
// Part2 process the file and builds a map of words and a 
// set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    int lineCount = 1;
    std::string word;
    std::ifstream in_file {"words.txt"};
    if (in_file) {
        while (std::getline(in_file, line)) {
            std::stringstream ss(line);
            while (ss >> word) {
                word = clean_string(word);
                words[word].insert(lineCount);
            }
            ++lineCount;
        }
        display_words(words);
        in_file.close();
    } else {
        std::cerr << "Error opening input file" << std::endl;
    }
}

int main() {
    part2();
    return 0;
}

