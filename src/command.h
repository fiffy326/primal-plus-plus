#ifndef PRIMAL_COMMAND_H
#define PRIMAL_COMMAND_H

#include <cstdlib>
#include <string>

#include "parser.h"

/**
 * Represents the functions that the program may perform.
 */
enum class Command {
    LIST_PRIMES = 1,
    FIND_NTH_PRIME = 2,
    TEST_NUMBER = 3,
    SHOW_HELP = 4,
    INTERACTIVE = 5
};

template <> Command parse(const std::string &input);

#endif // PRIMAL_COMMAND_H
