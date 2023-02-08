#include <cctype>
#include <iostream>
#include <string>

bool isRotation(const std::string str_A, const std::string str_B)
{
    bool isRotation = false;

    if (str_A.compare(str_B) == 0) {
        return isRotation = true;
    } else if (str_A.length() == 0 || str_B.length() == 0) {
        return isRotation;
    }
    size_t pos = str_B.find(str_A.at(0), 0);

    if (pos != std::string::npos && str_B.length() == str_A.length()) {

        std::string nstr_B;
        nstr_B.append(str_B.substr(pos, str_B.length() - 1)); // starting from pos
        nstr_B.append(str_B.substr(0, pos)); // pos amount of char taken

        if (str_A.compare(nstr_B) == 0) {

            return isRotation = true;
        }
    }
    return isRotation;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    std::cout << isRotation("abcde", "deabc") << std::endl;

    return 0;
}