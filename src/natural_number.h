#ifndef NATURAL_NUMBER_H
#define NATURAL_NUMBER_H

#include <cstdint>
#include <string>

/* Typedefs */
using NN08 = uint_fast8_t;
using NN16 = uint_fast16_t;
using NN32 = uint_fast32_t;
using NN64 = uint_fast64_t;

/* Constants */
static const NN64 NN64_MIN = 1;
static const NN64 NN64_MAX = UINT_FAST64_MAX - 1; // Allow overflow detection

/* Functions */
NN64 parse(const std::string &identifier, const std::string &input);
NN64 input(const std::string &identifier, const std::string &prompt);

#endif // NATURAL_NUMBER_H
