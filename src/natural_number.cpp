#include "natural_number.h"

#include <cerrno>
#include <cstdlib>
#include <iostream>
#include <string>

#include "error_exit.h"

NN64 parse(const std::string &identifier, const std::string &input) {
    std::string too_large = "The " + identifier + " provided was greater "
            + "than the maximum allowed value (max: "
            + std::to_string(NN64_MAX) + ").";
    std::string too_small = "The " + identifier + " provided was invalid "
            + "or less than the minimum allowed value (min: "
            + std::to_string(NN64_MIN) + ").";

    errno = 0;    // Clear errno before conversion.
    char *endptr; // Next char in string after the numeric value.

    // Convert the input string to an unsigned integer.
    NN64 value = std::strtoull(input.c_str(), &endptr, 10);

    // Verify that the input was a valid natural number.
    if (errno == ERANGE || value > NN64_MAX) {
        error_exit(too_large);
    } else if (*endptr != '\0' || input.empty() || value < NN64_MIN) {
        error_exit(too_small);
    }

    return value;
}

NN64 input(const std::string &identifier, const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    return parse(identifier, input);
}