#ifndef SIEVE_OF_ERATOSTHENES_H
#define SIEVE_OF_ERATOSTHENES_H

#include <stdexcept>
#include <type_traits>
#include <vector>

#include "enum/primality.h"

/**
 * Computes the primes up to a given ceiling using a Sieve of Eratosthenes.
 * @tparam T Unsigned integer type
 * @param ceiling Largest number to check
 * @param primes Vector of the primes found
 */
template <typename T>
typename std::enable_if_t<std::is_unsigned_v<T>, void>
sieve_of_eratosthenes(T ceiling, std::vector<T>& primes) {
    if (ceiling == 0) {
        throw std::runtime_error("Ceiling passed to sieve_of_eratosthenes must"
                                 " be a positive integer.");
    }

    // Prepare a primality vector to rule out multiples.
    std::vector<Primality> primality(ceiling + 1, Primality::PRIME);

    // Mark 0 and 1 as neither prime nor composite.
    primality[0] = primality[1] = Primality::NEITHER;

    // Mark multiples of numbers as composite.
    for (T number = 2; number * number <= ceiling; number++) {
        if (primality[number] == Primality::PRIME) {
            for (T i = number * number; i <= ceiling; i += number) {
                primality[i] = Primality::COMPOSITE;
            }
        }
    }

    // Fill the primes vector with the remaining numbers.
    for (T number = 2; number <= ceiling; number++) {
        if (primality[number] == Primality::PRIME) {
            primes.push_back(number);
        }
    }
}

#endif // SIEVE_OF_ERATOSTHENES_H
