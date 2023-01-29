#include <cctype>
#include <iostream>
#include <string>

std::string repeat(const std::string str, const int &reps) {

  if (str != "") {

    std::string rstring;
    for (size_t i = 0; i < reps; i++) {
      rstring.append(str);
    }
    return rstring;
  } else {
    return str;
  }
}

// Main
///////////////////////////////////////////////////////
int main() {

  std::string word = "Hello";
  std::cout << repeat(word, 3);

  return 0;
}