#include <iostream>

#include <cstdlib>

#include "ascii_art.h"
#include "error_exit.h"
#include "mode.h"
#include "options.h"
#include "primality.h"
#include "unsigned.h"

using std::cout;
using std::endl;
using std::exit;

/**
 * Compute primes interactively using user input
 */
void interactive_session() {
    cout << ASCII_ART << endl;
    cout << "[1] Compute every prime below a given ceiling value" << endl;
    cout << "[2] Compute the prime at a given index in the series" << endl;
    cout << "[3] Perform a primality test on a given candidate integer" << endl
         << endl;
    switch (prompt_mode()) {
        case NONE:
            error_exit("Invalid mode");
            break;
        case LIST_TERMS:
            list_terms(prompt_unsigned("ceiling", "Ceiling: "));
            break;
        case FIND_NTH_TERM:
            find_nth_term(prompt_unsigned("index", "Index: "));
            break;
        case TEST_CANDIDATE:
            test_candidate(prompt_unsigned("candidate", "Candidate: "));
            break;
    }
}

/**
 * Compute primes non-interactively using the command line options
 * @param options Struct of parsed command line options
 */
void non_interactive_session(Options* options) {
    switch (options->mode) {
        case NONE:
            error_exit("Invalid mode");
            break;
        case LIST_TERMS:
            list_terms(options->ceiling);
            break;
        case FIND_NTH_TERM:
            find_nth_term(options->index);
            break;
        case TEST_CANDIDATE:
            test_candidate(options->candidate);
            break;
    }
}

/**
 * Parses the command line arguments and starts a session accordingly
 * @param argc Number of arguments passed to the program
 * @param argv Arguments passed to the program
 * @return 0 on successful termination
 */
int main(int argc, char** argv) {
    Options options;
    parse_options(&options, argc, argv);

    if (options.mode == NONE) {
        interactive_session();
    } else {
        non_interactive_session(&options);
    }

    return 0;
}