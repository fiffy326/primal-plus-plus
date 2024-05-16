#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "ascii_art.h"
#include "check_number.h"
#include "find_prime_index.h"
#include "list_primes.h"
#include "parser.h"

void interactive_session(void) {
    printf("%s\n", ASCII_ART);

    switch (request_mode()) {
        case NONE:
            exit(EXIT_SUCCESS);
        case LIST_PRIMES:
            list_primes(request_ceiling());
            break;
        case CHECK_NUMBER:
            check_number(request_number());
            break;
        case FIND_PRIME_INDEX:
            find_prime_index(request_index());
            break;
    }
}

void non_interactive_session(Options* options) {
    switch (options->mode) {
        case NONE:
            fprintf(stderr, "Error: Invalid mode option\n%s", USAGE_MESSAGE);
            exit(EXIT_FAILURE);
            break;
        case LIST_PRIMES:
            list_primes(options->ceiling);
            break;
        case CHECK_NUMBER:
            check_number(options->number);
            break;
        case FIND_PRIME_INDEX:
            find_prime_index(options->index);
            break;
    }
}

int main(int argc, char** argv) {
    Options options;
    parse_options(&options, argc, argv);

    if (options.mode == NONE)
        interactive_session();
    else
        non_interactive_session(&options);

    return 0;
}
