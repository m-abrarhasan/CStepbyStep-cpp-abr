#include <cctype>
#include <iostream>
#include <string>

bool isPalindrome(std::string str)
{
    bool isPalindrome = false;

    std::transform(str.cbegin(), str.cend(), str.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    std::string reved = str;
    std::reverse(reved.begin(), reved.end());

    if (0 == str.compare(reved)) {

        isPalindrome = true;
    }

    return isPalindrome;
}

// Main
///////////////////////////////////////////////////////
int main()
{
    std::cout << isPalindrome("dog god") << std::endl;

    return 0;
}
