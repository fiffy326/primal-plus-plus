#ifndef PRIMAL_PARSER_H
#define PRIMAL_PARSER_H

#include <cerrno>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#include "command.h"
#include "natural_number.h"

/**
 * Parses a numeric string to a natural number type.
 * @tparam T Natural number return type
 * @param input Numeric input string
 * @return Parsed natural number value
 */
template<typename T = NN64>
T parse(const std::string &input) {
    NN8 lower_limit = NN8_MIN;
    NN64 upper_limit = (std::numeric_limits<T>::max() < NN64_MAX) ?
                       std::numeric_limits<T>::max() : NN64_MAX;

    errno = 0; // Clear errno before conversion;
    char *end; // Next char in string after numeric value.

    // Convert input string to an unsigned integer.
    NN64 value = std::strtoull(input.c_str(), &end, 10);

    // Make sure input was a valid natural number (non-zero unsigned integer).
    if (errno == ERANGE || value > upper_limit) {
        throw std::runtime_error("Value passed to parse was too large.");
    } else if (*end != '\0' || input.empty() || value < lower_limit) {
        throw std::runtime_error("Value passed to parse was too small "
                                 "or was not a valid natural number.");
    } else {
        return static_cast<T>(value);
    }
}

/**
 * Parses a numeric string to a Command enum type.
 * @param input Numeric input string
 * @return Parsed Command enum value
 */
template <> Command parse(const std::string &input);

/**
 * Prompts the user for input, then parses it.
 * @tparam T Return type
 * @param prompt Prompt to show the user
 * @return Parsed value
 */
template <typename T = NN64>
T input(const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return parse<T>(input);
}

#endif // PRIMAL_PARSER_H
