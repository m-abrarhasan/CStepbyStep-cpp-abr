#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

std::string coolest(const std::string& path)
{
    std::pair<std::string, size_t> coolest = { "", 0 };

    std::fstream file(path);
    if (file.is_open()) {

        std::map<std::string, std::set<std::string>> accounts;
        std::string name;
        std::string follower;

        while (file >> follower >> name) {

            if (accounts.count(name)) {
                accounts.at(name).insert(follower);

            } else {
                accounts.insert(std::make_pair(name, std::set<std::string> { follower }));
            }
        }
        file.close();

        for (const auto& [id, followers] : accounts) {

            size_t sum = 0;
            for (const auto& f : followers) {

                if (accounts.count(f)) {
                    sum += accounts.at(f).size();
                }
            }
            if (sum > coolest.second) {
                coolest.second = sum;
                coolest.first  = id;

            } else if (sum == coolest.second && id > coolest.first) {
                coolest.second = sum;
                coolest.first  = id;
            }
        }
    }
    return coolest.first;
}

int main(int, char**)
{
    auto var = coolest("../input.txt");
    std::cout << var;
    return 0;
}