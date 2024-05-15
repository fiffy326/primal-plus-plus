#include <stdint.h>
#include <stdio.h>
#include "ascii_art.h"
#include "primes.h"

int main(int argc, char** argv) {
    U64 search_cap;

    if (argc > 1)
        search_cap = parse_search_cap(argv[1]);
    else {
        printf("%s\n", ASCII_ART);
        printf("Minimum: %lu\n", MIN_VALUE);
        printf("Maximum: %lu\n\n", MAX_VALUE);
        printf("Search cap: ");

        char buffer[MAX_DIGITS + 1];
        fgets(buffer, sizeof(buffer), stdin);
        printf("\n");

        search_cap = parse_search_cap(buffer);
    }
    find_primes(search_cap);
    return 0;
}
