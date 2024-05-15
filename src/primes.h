#ifndef PRIMES_H
#define PRIMES_H

#include <limits.h>
#include <stdint.h>

/* Typedefs */
typedef uint_fast8_t U8;
typedef uint_fast16_t U16;
typedef uint_fast32_t U32;
typedef uint_fast64_t U64;

/* Enums */
enum Primality { COMPOSITE = 0, PRIME = 1 };

/* Constants */
static const U64 MAX_DIGITS = 20;            // U64 max # of digits
static const U64 MIN_VALUE = 1;              // Search ceiling min value
static const U64 MAX_VALUE = ULLONG_MAX - 1; // Search ceiling max value 

/* Functions */
void find_primes(U64 search_ceiling);
void find_primes_8(U8 search_ceiling);
void find_primes_16(U16 search_ceiling);
void find_primes_32(U32 search_ceiling);
void find_primes_64(U64 search_ceiling);
enum Primality is_prime_8(U8 n);
enum Primality is_prime_16(U16 n);
enum Primality is_prime_32(U32 n);
enum Primality is_prime_64(U64 n);
U64 parse_search_ceiling(const char* buffer);

#endif
