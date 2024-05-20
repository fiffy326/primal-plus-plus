#ifndef UNSIGNED_H
#define UNSIGNED_H

#include <string>

#include <cstdint>

/* Typedefs */
typedef uint_fast8_t U8;
typedef uint_fast16_t U16;
typedef uint_fast32_t U32;
typedef uint_fast64_t U64;

/* Constants */
static const U64 U64_MIN = 1;
static const U64 U64_MAX = UINT_FAST64_MAX - 1;

/* Functions */
U64 parse_unsigned(const std::string& arg_input, const std::string& arg_name);
U64 prompt_unsigned(const std::string& arg_name, const std::string& prompt);

#endif // UNSIGNED_H