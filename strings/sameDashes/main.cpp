#include <cctype>
#include <iostream>
#include <string>

bool sameDashes(const std::string& a_str, const std::string& b_str)
{

    std::string b = (a_str.length() >= b_str.length()) ? a_str : b_str;
    std::string l = (a_str.length() >= b_str.length()) ? b_str : a_str;

    bool is_Same = true;
    for (size_t i = 0; i < b.length(); i++) {

        try {
            if (b.at(i) == '-') {
                is_Same = (l.at(i) == '-') ? true : false;
            }
            if (std::string::npos == b.find('-') && std::string::npos != l.find('-')) {
                return false;
            }
        } catch (const std::out_of_range& e) {
            return false;
        }
    }

    return is_Same;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    if (sameDashes("1st-has-more-characters", "2nd-has-less")) {

        std::cout << "TRUE\n";
    } else
        std::cout << "FALSE\n";

    return 0;
}