#include <cctype>
#include <iostream>
#include <string>

std::string reverseChunks(std::string str, const unsigned int p)
{

    if (str.empty()) {
        return str;
    }

    size_t lo = str.length() % p;
    size_t t = str.length() - lo;

    std::string nstr;
    nstr.reserve(str.length());

    for (long long i = t - p; i >= 0; i -= p) {
        nstr.append(str.substr(i, p));
    }
    std::reverse(nstr.begin(), nstr.end());

    if (lo > 0) {
        nstr.append(str.substr(t, lo));
    }
    return nstr;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    std::cout << reverseChunks("KeithSchwarz", 5);

    return 0;
}