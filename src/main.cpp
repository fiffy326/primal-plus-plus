#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <getopt.h>
#include "ascii_art.h"

using std::cerr, std::cin, std::cout, std::endl, std::string, std::to_string;

/* Typedefs */
typedef uint_fast8_t U8;
typedef uint_fast16_t U16;
typedef uint_fast32_t U32;
typedef uint_fast64_t U64;

/* Enums */
typedef enum { NEITHER, COMPOSITE, PRIME } Primality;
typedef enum { NONE, LIST_TERMS, FIND_NTH_TERM, TEST_CANDIDATE } Mode;

/* Structs */
typedef struct {
    Mode mode;
    U64 ceiling;
    U64 index;
    U64 candidate;
} Options;

/* Constants */
static const U64 U64_MIN = 1;
static const U64 U64_MAX = UINT_FAST64_MAX - 1;

string usage_message(const string& program_name) {
    return "Usage: " + program_name + " [-?] [-c ceiling] [-i index] "
        + "[-t candidate]";
}

void error_exit(const string& message) {
    cerr << "Error: " << message << endl;
    exit(EXIT_FAILURE);
}

Mode parse(const string& arg_input) {
    Mode mode = (Mode)strtol(arg_input.c_str(), nullptr, 10);
    if ((mode == NONE) || (mode > sizeof(Mode) - 1))
        error_exit("Invalid mode");
    return mode;
}

U64 parse(const string& arg_input, const string& arg_name) {
    string too_large = "The " + arg_name + " provided was greater than the "
        + "maximum allowed value (max: " + to_string(U64_MAX) + ")";

    string too_small = "The " + arg_name + " provided was invalid or less than "
        + "the minimum allowed value (min: " + to_string(U64_MIN) + ")";

    U64 arg_value;
    if ((arg_value = strtoull(arg_input.c_str(), nullptr, 10)) > U64_MAX)
        error_exit(too_large);
    if (!arg_value)
        error_exit(too_small);
    return arg_value;
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
                error_exit("Invalid options");
        }
    }
    int extra_args = argc - optind;
    if (extra_args)
        error_exit("Invalid arguments");
}

U64 prompt(const string& arg_name, const string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    return parse(input, arg_name);
}

Mode prompt() {
    cout << "Mode: ";
    string input;
    cin >> input;
    return parse(input);
}

template <typename T>
Primality primality_test(T number) {
    if (number == 1) return NEITHER;
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
        if (primality_test(number) == PRIME) {
            cout << "Prime #" << i << " = " << number << endl;
            i++;
        }
    }
}

template <typename T>
void test_candidate(T candidate) {
    if (primality_test(candidate) == PRIME) {
        cout << candidate << " is prime" << endl;
    }
    else if (primality_test(candidate) == COMPOSITE) {
        cout << candidate << " is composite" << endl;
    }
    else {
        cout << candidate << " is neither prime nor composite" << endl;
    }
    exit(EXIT_SUCCESS);
}

template <typename T>
void find_nth_term(T index) {
    T i = 3;
    for (T number = 5; number <= U64_MAX; number += 2) {
        if (primality_test(number) != PRIME) continue;
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
            error_exit("Invalid mode");
            break;
        case LIST_TERMS:
            list_terms(prompt("ceiling", "Ceiling: "));
            break;
        case FIND_NTH_TERM:
            find_nth_term(prompt("index", "Index: "));
            break;
        case TEST_CANDIDATE:
            test_candidate(prompt("candidate", "Candidate: "));
            break;
    }
}

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

int main(int argc, char** argv) {
    Options options;
    parse(&options, argc, argv);
    if (options.mode == NONE)
        interactive_session();
    else
        non_interactive_session(&options);
    return 0;
}
