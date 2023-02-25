#include <fstream>
#include <iostream>
#include <map>
#include <string>

void leetSpeak(const std::string& i_path, const std::string& o_path)
{
    std::map<char, char> leets {
        { 'o', '0' },
        { 'l', '1' },
        { 'e', '3' },
        { 'a', '4' },
        { 't', '7' },
    };

    std::ifstream i_file(i_path);
    std::ofstream o_file(o_path);
    std::string line;

    if (i_file && o_file) {

        while (std::getline(i_file, line)) {

            std::string token;
            for (auto& c : line) {

                if (leets.count(c)) {
                    c = leets.at(c);
                }
                if (c != ' ') {
                    token += c;

                } else {
                    if (!token.empty()) {
                        token[token.length() - 1] = (token.back() == 's') ? 'Z' : token.back();
                        o_file << "(" + token + ")";
                        token.clear();
                    }
                    o_file << c;
                }
            }
            if (!token.empty()) {
                token[token.length() - 1] = (token.back() == 's') ? 'Z' : token.back();
                o_file << "(" + token + ")";
            }
            o_file << "\n";
        }
    }
}

int main(int, char**)
{
    leetSpeak("input.txt", "output.txt");
    return 0;
}