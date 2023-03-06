#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>

void wordStatsPlus(const std::string path)
{
    std::unordered_set<char> unique_letters;
    size_t total_lines         = 0;
    size_t total_words         = 0;
    size_t total_word_length   = 0;
    double avg_word_length     = 0;
    double avg_words_per_line  = 0;
    double unique_letters_perc = 0;

    std::ifstream file(path);
    if (file.is_open()) {

        std::string line;
        while (std::getline(file, line)) {

            total_lines++;

            std::stringstream data(line);
            std::string word;
            while (data >> word) {

                total_words++;
                total_word_length += word.length();

                for (auto const& c : word) {
                    char u = std::toupper(c);
                    if (std::isalpha(u)) {

                        unique_letters.insert(u);
                    }
                }
            }
        }
        avg_word_length     = total_word_length / static_cast<double>(total_words);
        avg_words_per_line  = total_words / static_cast<double>(total_lines);
        unique_letters_perc = (unique_letters.size() / (double)26) * 100;

        ////output----
        std::cout << "Total lines = " << total_lines << "\n";
        std::cout << "Total words = " << total_words << "\n";
        std::cout << "Total unique letters = " << unique_letters.size()
                  << " ("
                  << std::floor(unique_letters_perc)
                  << "\% of alphabet)\n";
        std::cout << "Average words/line = " << avg_words_per_line << "\n";
        std::cout << "Average word length = " << avg_word_length;

    } else {
        std::cout << "Error, bad input file.";
    }
}

int main(int, char**)
{
    wordStatsPlus("../input.txt");
    return 0;
}