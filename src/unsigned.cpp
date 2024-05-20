#include "unsigned.h"

#include <iostream>
#include <string>

#include "error_exit.h"

using std::cin;
using std::cout;
using std::string;
using std::to_string;

/**
 * Parses a string to an unsigned 64-bit integer
 * @param arg_input Input string to be parsed
 * @param arg_name Name of the value being parsed
 * @return Unsigned 64-bit integer parsed from the input string
 */
U64 parse_unsigned(const string& arg_input, const string& arg_name) {
    string too_large = "The " + arg_name + " provided was greater than the "
            + "maximum allowed value (max: " + to_string(U64_MAX) + ")";
    string too_small = "The " + arg_name + " provided was invalid or less than "
            + "the minimum allowed value (min: " + to_string(U64_MIN) + ")";

    U64 arg_value;
    if ((arg_value = strtoull(arg_input.c_str(), nullptr, 10)) > U64_MAX) {
        error_exit(too_large);
    }
    if (!arg_value) {
        error_exit(too_small);
    }
    return arg_value;
}

/**
 * Prompts and parses user input to an unsigned 64-bit integer
 * @param arg_name Name of the value being parsed
 * @param prompt Prompt to show the user
 * @return Unsigned 64-bit integer parsed from the input string
 */
U64 prompt_unsigned(const string& arg_name, const string& prompt) {
    cout << prompt;
    string input;
    cin >> input;
    return parse_unsigned(input, arg_name);
}