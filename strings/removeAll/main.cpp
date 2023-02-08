#include <cctype>
#include <iostream>
#include <string>

std::string removeAll(std::string str, const char& t)
{

    auto strlen = str.length();

    size_t i = 0;
    while (i < strlen) {

        std::cout << str[i] << " | " << t << "   " << strlen << "\n";
        if (str.at(i) == t) {

            str.erase(i, 1);
            strlen--;

        } else
            i++;
    }

    return str;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    std::string msg = removeAll("---0---", '-');

    std::cout << msg;
    return 0;
}