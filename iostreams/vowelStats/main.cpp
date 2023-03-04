#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>

void vowelStats(const std::string& path)
{
    std::ifstream file(path);
    if (file.is_open()) {

        const std::unordered_set<char> vowel { 'A', 'E', 'I', 'O', 'U' };
        size_t total_ln = 0;
        size_t longest  = 0;
        size_t total_ch = 0;
        double average  = 0;

        std::string line;
        while (std::getline(file, line)) {

            total_ln++;
            total_ch += line.length();
            longest = (line.length() > longest) ? line.length() : longest;

            size_t vowels = 0;
            for (const auto& c : line) {
                vowels += vowel.count(std::toupper(c));
            }

            std::cout << "Line " << total_ln
                      << " has " << line.length()
                      << " chars and " << vowels
                      << " vowels\n";
        }
        average = total_ch / static_cast<double>(total_ln);
        std::cout << total_ln
                  << " lines; longest = "
                  << longest
                  << ", average = "
                  << average;
    }
}

/////////////////////
int main(int, char**)
{
    vowelStats("../input.txt");
    return 0;
}
/////////////////////