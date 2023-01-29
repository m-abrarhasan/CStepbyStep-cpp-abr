#include <cctype>
#include <iostream>
#include <string>
#include <vector>

std::string stutter(const std::string &str) {

  if (str == "")
    return str;

  std::string n_str;
  n_str.reserve(str.length() * 2);

  for (auto &c : str) {

    n_str.append(2, c);
  }
  return n_str;
}

// Main
///////////////////////////////////////////////////////
int main() {

  auto msg = stutter("hello");

  std::cout << msg;
  return 0;
}