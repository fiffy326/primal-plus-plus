#ifndef PRIMAL_NATURAL_NUMBER_H
#define PRIMAL_NATURAL_NUMBER_H

#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <string>

#include "parser.h"

using NN8 = uint8_t;
using NN16 = uint16_t;
using NN32 = uint32_t;
using NN64 = uint64_t;
static const NN8 NN8_MIN = 1; // The natural numbers do not include zero.
static const NN16 NN16_MIN = NN8_MIN;
static const NN32 NN32_MIN = NN8_MIN;
static const NN64 NN64_MIN = NN8_MIN;
static const NN8 NN8_MAX = UINT8_MAX;
static const NN16 NN16_MAX = UINT16_MAX;
static const NN32 NN32_MAX = UINT32_MAX;
static const NN64 NN64_MAX = UINT64_MAX - 1; // Allow detection of overflow.

/**
 * Parses a numeric string to a natural number type.
 * @tparam T Natural number return type
 * @param input Numeric input string to parse
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

#endif // PRIMAL_NATURAL_NUMBER_H
