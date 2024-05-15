#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "primes.h"

void find_primes(U64 search_ceiling) {
    if (search_ceiling < 2) {
        printf("No primes were found.\n");
        exit(EXIT_SUCCESS);
    }
    printf("Prime #1 = 2\n");
    printf("Prime #2 = 3\n");

    if (search_ceiling <= UINT_FAST8_MAX)
        find_primes_8(search_ceiling);
    else if (search_ceiling <= UINT_FAST16_MAX)
        find_primes_16(search_ceiling);
    else if (search_ceiling <= UINT_FAST32_MAX)
        find_primes_32(search_ceiling);
    else if (search_ceiling <= UINT_FAST64_MAX)
        find_primes_64(search_ceiling);
}

void find_primes_8(U8 search_ceiling) {
    U8 found = 3;
    for (U8 n=5; n<=search_ceiling; n+=2) {
        if (is_prime_8(n)) {
            printf("Prime #%u = %u\n", found, n);
            found++;
        }
    }
}

void find_primes_16(U16 search_ceiling) {
    U16 found = 3;
    for (U16 n=5; n<=search_ceiling; n+=2) {
        if (is_prime_16(n)) {
            printf("Prime #%u = %u\n", found, n);
            found++;
        }
    }
}

void find_primes_32(U32 search_ceiling) {
    U32 found = 3;
    for (U32 n=5; n<=search_ceiling; n+=2) {
        if (is_prime_32(n)) {
            printf("Prime #%u = %u\n", found, n);
            found++;
        }
    }
}

void find_primes_64(U64 search_ceiling) {
    U64 found = 3;
    for (U64 n=5; n<=search_ceiling; n+=2) {
        if (is_prime_64(n)) {
            printf("Prime #%lu = %lu\n", found, n);
            found++;
        }
    }
}

enum Primality is_prime_8(U8 n) {
    if ((!(n % 2)) || (!(n % 3))) return COMPOSITE;
    for (U8 div=5; div*div<=n; div+=6) {
        if (!(n % div) || (!(n % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

enum Primality is_prime_16(U16 n) {
    if ((!(n % 2)) || (!(n % 3))) return COMPOSITE;
    for (U16 div=5; div*div<=n; div+=6) {
        if (!(n % div) || (!(n % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

enum Primality is_prime_32(U32 n) {
    if ((!(n % 2)) || (!(n % 3))) return COMPOSITE;
    for (U32 div=5; div*div<=n; div+=6) {
        if (!(n % div) || (!(n % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

enum Primality is_prime_64(U64 n) {
    if ((!(n % 2)) || (!(n % 3))) return COMPOSITE;
    for (U64 div=5; div*div<=n; div+=6) {
        if (!(n % div) || (!(n % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

U64 parse_search_ceiling(const char* buffer) {
    U64 search_ceiling;

    if ((search_ceiling = strtoull(buffer, NULL, 10)) > MAX_VALUE) {
        fprintf(stderr, "Error: The search ceiling provided was above the "
                "maximum allowed value (max: %lu)\n", MAX_VALUE);
        exit(EXIT_FAILURE);
    }
    if (!search_ceiling) {
        fprintf(stderr, "Error: The search ceiling provided was invalid or "
                "below the minimum allowed value (min: %lu)\n", MIN_VALUE);
        exit(EXIT_FAILURE);
    }
    return search_ceiling;
}
