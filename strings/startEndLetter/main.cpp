#include <cctype>
#include <iostream>
#include <string>

void startEndLetter(const char &ch) {

  const char c = std::tolower(ch);
  std::string word, last;
  unsigned short is2 = 0;

  std::cout << "Looking for two \"" << c << "\" words in a row.\n";
  while (true) {

    std::cout << "Type a word: ";
    std::cin >> word;
    last = word;
    std::transform(word.cbegin(), word.cend(), word.begin(),
                   [](unsigned char a) { return std::tolower(a); });

    if (word.at(0) == c && word.at(word.length() - 1) == c) {

      is2++;
    } else {
      is2 = 0;
    }
    if (is2 >= 2) {
      break;
    }
  }
  std::cout << "\"" << c << "\" is for \"" << last << "\"";
}

// Main
///////////////////////////////////////////////////////
int main() {

  startEndLetter('j');
  // Type a word: I

  return 0;
}