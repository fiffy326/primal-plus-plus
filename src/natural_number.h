#ifndef PRIMAL_NATURAL_NUMBER_H
#define PRIMAL_NATURAL_NUMBER_H

#include <cstdint>

/* Types to represent natural numbers (positive integers). */
using NN8 = uint8_t;
using NN16 = uint16_t;
using NN32 = uint32_t;
using NN64 = uint64_t;
static const NN8 NN8_MIN = 1; // Natural numbers must be positive.
static const NN16 NN16_MIN = NN8_MIN;
static const NN32 NN32_MIN = NN8_MIN;
static const NN64 NN64_MIN = NN8_MIN;
static const NN8 NN8_MAX = UINT8_MAX;
static const NN16 NN16_MAX = UINT16_MAX;
static const NN32 NN32_MAX = UINT32_MAX;
static const NN64 NN64_MAX = UINT64_MAX - 1; // Allow overflow detection.

#endif // PRIMAL_NATURAL_NUMBER_H
