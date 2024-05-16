#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <getopt.h>
#include "ascii_art.h"

using std::cerr, std::cin, std::cout, std::endl, std::string, std::to_string;

/* Typedefs */
typedef uint_fast8_t UINT8;
typedef uint_fast16_t UINT16;
typedef uint_fast32_t UINT32;
typedef uint_fast64_t UINT64;

/* Enums */
typedef enum { COMPOSITE, PRIME } Primality;
typedef enum { NONE, LIST_TERMS, FIND_NTH_TERM, TEST_CANDIDATE } Mode;

/* Structs */
typedef struct {
    Mode mode;
    UINT64 ceiling;
    UINT64 index;
    UINT64 candidate;
} Options;

string usage_message(const string& program_name) {
    return "Usage: " + program_name + " [-?] [-c ceiling] [-i index] "
        + "[-t candidate]";
}

void error_exit(string error_message) {
    cerr << error_message << endl;
    exit(EXIT_FAILURE);
}

Mode parse(const string& arg_input) {
    Mode mode = (Mode)strtol(arg_input.c_str(), nullptr, 10);
    if ((mode == NONE) || (mode > sizeof(Mode) - 1))
        error_exit("Error: Invalid mode");
    return mode;
}

UINT64 parse(const string& arg_input, const string& arg_name) {
    string too_large = "Error: The " + arg_name + " provided was greater than "
        + "the maximum allowed value (max: " + to_string(UINT64_MAX) + ")";

    string too_small = "Error: The " + arg_name + " provided was invalid or "
        + "less than the minimum allowed value (min: " + to_string(1) + ")";

    UINT64 value;
    if ((value = strtoull(arg_input.c_str(), nullptr, 10)) > UINT64_MAX)
        error_exit(too_large);
    if (!value)
        error_exit(too_small);
    return value;
}

void parse(Options* options, int argc, char** argv) {
    options->mode = NONE;
    options->ceiling = 0;
    options->index = 0;
    options->candidate = 0;
    int opt;
    while ((opt = getopt(argc, argv, ":c:i:t:")) != -1) {
        switch (opt) {
            case ':':
            case 'c':
                options->mode = LIST_TERMS;
                options->ceiling = parse(optarg, "ceiling");
                break;
            case 'i':
                options->mode = FIND_NTH_TERM;
                options->index = parse(optarg, "index");
                break;
            case 't':
                options->mode = TEST_CANDIDATE;
                options->candidate = parse(optarg, "candidate");
                break;
            case '?':
                cout << usage_message(argv[0]) << endl;
                exit(EXIT_SUCCESS);
            default:
                error_exit("Error: Invalid options");
        }
    }
    int extra_args = argc - optind;
    if (extra_args)
        error_exit("Error: Invalid arguments");
}

UINT64 prompt(const string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    return parse(input, prompt);
}

Mode prompt() {
    cout << "Mode: ";
    string input;
    cin >> input;
    return parse(input);
}

template <typename T>
Primality primality_test(T number) {
    if (number == 1) return COMPOSITE;
    if ((number == 2) || (number == 3)) return PRIME;
    if ((!(number % 2)) || (!(number % 3))) return COMPOSITE;
    for (size_t div = 5; div * div <= number; div += 6) {
        if (!(number % div) || (!(number % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

template <typename T>
void list_terms(T ceiling) {
    T i = 3;
    for (T number = 5; number <= ceiling; number += 2) {
        if (primality_test(number)) {
            cout << "Prime #" << i << " = " << number << endl;
            i++;
        }
    }
}

template <typename T>
void test_candidate(T candidate) {
    if (primality_test(candidate) == PRIME) {
        cout << candidate << " is prime" << endl;
    } else {
        cout << candidate << " is composite" << endl;
    }
    exit(EXIT_SUCCESS);
}

template <typename T>
void find_nth_term(T index) {
    T i = 3;
    for (T number = 5; number <= UINT64_MAX; number += 2) {
        if (primality_test(number) == COMPOSITE) continue;
        else {
            if (i == index) {
                cout << "Prime #" << i << " = " << number << endl;
                exit(EXIT_SUCCESS);
            }
            i++;
        }
    }
}

void interactive_session() {
    cout << ASCII_ART << endl;
    cout << "[1] Compute every prime below a given ceiling value" << endl;
    cout << "[2] Compute the prime at a given index in the series" << endl;
    cout << "[3] Perform a primality test on a given candidate integer" << endl
         << endl;
    switch (prompt()) {
        case NONE:
            error_exit("Error: Invalid mode");
            break;
        case LIST_TERMS:
            list_terms(prompt("Ceiling: "));
            break;
        case FIND_NTH_TERM:
            find_nth_term(prompt("Index: "));
            break;
        case TEST_CANDIDATE:
            test_candidate(prompt("Candidate: "));
            break;
    }
}

void non_interactive_session(Options* options) {
    switch (options->mode) {
        case NONE:
            error_exit("Error: Invalid mode");
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

int main(int argc, char** argv) {
    Options options;
    parse(&options, argc, argv);
    if (options.mode == NONE)
        interactive_session();
    else
        non_interactive_session(&options);
    return 0;
}
