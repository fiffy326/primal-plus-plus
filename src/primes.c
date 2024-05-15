#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

void find_primes(U64 cap) {
    if (cap < 2) {
        printf("No primes were found.\n");
        exit(EXIT_SUCCESS);
    }
    printf("Prime #1 = 2\n");

    if (cap <= UINT_FAST8_MAX)
        find_primes_8(cap);
    else if (cap <= UINT_FAST16_MAX)
        find_primes_16(cap);
    else if (cap <= UINT_FAST32_MAX)
        find_primes_32(cap);
    else if (cap <= UINT_FAST64_MAX)
        find_primes_64(cap);
}

void find_primes_8(U8 cap) {
    U8 found = 2;
    U8 n = 3;

    while (n <= cap) {
        if (is_prime_8(n)) {
            printf("Prime #%u = %u\n", found, n);
            found++;
        }
        n += 2;
    }
}

void find_primes_16(U16 cap) {
    U16 found = 2;
    U16 n = 3;

    while (n <= cap) {
        if (is_prime_16(n)) {
            printf("Prime #%lu = %lu\n", found, n);
            found++;
        }
        n += 2;
    }
}

void find_primes_32(U32 cap) {
    U32 found = 2;
    U32 n = 3;

    while (n <= cap) {
        if (is_prime_32(n)) {
            printf("Prime #%lu = %lu\n", found, n);
            found++;
        }
        n += 2;
    }
}

void find_primes_64(U64 cap) {
    U64 found = 2;
    U64 n = 3;

    while (n <= cap) {
        if (is_prime_64(n)) {
            printf("Prime #%lu = %lu\n", found, n);
            found++;
        }
        n += 2;
    }
}

enum Primality is_prime_8(U8 n) {
    U8 div_max = sqrt(n);
    U8 div = 3;

    if (!(n % 2)) return COMPOSITE;
    while (div <= div_max) {
        if (!(n % div)) return COMPOSITE;
        div += 2;
    }
    return PRIME;
}

enum Primality is_prime_16(U16 n) {
    U16 div_max = sqrt(n);
    U16 div = 3;

    if (!(n % 2)) return COMPOSITE;
    while (div <= div_max) {
        if (!(n % div)) return COMPOSITE;
        div += 2;
    }
    return PRIME;
}

enum Primality is_prime_32(U32 n) {
    U32 div_max = sqrt(n);
    U32 div = 3;

    if (!(n % 2)) return COMPOSITE;
    while (div <= div_max) {
        if (!(n % div)) return COMPOSITE;
        div += 2;
    }
    return PRIME;
}

enum Primality is_prime_64(U64 n) {
    U64 div_max = sqrt(n);
    U64 div = 3;

    if (!(n % 2)) return COMPOSITE;
    while (div <= div_max) {
        if (!(n % div)) return COMPOSITE;
        div += 2;
    }
    return PRIME;
}

U64 parse_search_cap(const char* buffer) {
    U64 cap;

    if ((cap = strtoull(buffer, NULL, 10)) > MAX_VALUE) {
        fprintf(stderr, "Error: The search cap provided was above the maximum "
                "allowed value (max: %lu)\n", MAX_VALUE);
        exit(EXIT_FAILURE);
    }
    if (!cap) {
        fprintf(stderr, "Error: The search cap provided was invalid or below "
                "the minimum allowed value (min: %lu)\n", MIN_VALUE);
        exit(EXIT_FAILURE);
    }
    return cap;
}
