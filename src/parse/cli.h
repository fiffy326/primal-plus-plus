#ifndef PARSE_CLI_H
#define PARSE_CLI_H

#include <cstdint>
#include <string>

#include "../enum/command.h"

/**
 * Represents the command line options passed to the program.
 */
class Cli {
public:
    Cli(int argc, char** argv);
    std::string getUsageMessage();
    Command getCommand();
    uint64_t getCeiling();
    uint64_t getIndex();
    uint64_t getNumber();
private:
    std::string program_name;
    Command command;
    uint64_t ceiling;
    uint64_t index;
    uint64_t number;
};

/**
 * Parses the command line options passed to the program.
 * @tparam T Cli object type
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Cli object of parsed command line options
 */
template <typename T>
T parse(int argc, char** argv) {
    return Cli(argc, argv);
}

#endif // PARSE_CLI_H
