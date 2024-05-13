#ifndef PRIMES_H
#define PRIMES_H

#include <limits.h>
#include <stdint.h>

/* Constants */
static const uint_fast64_t MAX_DIGITS = 20;            // uint64 max digits
static const uint_fast64_t MIN_VALUE = 1;              // Upper limit min value
static const uint_fast64_t MAX_VALUE = ULLONG_MAX - 1; // Upper limit max value 

/* Enums */
enum Primality { COMPOSITE = 0, PRIME = 1 };

/* Functions */
void find_primes(uint_fast64_t upper_limit);
void find_primes_8(uint_fast8_t upper_limit);
void find_primes_16(uint_fast16_t upper_limit);
void find_primes_32(uint_fast32_t upper_limit);
void find_primes_64(uint_fast64_t upper_limit);
enum Primality is_prime_8(uint_fast8_t candidate);
enum Primality is_prime_16(uint_fast16_t candidate);
enum Primality is_prime_32(uint_fast32_t candidate);
enum Primality is_prime_64(uint_fast64_t candidate);
uint_fast64_t parse_upper_limit(const char* buffer);

#endif
