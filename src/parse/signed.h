#ifndef PARSE_SIGNED_H
#define PARSE_SIGNED_H

#include <cerrno>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>
#include <type_traits>

/**
 * Parses a string to a signed integer type.
 * @tparam T Signed integer return type
 * @param text String to parse
 * @return Parsed signed integer value
 */
template <typename T>
typename std::enable_if<std::is_signed<T>::value, T>::type
parse(const std::string& text) {
    T type_min = std::numeric_limits<T>::min();
    T type_max = std::numeric_limits<T>::max();

    errno = 0; // Clear errno before conversion.
    char* end; // Next char in string after numeric value.

    // Convert input string to a signed integer.
    T value = std::strtoll(text.c_str(), &end, 10);

    // Make sure the text was a valid integer.
    if (errno == ERANGE || value > type_max) {
        throw std::runtime_error("Value of signed integer passed to parse was "
                                 "too large.");
    } else if (*end != '\0' || text.empty() || value < type_min) {
        throw std::runtime_error("Value of signed integer passed to parse was "
                                 "too small or was not a valid signed integer."
                                 );
    }
}

#endif // PARSE_SIGNED_H
