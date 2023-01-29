#include <cctype>
#include <iostream>
#include <string>

std::string replaceAll(std::string str, const char c1, const char c2) {

  if (str != "") {

    const auto strlen = str.length();
    for (size_t i = 0; i < strlen; i++) {

      if (str[i] == c1) {
        str[i] = c2;
      }
    }
  }

  return str;
}

// Main
///////////////////////////////////////////////////////
int main() {

  std::cout << replaceAll("Hello, world!", 'l', 'Y');

  return 0;
}