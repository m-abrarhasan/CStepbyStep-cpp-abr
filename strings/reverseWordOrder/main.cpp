#include <cctype>
#include <iostream>
#include <string>

std::string reverseWordOrder(const std::string& str)
{

    if (str == "") {
        return str;
    }

    std::string nstr;
    for (size_t i = str.length() - 1; i >= 0; i--) {
        if (str.at(i) != ' ') {

            uint16_t e = i;

            while (str.at(i) != ' ') {
                if (i == 0) {
                    // std::cout << "BREAK\n";
                    break;
                } else {
                    i--;
                    // std::cout << i << "\n";
                }
            }

            uint16_t b = (i == 0) ? i : i + 1;
            uint16_t p = (e - b) + 1;

            if (str.at(b) != ' ') {

                nstr.append(str.substr(b, p) + ' ');
                // std::cout << nstr << "\n";
                if (i == 0) {
                    nstr.pop_back();
                    break;
                }
            }
        }
    }

    return nstr;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    std::cout << reverseWordOrder("Hello what is your name?");

    return 0;
}