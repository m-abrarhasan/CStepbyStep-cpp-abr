#include <algorithm>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include <utility>

size_t
flipAndReverseLines()
{
    std::string path;
    std::ifstream file;
    while (!file.is_open()) {

        std::cout << "Input file name? ";
        std::getline(std::cin, path);

        file.open(path);
        if (!file.is_open()) {
            std::cout << "Unable to open that file.  Try again.\n";
        } else {
            std::cout << "\n";
        }
    }

    size_t lines { 0 };
    std::string line_a;
    std::string line_b;
    while (!file.eof()) {

        std::getline(file, line_a) ? lines++ : lines;
        std::getline(file, line_b) ? lines++ : lines;

        // reversed line order
        std::swap(line_a, line_b);

        // reversed line
        auto reverse = [&](std::string& str) {
            auto l = str.begin();
            auto r = str.end() - 1;
            while (l < r) {
                std::swap(*l++, *r--);
            }
        };
        reverse(line_a);
        reverse(line_b);

        // alternating case
        std::transform(line_a.begin(), line_a.end(), line_a.begin(), ::toupper);
        std::transform(
            line_b.begin(), line_b.end(), line_b.begin(), [&lines](unsigned char ch) {
                if (lines % 2 == 0) {
                    return std::tolower(ch);
                } else {
                    return std::toupper(ch);
                }
            });

        // output
        std::cout << (file.eof() ? line_a : line_a + "\n");
        std::cout << (file.eof() ? line_b : line_b + "\n");

        // clear lines
        line_a.clear();
        line_b.clear();
    }
    return lines;
}

///////////// Main /////////////////
int main(int, char**)
{
    flipAndReverseLines();

    return 0;
}