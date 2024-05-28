#ifndef PRIMAL_CLI_H
#define PRIMAL_CLI_H

#include <string>

#include "command.h"
#include "natural_number.h"

/**
 * Represents the command line options.
 */
class Cli {
public:
    Cli(int argc, char **argv);
    std::string getProgramName();
    Command getCommand();
    NN64 getCeiling();
    NN64 getIndex();
    NN64 getNumber();
private:
    std::string program_name;
    Command command = Command::INTERACTIVE;
    NN64 ceiling = NN64_MIN;
    NN64 index = NN64_MIN;
    NN64 number = NN64_MIN;
};

#endif // PRIMAL_CLI_H
