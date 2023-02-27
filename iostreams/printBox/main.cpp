#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

void printBox(const std::string path, int width)
{
    if (width < 2) {
        throw -1;
    }

    std::ifstream file(path);
    if (file) {

        std::string line;
        std::vector<std::string> data;

        while (std::getline(file, line)) {

            // turncate lines
            if (width - 2 < line.length()) {
                line.erase((width - 2));
            }
            // Title Case
            if (line != "") {
                for (auto& c : line) {
                    c = std::tolower(c);
                }
                line[0] = std::toupper(line[0]);
            }
            // store in data
            data.push_back(line);
        }

        // output
        const char border = '#';
        const size_t rows = data.size() + 2;
        const size_t cols = width;

        size_t r  = 0;
        size_t ln = 0;
        while (r < rows) {

            size_t c = 0;
            while (c < cols) {

                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    std::cout << border;
                    c++;

                } else if (c == 1 && r != 0 && r != rows - 1) {

                    if (data.at(ln) == "") {
                        std::cout << ' ';
                        c++;
                        ln++;

                    } else {
                        std::cout << data.at(ln);
                        c += data.at(ln).length();
                        ln++;
                    }

                } else {
                    std::cout << ' ';
                    c++;
                }
            }
            std::cout << '\n';
            r++;
        }
    }
}

int main(int, char**)
{
    printBox("input.txt", 5);
    return 0;
}