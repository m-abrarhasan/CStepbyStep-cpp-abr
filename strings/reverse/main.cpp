#include <cctype>
#include <iostream>
#include <string>

std::string reverse(std::string str) {

  // if (str != "") {

  //   char cstr[str.length()];

  //   size_t j = 0;
  //   for (auto i = str.length(); i != 0; i--) {

  //     cstr[j] = str[i - 1];
  //     j++;
  //   }

  //   return cstr;
  // } else {
  //   return str;
  // }

  std::reverse(str.begin(), str.end());
  return str;
}

// Main
///////////////////////////////////////////////////////
int main() {

  std::cout << reverse("banana split");

  return 0;
}