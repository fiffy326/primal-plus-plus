#ifndef COMMAND_LIST_PRIMES_H
#define COMMAND_LIST_PRIMES_H

#include <cinttypes>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

#include "../sieve_of_eratosthenes.h"
#include "../utils/get_format_specifier.h"

/**
 * Prints the primes up to a ceiling.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 */
template <typename T>
typename std::enable_if_t<std::is_unsigned_v<T>, void>
list_primes(T ceiling) {
    std::vector<T> primes;
    sieve_of_eratosthenes<T>(ceiling, primes);

    // Get the printf format specifier for the type.
    std::string format = get_format_specifier<T>();

    // Build the printf format string for the output.
    std::stringstream output_format_stream;
    output_format_stream << "Prime #%" << format << " = %" << format << '\n';

    // Convert the string stream to a C string.
    std::string output_format = output_format_stream.str();
    const char* output = output_format.c_str();

    for (T i = 0; i < primes.size(); i++) {
        // Use printf in loop to increase performance.
        printf(output, (i + 1), primes[i]);
    }
}

#endif // COMMAND_LIST_PRIMES_H
