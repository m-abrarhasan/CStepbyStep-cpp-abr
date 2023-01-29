#include <cctype>
#include <iostream>

size_t countWords(std::string str) {
  size_t words = 0;

  // In case of an empty string apending two spaces
  // to make sure index 1 exists
  str.append("  ");

  const size_t lenstr = str.length();
  for (size_t i = 1; i < lenstr; ++i) {
    if (' ' == str.at(i) && ' ' != str.at(i - 1)) {
      words++;
    }
  }

  return words;
}

// Main
///////////////////////////////////////////////////////
int main() {
  std::string str = "hello";

  std::cout << str.substr(1);

  return 0;
}