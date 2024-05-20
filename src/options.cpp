#include "options.h"

#include <iostream>
#include <string>

#include <cstdlib>
#include "getopt.h"

#include "error_exit.h"
#include "mode.h"
#include "unsigned.h"

using std::cout;
using std::endl;
using std::exit;
using std::string;

/**
 * Builds a program usage message string
 * @param program_name Name of the program
 * @return Usage message string for the program
 */
string usage_message(const string& program_name) {
    return "Usage: " + program_name + " [-?] [-c CEILING] [-i INDEX] "
        + "[-t CANDIDATE]";
}

/**
 * Parses command line options to an Options struct
 * @param options Options struct to parse values into
 * @param argc Number of arguments passed to the program
 * @param argv Arguments passed to the program
 */
void parse_options(Options* options, int argc, char** argv) {
    options->mode = NONE;
    options->ceiling = options->index = options->candidate = 0;
    int opt;
    while ((opt = getopt(argc, argv, ":c:i:t:")) != -1) {
        switch (opt) {
            case ':':
            case 'c':
                options->mode = LIST_TERMS;
                options->ceiling = parse_unsigned(optarg, "ceiling");
                break;
            case 'i':
                options->mode = FIND_NTH_TERM;
                options->index = parse_unsigned(optarg, "index");
                break;
            case 't':
                options->mode = TEST_CANDIDATE;
                options->candidate = parse_unsigned(optarg, "candidate");
                break;
            case '?':
                cout << usage_message(argv[0]) << endl;
                exit(EXIT_SUCCESS);
            default:
                error_exit("Invalid options");
        }
    }
    int extra_args = argc - optind;
    if (extra_args) {
        error_exit("Invalid arguments");
    }
}