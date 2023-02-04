#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::string
coolest(const std::string& path)
{
  std::fstream file(path);

  std::string name_a, name_b;
  std::unordered_map<std::string, size_t> followers;
  std::unordered_map<std::string, std::vector<std::string>> followees;

  while (file >> name_a >> name_b) {

    followers[name_b]++;
    followees[name_b].push_back(name_a);
  }

  std::string coolest;
  long mostPopular = -1;
  for (const auto& pair : followees) {

    const auto& user = pair.first;
    const auto& flist = pair.second;

    long popularity = 0;
    for (const auto& name : flist) {

      popularity += followers[name];
    }
    if (popularity > mostPopular) {

      coolest = user;
      mostPopular = popularity;

    } else if (popularity == mostPopular) {
      coolest = std::min(coolest, user);
    }
  }
  return coolest;
}

///////////// Main /////////////////
int
main(int, char**)
{
  // std::map<std::string, size_t> popular{ { "marty", 20 }, { "arty", 10 } };
  // for (const auto& [name, follower] : popular) {

  //   std::cout << name << " : " << follower << "\n";
  // }
  // std::cout << popular["marty"] << "\n";

  std::cout << coolest("../../../input.txt");
  return 0;
}