#include <iostream>
#include <regex>
#include <string>

int main(int argc, char *argv[]) {
  uint64_t output = 0, number = 0;
  std::string input;
  bool is_correct = true;
  std::regex regex("(\\+)?0*\\d{1,19}(\\\\n)?");
  std::cin >> input;
  if (std::regex_match(input, regex)) {
    std::string temp_input = std::regex_replace(input, std::regex("[\\D]"), "");
    number = std::stoull(temp_input);
    if (number < 1 || number > INT64_MAX) {
      is_correct = false;
    }
  } else {
    is_correct = false;
  }
  if (is_correct) {
    uint64_t square = uint64_t(std::sqrt(number * 8 + 1));
    if (square * square == (number * 8 + 1)) {
      output = (square - 1) / 2;
    }
  } 
  std::cout << output << std::endl;
  return 0;
}