#ifndef PRIMAL_LIST_PRIMES_H
#define PRIMAL_LIST_PRIMES_H

#include <iostream>
#include <vector>

#include "natural_number.h"
#include "sieve_of_eratosthenes.h"

/**
 * Prints the prime numbers up to a ceiling.
 * @tparam T Natural number type
 * @param ceiling Ceiling value
 */
template <typename T = NN64>
void list_primes(T ceiling) {
    std::vector<T> primes;
    sieve_of_eratosthenes(ceiling, primes);

    for (T i = 0; i < primes.size(); i++) {
        // Use \n instead of std::endl to avoid flushing buffer to loop faster.
        std::cout << "Prime #" << (i + 1) << " = " << primes[i] << "\n";
    }
}

#endif // PRIMAL_LIST_PRIMES_H
