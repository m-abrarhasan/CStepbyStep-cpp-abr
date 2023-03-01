#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>

void vowelStats(const std::string& path)
{
    std::ifstream file(path);
    if (file.is_open()) {

        const std::array<char, 5> vowel { 'A', 'E', 'I', 'O', 'U' };
        size_t total_l   = 0;
        size_t longest_l = 0;
        size_t total_ch  = 0;
        double average   = 0;

        std::string line;
        while (std::getline(file, line)) {

            total_l++;
            total_ch += line.length();
            longest_l = (line.length() > longest_l) ? line.length() : longest_l;

            size_t vowels = 0;
            for (const auto& c : line) {
                char u = std::toupper(c);
                vowels += std::count(vowel.begin(), vowel.end(), u);
            }

            std::cout << "Line " << total_l
                      << " has " << line.length()
                      << " chars and " << vowels
                      << " vowels\n";
        }
        average = total_ch / static_cast<double>(total_l);
        std::cout << total_l
                  << " lines; longest = "
                  << longest_l
                  << ", average = "
                  << average;
    }
}

int main(int, char**)
{
    vowelStats("../input.txt");
    return 0;
}