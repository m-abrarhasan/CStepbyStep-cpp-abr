#include <cctype>
#include <iostream>
#include <string>

// Main
///////////////////////////////////////////////////////
int main()
{

    std::string first_nm;
    std::string last_nm;

    std::cout << "What is your name? ";
    std::cin >> first_nm;
    std::cin >> last_nm;

    if (first_nm != "" && "" != last_nm) {

        std::cout << first_nm + ", " + first_nm + ", bo-B" + first_nm.substr(1) + "\nBanana-fana fo-F" + first_nm.substr(1) + "\nFee-fi-mo-M" + first_nm.substr(1) + "\n";
        std::transform(first_nm.cbegin(), first_nm.cend(), first_nm.begin(),
            [](unsigned char c) { return std::toupper(c); });
        std::cout << first_nm + "!\n\n";

        std::cout << last_nm + ", " + last_nm + ", bo-B" + last_nm.substr(1) + "\nBanana-fana fo-F" + last_nm.substr(1) + "\nFee-fi-mo-M" + last_nm.substr(1) + "\n";
        std::transform(last_nm.cbegin(), last_nm.cend(), last_nm.begin(),
            [](unsigned char c) { return std::toupper(c); });
        std::cout << last_nm + "!";

    } else
        return 1;

    return 0;
}
///////////////////////////////////////////////////////