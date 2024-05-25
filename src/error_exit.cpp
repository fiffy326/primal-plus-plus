#include "error_exit.h"

#include <cstdlib>
#include <iostream>
#include <string>

void error_exit(const std::string &message) {
    std::cerr << "Error: " << message << std::endl;
    std::exit(EXIT_FAILURE);
}
