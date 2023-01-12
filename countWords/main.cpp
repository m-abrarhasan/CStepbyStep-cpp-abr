#include <iostream>
#include <cctype>

size_t countWords(std::string str)
{
    size_t words = 0;

    // In case of an empty string apending two spaces
    // to make sure index 1 exists
    str.append("  ");

    for (int i = 1; i < str.length(); ++i)
    {
        if (' ' == str.at(i) && ' ' != str.at(i - 1))
        {
            words++;
        }
    }

    return words;
}

// Main
///////////////////////////////////////////////////////
int main()
{
    std::string msg;

    std::cout << "Your String : ";
    std::getline(std::cin, msg);

    size_t words = countWords(msg);

    std::cout << words << std::endl;

    return 0;
}