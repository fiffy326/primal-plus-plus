#ifndef COMMAND_FIND_NTH_PRIME_H
#define COMMAND_FIND_NTH_PRIME_H

#include <cmath>
#include <iostream>
#include <type_traits>
#include <vector>

#include "../sieve_of_eratosthenes.h"

/**
 * Prints the Nth prime number.
 * @tparam T Unsigned integer type
 * @param n Prime index
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
find_nth_prime(T n) {
    // Prime number theorem approximation for the Nth prime.
    T ceiling_estimate = n * std::log(n) + n * std::log(std::log(n));

    // Minimum sieve ceiling value (in case approximation fails for small n).
    T ceiling_min = 15;

    // Sieve ceiling used for computations.
    T ceiling;

    std::vector<T> primes;
    while (true) {
        // (Re)calculate the sieve ceiling.
        ceiling = std::max(ceiling_estimate, ceiling_min);

        sieve_of_eratosthenes<T>(ceiling, primes);
        if (n <= primes.size()) {
            std::cout << "Prime #" << n << " = " << primes[n - 1] << '\n';
            return;
        } else {
            // Increase the ceiling if the sieve didn't find the desired prime.
            std::cout << "Increasing sieve ceiling...\n";
            ceiling_min = static_cast<T>(ceiling * 1.25);
            primes.clear();
        }
    }
}

#endif // COMMAND_FIND_NTH_PRIME_H
