#include <cctype>
#include <iostream>
#include <string>

size_t dnaErrors(std::string a, std::string b)
{

    size_t errors = { 0 };

    if (a.length() > b.length()) {

        errors = a.length() - b.length();
        a.erase(b.length(), a.length() - 1);

    } else if (a.length() < b.length()) {

        errors = b.length() - a.length();
        b.erase(a.length(), b.length() - 1);
    }

    if (a.length() == b.length()) {

        for (size_t i = 0; i < a.length(); ++i) {

            a[i] = std::toupper(a.at(i));
            b[i] = std::toupper(b.at(i));

            if ('-' == a.at(i)) {
                errors++;
            }
            if ('A' == a.at(i) && b.at(i) != 'T') {

                (a.at(i) == '-' || b.at(i) == '-') ? errors++ : errors += 2;
            }
            if ('T' == a.at(i) && b.at(i) != 'A') {

                (a.at(i) == '-' || b.at(i) == '-') ? errors++ : errors += 2;
            }
            if ('G' == a.at(i) && b.at(i) != 'C') {

                (a.at(i) == '-' || b.at(i) == '-') ? errors++ : errors += 2;
            }
            if ('C' == a.at(i) && b.at(i) != 'G') {

                (a.at(i) == '-' || b.at(i) == '-') ? errors++ : errors += 2;
            }
        }
    }

    // std::cout << a << "\n" << b << std::endl;
    return errors;
}

// Main
///////////////////////////////////////////////////////
int main()
{

    dnaErrors("GGGA-GAATCTCTGGACT", "CTCTACTTA-AGACCGGTACAGG");

    return 0;
}
