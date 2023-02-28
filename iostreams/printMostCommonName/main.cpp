#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

size_t printMostCommonName(const std::string& path)
{
    size_t unique_names = 0;
    std::ifstream file(path);
    if (file.is_open()) {

        /// sutff
        std::pair<std::string, size_t> most  = { "", 0 };
        std::pair<std::string, size_t> token = { "", 0 };
        std::string name;

        while (file >> name) {
            if (name != token.first) {
                token = { name, 1 };
                unique_names++;

            } else {
                token.second++;
            }
            token.second > most.second ? most = token : most;
        }
        std::cout << "Most common name: " + most.first + ", " << most.second;
    }
    return unique_names;
}

int main(int, char**)
{
    auto u = printMostCommonName("input.txt");
    std::cout << '\n'
              << "total names ="
              << u;

    return 0;
}