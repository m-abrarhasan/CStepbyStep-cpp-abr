#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

void inputStats(const std::string& path)
{
    std::ifstream file(path);
    if (file) {

        size_t total_l      = 0;
        size_t total_ch     = 0;
        size_t longest_l    = 0;
        long double average = 0;

        std::string line;
        size_t length;
        while (std::getline(file, line)) {

            length = line.length();
            total_l++;
            total_ch += length;
            longest_l = (length > longest_l) ? length : longest_l;

            std::cout << "Line " << total_l << " has " << length << " chars\n";
        }
        average = static_cast<long double>(total_ch) / static_cast<long double>(total_l);
        std::cout << total_l << " lines; longest = " << longest_l << ", average = " << average;
    }
}

int main(int, char**)
{
    inputStats("input.txt");
    return 0;
}