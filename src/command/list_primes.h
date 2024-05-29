#ifndef COMMAND_LIST_PRIMES_H
#define COMMAND_LIST_PRIMES_H

#include <cinttypes>
#include <cstdio>
#include <iostream>
#include <type_traits>
#include <vector>

#include "../sieve_of_eratosthenes.h"

/**
 * Prints the primes up to a ceiling.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
list_primes(T ceiling) {
    std::vector<T> primes;
    sieve_of_eratosthenes<T>(ceiling, primes);

    for (T i = 0; i < primes.size(); i++) {
        // Use printf in loop to increase performance.
        printf("Prime #%" PRIu64 " = %" PRIu64 "\n",
               static_cast<uint64_t>((i + 1)),
               static_cast<uint64_t>(primes[i]));
    }
}

#endif // COMMAND_LIST_PRIMES_H
