#include "cli.h"

#include <cstdint>
#include <stdexcept>
#include <string>
#include <unistd.h>

#include "../enum/command.h"
#include "unsigned.h"

/**
 * Parses the command line options passed to the program.
 * @param argc Number of command line arguments
 * @param argv Command line options
 */
Cli::Cli(int argc, char** argv) {
    command = Command::INTERACTIVE;
    ceiling = index = number = 0;
    program_name = argv[0];
    int opt;
    while ((opt = getopt(argc, argv, "l:n:t:?")) != -1) {
        switch (opt) {
            case 'l':
                command = Command::LIST_PRIMES;
                ceiling = parse<uint64_t>(optarg);
                break;
            case 'n':
                command = Command::FIND_NTH_PRIME;
                index = parse<uint64_t>(optarg);
                break;
            case 't':
                command = Command::TEST_NUMBER;
                number = parse<uint64_t>(optarg);
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
 * Gets the usage message for the program.
 * @return Program usage message
 */
std::string Cli::getUsageMessage() {
    return "Usage: " + program_name + " [-?] [-l CEILING] [-n INDEX] "
    + "[-t NUMBER]";
}

/**
 * Gets the Command enum value associated with the parsed command line options.
 * @return Command enum value
 */
Command Cli::getCommand() {
    return command;
}

/**
 * Gets the 'ceiling' command line argument value.
 * @return Ceiling argument value
 */
uint64_t Cli::getCeiling() {
    return ceiling;
}

/**
 * Gets the 'index' command line argument value.
 * @return Index argument value
 */
uint64_t Cli::getIndex() {
    return index;
}

/**
 * Gets the 'number' command line argument value.
 * @return Number argument value
 */
uint64_t Cli::getNumber() {
    return number;
}
