#ifndef UTILS_GET_FORMAT_SPECIFIER_H
#define UTILS_GET_FORMAT_SPECIFIER_H

#include <cinttypes>
#include <sstream>
#include <string>
#include <type_traits>

/**
 * Gets the printf format specifier a numeric type.
 * @tparam T Numeric type
 * @return Printf format specifier
 */
template <typename T>
typename std::enable_if_t<std::is_arithmetic_v<T>, std::string>
get_format_specifier() {
    if constexpr (std::is_floating_point_v<T>) return 'f';
    if constexpr (std::is_signed_v<T>) {
        if constexpr (std::is_same_v<T, int8_t>) return PRIi8;
        if constexpr (std::is_same_v<T, int16_t>) return PRIi16;
        if constexpr (std::is_same_v<T, int16_t>) return PRIi16;
        if constexpr (std::is_same_v<T, int32_t>) return PRIi32;
        if constexpr (std::is_same_v<T, int64_t>) return PRIi64;
    } else if constexpr (std::is_unsigned_v<T>) {
        if constexpr (std::is_same_v<T, uint8_t>) return PRIu8;
        if constexpr (std::is_same_v<T, uint16_t>) return PRIu16;
        if constexpr (std::is_same_v<T, uint32_t>) return PRIu32;
        if constexpr (std::is_same_v<T, uint64_t>) return PRIu64;
    }
    throw std::runtime_error("Formatting specifier not implemented for type "
                             "passed to get_format_specifier.");
}

#endif // UTILS_GET_FORMAT_SPECIFIER_H
