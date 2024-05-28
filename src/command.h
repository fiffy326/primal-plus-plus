#ifndef PRIMAL_COMMAND_H
#define PRIMAL_COMMAND_H

/**
 * Represents functions the program may perform.
 */
enum class Command {
    LIST_PRIMES = 1,
    FIND_NTH_PRIME = 2,
    TEST_NUMBER = 3,
    SHOW_HELP = 4,
    INTERACTIVE = 5
};

#endif // PRIMAL_COMMAND_H
