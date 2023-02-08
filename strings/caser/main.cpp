#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

std::string caeser(std::string& s, int key);

int main()
{
    std::string message;
    int key;
    std::cout << "Your message? ";
    std::getline(std::cin, message);
    std::cout << "Encoding key? ";
    std::cin >> key;

    std::string encMessage = caeser(message, key);

    if (("" != encMessage)) {
        std::cout << encMessage << std::endl;
    } else {
        return 1;
    }
    return 0;
}

std::string caeser(std::string& s, int key)
{

    char alphabets[26] = { 'A', 'B', 'C', 'D', 'E',
        'F', 'G', 'H', 'I', 'J',
        'K', 'L', 'M', 'N', 'O',
        'P', 'Q', 'R', 'S', 'T',
        'U', 'V', 'W', 'X', 'Y',
        'Z' };
    if (key < 0) {

        int n = sizeof(alphabets) / sizeof(alphabets[0]);
        std::reverse(alphabets, alphabets + n);
        key = key * (-1);
    }

    for (int i = 0; i < s.length(); i++) {
        char inC = s.at(i);
        inC = toupper(inC);

        int j = 0;
        for (j; j < 26; j++) {

            if (inC == alphabets[j]) {

                int pos = j + key;

                while (pos > 25 || pos < 0) {
                    pos = pos - 26;
                }

                // result.append(&alphabets[(j+key)]);
                s[i] = alphabets[pos];
                break;
            } else if (inC == ' ') {

                // result.append(" ");
                s[i] = ' ';
                break;
            }
        }
        if (inC != alphabets[j] && inC != ' ') {

            std::cerr << "Invalid Inputs! Can only contain Alphabets!\n";
            return "";
        }
    }

    return s;
}
