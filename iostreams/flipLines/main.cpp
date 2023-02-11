#include <algorithm>
#include <fstream>
#include <iostream>
#include <streambuf>
#include <string>
#include <utility>

void flipLines(const std::string& path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cout << "Unable to open input file \"" << path << "\"!" << std::endl;
        std::exit(0); // exiting with zero to avoid console output
    }

    size_t lines { 0 };
    std::string line_a;
    std::string line_b;
    while (!file.eof()) {

        std::getline(file, line_a);
        std::getline(file, line_b);

        // reversed line order
        std::swap(line_a, line_b);

        // alternating case
        std::transform(line_a.begin(), line_a.end(), line_a.begin(), ::toupper);
        std::transform(line_b.begin(), line_b.end(), line_b.begin(),

            [&lines](unsigned char ch) {
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
}

int main(int, char**)
{
    flipLines("input.txt");
    return 0;
}