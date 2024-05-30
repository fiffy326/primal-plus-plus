#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "enum/command.h"
#include "parse/cli.h"
#include "session.h"

/**
 * Program entry point.
 * @param argc Number of command line arguments
 * @param argv Command line arguments
 * @return EXIT_SUCCESS if successful, EXIT_FAILURE on error
 */
int main(int argc, char** argv) {
    try {
        // Parse the command line arguments.
        Cli cli = parse<Cli>(argc, argv);

        // Start the appropriate session type.
        switch (cli.getCommand()) {
            case Command::INTERACTIVE:
                session();
                break;
            default:
                session(cli);
                break;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
