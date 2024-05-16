#ifndef UNSIGNED_H
#define UNSIGNED_H

#include <limits.h>
#include <stdint.h>

/* Typedefs */
typedef uint_fast8_t U8;
typedef uint_fast16_t U16;
typedef uint_fast32_t U32;
typedef uint_fast64_t U64;

/* Constants */
static const U8 U8_MIN = 1;
static const U8 U8_MAX = UINT_FAST8_MAX;
static const U16 U16_MIN = 1;
static const U16 U16_MAX = UINT_FAST16_MAX;
static const U32 U32_MIN = 1;
static const U32 U32_MAX = UINT_FAST32_MAX;
static const U64 U64_MIN = 1;
static const U64 U64_MAX = UINT_FAST64_MAX;

#endif
