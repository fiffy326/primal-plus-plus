#include <stdint.h>
#include <stdio.h>
#include "ascii_art.h"
#include "primes.h"

int main(int argc, char** argv) {
    U64 search_ceiling;

    if (argc > 1)
        search_ceiling = parse_search_ceiling(argv[1]);
    else {
        printf("%s\n", ASCII_ART);
        printf("Minimum: %lu\n", MIN_VALUE);
        printf("Maximum: %lu\n\n", MAX_VALUE);
        printf("Search cap: ");
        fflush(stdout);

        char buffer[MAX_DIGITS + 1];
        fgets(buffer, sizeof(buffer), stdin);
        printf("\n");

        search_ceiling = parse_search_ceiling(buffer);
    }
    find_primes(search_ceiling);
    return 0;
}
