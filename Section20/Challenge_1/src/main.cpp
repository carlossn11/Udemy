// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s) {
  std::deque<char> dequeTypeChar;
  std::copy_if(s.cbegin(), s.cend(), std::back_inserter(dequeTypeChar), 
  [] (char c) {
    if (std::isalpha(c))
      return true;

    return false;
  });

  std::transform(std::cbegin(dequeTypeChar), std::cend(dequeTypeChar), std::begin(dequeTypeChar), ::toupper);

  std::deque<char> reversedTypeChar;
  std::copy(dequeTypeChar.crbegin(), dequeTypeChar.crend(), std::back_inserter(reversedTypeChar));

  if (dequeTypeChar == reversedTypeChar)
    return true;

  return false;
}

int main() {
  std::vector<std::string> test_strings { "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
    "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
    "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
  
  std::cout << std::boolalpha;
  std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
  for(const auto& s : test_strings) {
    std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
  }
  std::cout << std::endl;
  return 0;
}