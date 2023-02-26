#include <fstream>
#include <iostream>
#include <unordered_map>

std::string mostCommon(const std::string& path)
{
    std::ifstream file(path);
    std::pair<std::string, size_t> most;

    if (file.is_open()) {

        std::unordered_map<std::string, size_t> names;
        std::string token;

        file >> token ? most = { token, 1 } : most = { "", 0 };
        names.insert(most);

        while (file >> token) {
            names.count(token) ? names.at(token)++ : names[token] = 1;

            if (names.at(token) > most.second) {
                most.first  = token;
                most.second = names.at(token);
            }
        }
    }
    return most.first;
}

int main(int, char**)
{
    std::cout << "most common = " + mostCommon("input.txt") + "\n";
    return 0;
}