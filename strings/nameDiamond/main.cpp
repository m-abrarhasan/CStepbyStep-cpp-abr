#include <cctype>
#include <iostream>
#include <string>

void nameDiamond(std::string str) {

  const size_t strlen = str.length();

  std::string line(strlen, ' ');
  std::string block;
  for (size_t i = 0; i < strlen; i++) {

    for (size_t j = 0; j <= i; j++) {
      line[j] = str[j];
    }
    block.append(line + "\n");
  }

  line = str;
  for (size_t i = 0; i < strlen; i++) {

    for (size_t j = 0; j <= i; j++) {
      line[j] = ' ';
    }
    block.append(line + "\n");
  }

  block.pop_back();
  std::cout << block;
}

// Main
///////////////////////////////////////////////////////
int main() {

  nameDiamond("marty");

  return 0;
}