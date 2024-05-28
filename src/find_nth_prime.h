#ifndef PRIMAL_FIND_NTH_PRIME_H
#define PRIMAL_FIND_NTH_PRIME_H

#include <cmath>
#include <iostream>
#include <vector>

#include "natural_number.h"
#include "sieve_of_eratosthenes.h"

/**
 * Prints the Nth prime number.
 * @tparam T Natural number type
 * @param n Prime index
 */
template <typename T = NN64>
void find_nth_prime(T n) {
    // Prime number theorem approximation of the Nth prime.
    T ceiling_estimate = n * std::log(n) + n * std::log(std::log(n));

    // Minimum sieve ceiling value (in case approximation fails for small n).
    T ceiling_min = 15;

    // Sieve ceiling used for computations.
    T ceiling;

    std::vector<T> primes;
    while (true) {
        // (Re)calculate the sieve ceiling.
        ceiling = std::max(ceiling_estimate, ceiling_min);

        sieve_of_eratosthenes(ceiling, primes);

        if (n <= primes.size()) {
            std::cout << "Prime #" << n << " = " << primes[n - 1] << std::endl;
            break;
        } else {
            // Increase the ceiling if the sieve didn't find the desired prime.
            std::cout << "Increasing sieve ceiling..." << std::endl;
            ceiling_min = static_cast<T>(ceiling * 1.25);
            primes.clear();
        }
    }
}

#endif // PRIMAL_FIND_NTH_PRIME_H
