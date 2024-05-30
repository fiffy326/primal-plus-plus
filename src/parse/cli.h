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
    Command command = Command::INTERACTIVE;
    uint64_t ceiling = 0;
    uint64_t index = 0;
    uint64_t number = 0;
};

/**
 * Parses the command line options passed to the program.
 * @tparam T Cli object return type
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return Cli object of parsed command line options
 */
template <typename T>
typename std::enable_if_t<std::is_class_v<T>, T>
parse(int argc, char** argv) {
    return Cli(argc, argv);
}

#endif // PARSE_CLI_H
