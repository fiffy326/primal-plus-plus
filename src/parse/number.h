#ifndef PARSE_NUMBER_H
#define PARSE_NUMBER_H

#include <cerrno>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>
#include <type_traits>

/**
 * Parses a string to a numeric type.
 * @tparam T Numeric type
 * @param text String to parse
 * @return Parsed numeric value
 */
template <typename T>
typename std::enable_if_t<std::is_arithmetic_v<T>, T>
parse(const std::string& text) {
    T type_min = std::numeric_limits<T>::min();
    T type_max = std::numeric_limits<T>::max();

    errno = 0; // Clear errno before conversion.
    char* end; // Next char in string after numeric value.

    // Convert the string to the desired numeric type.
    T value;
    if constexpr (std::is_floating_point_v<T>) {
        value = strtold(text.c_str(), &end);
    } else if constexpr (std::is_signed_v<T>) {
        value = strtoll(text.c_str(), &end, 10);
    } else {
        value = strtoull(text.c_str(), &end, 10);
    }

    // Validate the input before returning the parsed value.
    if (text.empty()) {
        throw std::runtime_error("String passed to parse was empty.");
    } else if (*end != '\0') {
        throw std::runtime_error("String passed to parse was truncated.");
    } else if (errno == ERANGE || value < type_min || value > type_max) {
        throw std::runtime_error("String passed to parse was out of range.");
    }
    return static_cast<T>(value);
}

#endif // PARSE_NUMBER_H
