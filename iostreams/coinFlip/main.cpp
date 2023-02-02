#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

void coinFlip(const std::string &fpath) {
  unsigned int t_heads = 0;
  unsigned int t_tails = 0;

  std::ifstream file(fpath);

  if (file.is_open()) {
    std::string token;

    while (file >> token) {
      std::transform(token.cbegin(), token.cend(), token.begin(),
                     [](unsigned char c) { return std::toupper(c); });

      if ("HEADS" == token || token == "H") {
        t_heads++;
      }
      if ("TAILS" == token || token == "T") {
        t_tails++;
      }
    }

    if (t_heads >= 0 || t_tails >= 0) {
      double percentage =
          std::round((t_heads / (double)(t_heads + t_tails)) * 100);

      // output--------
      std::cout << t_heads << " heads (" << percentage << "%)\n";
      (percentage >= 50) ? std::cout << "You win!" : std::cout << "You lose!";
    }
  }
}

///////////// Main /////////////////
int main(int, char **) {
  coinFlip("input.txt");

  return 0;
}