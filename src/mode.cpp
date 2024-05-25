#include "mode.h"

#include <iostream>
#include <string>

Mode parse(const std::string &input) {
    return (Mode)strtol(input.c_str(), nullptr, 10);
}

Mode input(const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    return parse(input);
}
