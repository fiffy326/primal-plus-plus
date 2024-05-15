#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

void find_primes(uint_fast64_t upper_limit) {
    if (upper_limit < 2) {
        printf("No primes were found.\n");
        exit(EXIT_SUCCESS);
    }
    printf("Prime #1 = 2\n");

    if (upper_limit <= UINT_FAST8_MAX)
        find_primes_8(upper_limit);
    else if (upper_limit <= UINT_FAST16_MAX)
        find_primes_16(upper_limit);
    else if (upper_limit <= UINT_FAST32_MAX)
        find_primes_32(upper_limit);
    else if (upper_limit <= UINT_FAST64_MAX)
        find_primes_64(upper_limit);
}

void find_primes_8(uint_fast8_t upper_limit) {
    uint_fast8_t found = 2;
    uint_fast8_t candidate = 3;

    while (candidate <= upper_limit) {
        if (is_prime_8(candidate)) {
            printf("Prime #%u = %u\n", found, candidate);
            found++;
        }
        candidate += 2;
    }
}

void find_primes_16(uint_fast16_t upper_limit) {
    uint_fast16_t found = 2;
    uint_fast16_t candidate = 3;

    while (candidate <= upper_limit) {
        if (is_prime_16(candidate)) {
            printf("Prime #%lu = %lu\n", found, candidate);
            found++;
        }
        candidate += 2;
    }
}

void find_primes_32(uint_fast32_t upper_limit) {
    uint_fast32_t found = 2;
    uint_fast32_t candidate = 3;

    while (candidate <= upper_limit) {
        if (is_prime_32(candidate)) {
            printf("Prime #%lu = %lu\n", found, candidate);
            found++;
        }
        candidate += 2;
    }
}

void find_primes_64(uint_fast64_t upper_limit) {
    uint_fast64_t found = 2;
    uint_fast64_t candidate = 3;

    while (candidate <= upper_limit) {
        if (is_prime_64(candidate)) {
            printf("Prime #%lu = %lu\n", found, candidate);
            found++;
        }
        candidate += 2;
    }
}

enum Primality is_prime_8(uint_fast8_t candidate) {
    uint_fast8_t divisor_max = sqrt(candidate);
    uint_fast8_t divisor = 3;

    if (!(candidate % 2)) return COMPOSITE;

    while (divisor <= divisor_max) {
        if (!(candidate % divisor)) return COMPOSITE;
        divisor += 2;
    }
    return PRIME;
}

enum Primality is_prime_16(uint_fast16_t candidate) {
    uint_fast16_t divisor_max = sqrt(candidate);
    uint_fast16_t divisor = 3;

    if (!(candidate % 2)) return COMPOSITE;

    while (divisor <= divisor_max) {
        if (!(candidate % divisor)) return COMPOSITE;
        divisor += 2;
    }
    return PRIME;
}

enum Primality is_prime_32(uint_fast32_t candidate) {
    uint_fast32_t divisor_max = sqrt(candidate);
    uint_fast32_t divisor = 3;

    if (!(candidate % 2)) return COMPOSITE;

    while (divisor <= divisor_max) {
        if (!(candidate % divisor)) return COMPOSITE;
        divisor += 2;
    }
    return PRIME;
}

enum Primality is_prime_64(uint_fast64_t candidate) {
    uint_fast64_t divisor_max = sqrt(candidate);
    uint_fast64_t divisor = 3;

    if (!(candidate % 2)) return COMPOSITE;

    while (divisor <= divisor_max) {
        if (!(candidate % divisor)) return COMPOSITE;
        divisor += 2;
    }
    return PRIME;
}

uint_fast64_t parse_upper_limit(const char* buffer) {
    uint_fast64_t upper_limit;

    if ((upper_limit = strtoull(buffer, NULL, 10)) > MAX_VALUE) {
        fprintf(stderr, "Error: The upper limit provided was above the maximum "
                "allowed value (max: %lu)\n", MAX_VALUE);
        exit(EXIT_FAILURE);
    }
    if (!upper_limit) {
        fprintf(stderr, "Error: The upper limit provided was invalid or below "
                "the minimum allowed value (min: %lu)\n", MIN_VALUE);
        exit(EXIT_FAILURE);
    }
    return upper_limit;
}
