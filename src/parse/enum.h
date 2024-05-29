#ifndef PARSE_ENUM_H
#define PARSE_ENUM_H

#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <type_traits>

#include "unsigned.h"

/**
 * Parses a numeric string to an enum type.
 * @tparam T Enum return type
 * @param text String to parse
 * @return Parsed enum value
 */
template <typename T>
typename std::enable_if<std::is_enum<T>::value, T>::type
parse(const std::string& text) {
    uint64_t value = parse<uint64_t>(text);
    if (value < sizeof(T)) {
        return static_cast<T>(value);
    }
    throw std::runtime_error("Value passed to parse was not an enum value.");
}

#endif // PARSE_ENUM_H
