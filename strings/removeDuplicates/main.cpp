#include <cctype>
#include <iostream>
#include <string>

std::string removeDuplicates(std::string str) {

  auto strlen = str.length();

  if (str != "") {

    size_t i = 0;
    while (i < str.length() - 1) {

      if (str.at(i) == str.at(i + 1)) {

        str.erase(i + 1, 1);

      } else {
        i++;
      }
    }
  }

  return str;
}

// Main
///////////////////////////////////////////////////////
int main() {

  std::cout << removeDuplicates("bookkeeeeeper");
  return 0;
}