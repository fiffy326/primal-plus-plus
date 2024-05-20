#include "error_exit.h"

#include <iostream>
#include <string>

#include <cstdlib>

using std::cerr;
using std::endl;
using std::exit;
using std::string;

/**
 * Displays an error message and exits the program
 * @param message Error message to display
 */
void error_exit(const std::string& message) {
    cerr << "Error: " << message << endl;
    exit(EXIT_FAILURE);
}