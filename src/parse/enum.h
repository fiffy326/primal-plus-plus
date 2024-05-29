#ifndef PARSE_ENUM_H
#define PARSE_ENUM_H

#include <stdexcept>
#include <string>
#include <type_traits>

#include "number.h"

/**
 * Parses a numeric string to its corresponding enum value.
 * @tparam T Enum return type
 * @param text String to parse
 * @return Parsed enum value
 */
template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T>
parse(const std::string& text) {
    auto value = parse<std::underlying_type_t<T>>(text);
    if (value >= static_cast<std::underlying_type_t<T>>(sizeof(T))) {
        throw std::runtime_error("String passed to parse does not have a "
                                 "corresponding enum value.");
    }
    return static_cast<T>(value);
}

#endif // PARSE_ENUM_H
