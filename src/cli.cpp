#include "cli.h"

#include <stdexcept>
#include <string>
#include <unistd.h>

#include "command.h"
#include "natural_number.h"

/**
 * Parses the command line options passed to the program.
 * @param argc Number of command line arguments
 * @param argv Command line arguments
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

/**
 * Gets the program name command line argument (argv[0]).
 * @return Program name
 */
std::string Cli::getProgramName() {
    return program_name;
}

/**
 * Gets the Command enum appropriate for the provided command line options.
 * @return
 */
Command Cli::getCommand() {
    return command;
}

/**
 * Gets the 'ceiling' command line argument for the LIST_PRIMES command.
 * @return Ceiling
 */
NN64 Cli::getCeiling() {
    return ceiling;
}

/**
 * Gets the 'index' command line argument for the FIND_NTH_PRIME command.
 * @return
 */
NN64 Cli::getIndex() {
    return index;
}

/**
 * Gets the 'number' command line argument for the TEST_NUMBER command.
 * @return
 */
NN64 Cli::getNumber() {
    return number;
}
