#include "command.h"

/**
 * Parses a numeric string to a Command enum type.
 * @param input Numeric input string to parse
 * @return Parsed Command enum value
 */
template <>
Command parse(const std::string &input) {
    return static_cast<Command>(strtol(input.c_str(), nullptr, 10));
}
