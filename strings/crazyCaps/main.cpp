#include <cctype>
#include <iostream>
#include <string>

void crazyCaps(std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i) {

        str[i] = (i % 2 == 0) ? std::tolower(str[i]) : std::toupper(str[i]);
    }
}

// Main
///////////////////////////////////////////////////////
int main()
{
    std::string msg;

    std::cout << "Your String : ";
    std::getline(std::cin, msg);

    crazyCaps(msg);

    std::cout << msg << std::endl;

    return 0;
}