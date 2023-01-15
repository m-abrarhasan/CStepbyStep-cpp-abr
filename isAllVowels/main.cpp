#include <cctype>
#include <iostream>
#include <string>

bool isAllVowels(std::string str)
{
    bool isAllVowels = true;
    const char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < str.length(); ++i) {

        str[i] = std::toupper(str.at(i));

        for (int j = 0; j < 5; ++j) {

            if (str[i] == vowels[j]) {
                break;
            } else if (j == 4) {
                return false;
            }
        }
    }

    return isAllVowels;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    std::string line;
    std::getline(std::cin, line);

    std::cout << '\n' << isAllVowels(line);

    return 0;
}
