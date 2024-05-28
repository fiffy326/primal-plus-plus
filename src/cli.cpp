#include "cli.h"

#include <stdexcept>
#include <string>
#include <unistd.h>

#include "command.h"
#include "natural_number.h"
#include "parser.h"

/**
 * Parses the command line options.
 * @param argc Number of program arguments
 * @param argv Program arguments
 */
Cli::Cli(int argc, char **argv) {
    program_name = argv[0];
    int opt;
    while ((opt = getopt(argc, argv, "l:n:t:?")) != -1) {
        switch (opt) {
            case 'l':
                command = Command::LIST_PRIMES;
                ceiling = parse(optarg);
                break;
            case 'n':
                command = Command::FIND_NTH_PRIME;
                index = parse(optarg);
                break;
            case 't':
                command = Command::TEST_NUMBER;
                number = parse(optarg);
                break;
            case '?':
                command = Command::SHOW_HELP;
                break;
            default:
                throw std::runtime_error("Invalid options.");
        }
    }
    int extra_args = argc - optind;
    if (extra_args) {
        throw std::runtime_error("Invalid arguments.");
    }
}

std::string Cli::getProgramName() {
    return program_name;
}

Command Cli::getCommand() {
    return command;
}

NN64 Cli::getCeiling() {
    return ceiling;
}

NN64 Cli::getIndex() {
    return index;
}

NN64 Cli::getNumber() {
    return number;
}
