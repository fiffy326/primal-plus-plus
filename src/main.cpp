#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

#include "ascii_art.h"
#include "cli.h"
#include "find_nth_prime.h"
#include "list_primes.h"
#include "parser.h"
#include "test_number.h"

/**
 * Program help message builder.
 * @param program_name Name of the program
 * @return Program help message
 */
std::string get_help_message(const std::string &program_name) {
    return "Usage: " + program_name + " [-?] [-l CEILING] [-n INDEX] "
    + "[-t NUMBER]";
}

/**
 * Starts a session using the command line options.
 * @param cli Command line options
 * @return EXIT_SUCCESS if successful
 */
int cli_session(Cli &cli) {
    switch (cli.getCommand()) {
        case Command::LIST_PRIMES:
            list_primes(cli.getCeiling());
            break;
        case Command::FIND_NTH_PRIME:
            find_nth_prime(cli.getIndex());
            break;
        case Command::TEST_NUMBER:
            test_number(cli.getNumber());
            break;
        case Command::SHOW_HELP:
            std::cout << get_help_message(cli.getProgramName()) << std::endl;
            break;
        default:
            throw std::runtime_error("Invalid command.");
    }
    return EXIT_SUCCESS;
}

/**
 * Starts a session using interactive user input.
 * @return EXIT_SUCCESS if successful
 */
int interactive_session() {
    std::cout << ASCII_ART
    << "[1] List primes up to a value.\n"
    << "[2] Find the Nth prime number.\n"
    << "[3] Test if a number is prime.\n" << std::endl;

    switch (input<Command>("Command: ")) {
        case Command::LIST_PRIMES:
            list_primes(input("Ceiling: "));
            break;
        case Command::FIND_NTH_PRIME:
            find_nth_prime(input("Index: "));
            break;
        case Command::TEST_NUMBER:
            test_number(input("Number: "));
            break;
        default:
            throw std::runtime_error("Invalid command.");
    }
    return EXIT_SUCCESS;
}

/**
 * Program entry point.
 * @param argc Number of program arguments
 * @param argv Program arguments
 * @return EXIT_SUCCESS if successful
 */
int main(int argc, char **argv) {
    try {
        // Parse command line arguments.
        Cli cli = Cli(argc, argv);

        // Start the appropriate session type.
        switch (cli.getCommand()) {
            case Command::INTERACTIVE:
                return interactive_session();
            default:
                return cli_session(cli);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
