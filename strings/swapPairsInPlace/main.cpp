#include <cctype>
#include <iostream>
#include <string>
#include <vector>

void swapPairsInPlace(std::string& str)
{

    const auto len = ((str.length() % 2 == 0)) ? str.length() : str.length() - 1;
    if (len != 0) {

        char c;
        for (auto i = 0; i < len - 1; i += 2) {

            c = str[i];
            str[i] = str[i + 1];
            str[i + 1] = c;
        }
    }
}
// Main
///////////////////////////////////////////////////////
int main()
{

    std::string msg = "abcd";

    swapPairsInPlace(msg);

    std::cout << msg;
    return 0;
}