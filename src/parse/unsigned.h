#ifndef PARSE_UNSIGNED_H
#define PARSE_UNSIGNED_H

#include <cerrno>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>
#include <type_traits>

/**
 * Parses a string to an unsigned integer type.
 * @tparam T Unsigned integer return type
 * @param text String to parse
 * @return Parsed unsigned integer value
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, T>::type
parse(const std::string& text) {
    T type_max = std::numeric_limits<T>::max();

    errno = 0; // Clear errno before conversion.
    char* end; // Next char in string after numeric value.

    // Convert input string to an unsigned integer.
    T value = std::strtoull(text.c_str(), &end, 10);

    // Make sure the text was a valid unsigned integer.
    if (errno == ERANGE || value > type_max) {
        throw std::runtime_error("Value passed to parse was too large.");
    } else if (*end != '\0' || text.empty()) {
        throw std::runtime_error("Value passed to parse was not a valid "
                                 "unsigned integer.");
    } else {
        return static_cast<T>(value);
    }
}

#endif // PARSE_UNSIGNED_H
