#include <stdint.h>
#include <stdio.h>
#include "ascii_art.h"
#include "primes.h"

int main(int argc, char** argv) {
    uint_fast64_t upper_limit;

    if (argc > 1)
        upper_limit = parse_upper_limit(argv[1]);
    else {
        printf("%s\n", ASCII_ART);
        printf("Minimum: %lu\n", MIN_VALUE);
        printf("Maximum: %lu\n\n", MAX_VALUE);
        printf("Upper limit: ");

        char buffer[MAX_DIGITS + 1];
        fgets(buffer, sizeof(buffer), stdin);
        printf("\n");

        upper_limit = parse_upper_limit(buffer);
    }
    find_primes(upper_limit);
    return 0;
}
