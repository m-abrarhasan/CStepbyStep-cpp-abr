#include <fstream>
#include <iostream>
#include <string>

double averageValueInFile(const std::string &path) {

  std::ifstream file;
  double sum{0};
  int count{0};
  file.open(path);

  if (!file.is_open()) {
    std::cerr << "error opening file!";
  } else {

    double num;
    while (file >> num) {

      sum += num;
      count++;
    }
  }
  if (count != 0) {
    return sum / count;
  }
  return 0.0;
}

///////////// Main /////////////////
int main(int, char **) {

  std::string filePath = "./numbers.txt";
  std::cout << "Total mean average = " << averageValueInFile(filePath) << "\n";

  return 0;
}