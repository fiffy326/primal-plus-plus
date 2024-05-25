#include "options.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>

#include "error_exit.h"
#include "mode.h"
#include "natural_number.h"

std::string get_usage_message(const std::string &program_name) {
    return "Usage: " + program_name + " [-?] [-c CEILING] [-i INDEX] "
        + "[-t NUMBER]";
}

void parse_options(Options *options, int argc, char **argv) {
    options->mode = NONE;
    options->ceiling = options->index = options->number = 0;
    int opt;
    while ((opt = getopt(argc, argv, "c:i:t:")) != -1) {
        switch (opt) {
            case 'c':
                options->mode = LIST_PRIMES;
                options->ceiling = parse("ceiling", optarg);
                break;
            case 'i':
                options->mode = FIND_NTH_PRIME;
                options->index = parse("index", optarg);
                break;
            case 't':
                options->mode = TEST_NUMBER;
                options->number = parse("number", optarg);
                break;
            case '?':
                std::cout << get_usage_message(argv[0]) << std::endl;
                std::exit(EXIT_SUCCESS);
            default:
                error_exit("Invalid options.");
        }
    }
    int extra_args = argc - optind;
    if (extra_args) {
        error_exit("Invalid arguments.");
    }
}
