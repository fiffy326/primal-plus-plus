#ifndef PRIMAL_PARSER_H
#define PRIMAL_PARSER_H

#include <iostream>
#include <string>

/**
 * Parses a string.
 * @tparam T Return type
 * @param input String to parse
 * @return Parsed value
 */
template <typename T>
T parse(const std::string &input);

/**
 * Prompts the user for input then parses it.
 * @tparam T Return type
 * @param prompt Prompt to display
 * @return Parsed input value
 */
template <typename T>
T input(const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    std::cout << std::endl;
    return parse<T>(input);
}

#endif // PRIMAL_PARSER_H
