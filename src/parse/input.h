#ifndef PARSE_INPUT_H
#define PARSE_INPUT_H

#include <iostream>
#include <string>

#include "enum.h"
#include "number.h"

/**
 * Prompts the user for input then parses it.
 * @tparam T Return type
 * @param prompt Prompt to display
 * @return Parsed input value
 */
template <typename T>
T input(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    std::cout << '\n';
    return parse<T>(input);
}

#endif // PARSE_INPUT_H
