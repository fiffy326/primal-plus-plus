#include "session.h"

#include <cstdint>
#include <iostream>
#include <stdexcept>

#include "ascii_art.h"
#include "command/find_nth_prime.h"
#include "command/list_primes.h"
#include "command/test_number.h"
#include "enum/command.h"
#include "parse/cli.h"
#include "parse/input.h"

/**
 * Starts a session using interactive user input.
 */
void session() {
    std::cout << ASCII_ART
              << "[1] List primes up to a value.\n"
              << "[2] Find the Nth prime number.\n"
              << "[3] Test if a number is prime.\n\n";

    switch (input<Command>("Command: ")) {
        case Command::LIST_PRIMES:
            list_primes(input<uint64_t>("Ceiling: "));
            break;
        case Command::FIND_NTH_PRIME:
            find_nth_prime(input<uint64_t>("Index: "));
            break;
        case Command::TEST_NUMBER:
            test_number(input<uint64_t>("Number: "));
            break;
        default:
            throw std::runtime_error("Invalid command.");
    }
}

/**
 * Starts a session using the command line options.
 * @param cli Parsed command line options
 */
void session(Cli& cli) {
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
            std::cout << cli.getUsageMessage() << '\n';
            break;
        default:
            throw std::runtime_error("Invalid command.");
    }
}
