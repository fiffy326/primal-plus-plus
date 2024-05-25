#include <iostream>

#include "ascii_art.h"
#include "error_exit.h"
#include "mode.h"
#include "natural_number.h"
#include "options.h"
#include "primality.h"

void interactive_session() {
    std::cout << ASCII_ART << '\n'
    << "[1] List every prime below a ceiling.\n"
    << "[2] Find the Nth prime in the series.\n"
    << "[3] Perform a primality test on a number.\n" << std::endl;
    switch (input("Mode: ")) {
        case LIST_PRIMES:
            list_primes(input("ceiling", "Ceiling: "));
            break;
        case FIND_NTH_PRIME:
            find_nth_prime(input("index", "Index: "));
            break;
        case TEST_NUMBER:
            test_number(input("number", "Number: "));
            break;
        default:
            error_exit("Invalid mode.");
    }
}

void non_interactive_session(Options *options) {
    switch (options->mode) {
        case LIST_PRIMES:
            list_primes(options->ceiling);
            break;
        case FIND_NTH_PRIME:
            find_nth_prime(options->index);
            break;
        case TEST_NUMBER:
            test_number(options->number);
            break;
        default:
            error_exit("Invalid mode.");
    }
}

int main(int argc, char **argv) {
    Options options;
    parse_options(&options, argc, argv);

    if (options.mode == NONE) {
        interactive_session();
    } else {
        non_interactive_session(&options);
    }

    return 0;
}
