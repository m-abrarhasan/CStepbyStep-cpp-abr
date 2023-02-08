#include <cctype>
#include <iostream>
#include <string>

void printBackward(std::string str)
{

    std::reverse(str.begin(), str.end());
    std::cout << str;
}

// Main
///////////////////////////////////////////////////////
int main()
{
    printBackward("hello there!");
    return 0;
}