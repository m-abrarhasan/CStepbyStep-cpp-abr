#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

auto hoursWorked(const std::string& path) -> void
{
    std::ifstream file(path);
    if (!file) {
        std::exit(0);
    }

    size_t id = 0;
    std::string name;
    std::string line;

    while (std::getline(file, line)) {

        // read in id,name,total-hours
        std::istringstream ls(line);
        if (!(ls >> id >> name)) {

            std::cerr << "err reading file";
            continue;
        }

        size_t days  = 0;
        double hours = 0;
        double temp  = 0;
        while (ls >> temp) {

            hours += temp;
            days++;
        }
        double perday = hours / (double)days;

        // printf("%zu\t|\t%s\t= %f hours & (%f/day)\n", id, name.c_str(), hours, perday);
        // output
        auto bakout = std::cout.flags();

        std::cout << std::left << std::setw(9) << name
                  << "(ID# " << std::setw(4) << std::right << id << ")"
                  << " worked " << std::fixed << std::setprecision(1) << hours << " hours"
                  << " (" << std::fixed << std::setprecision(2) << perday << "/day)\n";
    }
}

int main(int, char**)
{
    hoursWorked("input.txt");
    return 0;
}