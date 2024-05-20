#include "mode.h"

#include <iostream>
#include <string>

#include "error_exit.h"

using std::cin;
using std::cout;
using std::string;

/**
 * Parses a string to a Mode enum
 * @param arg_input Input string to be parsed
 * @return Mode enum parsed from the input string
 */
Mode parse_mode(const string& arg_input) {
    Mode mode = (Mode)strtol(arg_input.c_str(), nullptr, 10);
    if ((mode == NONE) || (mode > sizeof(Mode) - 1)) {
        error_exit("Invalid mode");
    }
    return mode;
}

/**
 * Prompts and parses user input to a Mode enum
 * @return Mode enum parsed from the input string
 */
Mode prompt_mode() {
    cout << "Mode: ";
    string input;
    cin >> input;
    return parse_mode(input);
}