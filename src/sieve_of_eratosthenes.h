#ifndef PRIMAL_SIEVE_OF_ERATOSTHENES_H
#define PRIMAL_SIEVE_OF_ERATOSTHENES_H

#include <iostream>
#include <vector>

#include "natural_number.h"
#include "primality.h"

/**
 * Computes the prime numbers up to a ceiling using a Sieve of Eratosthenes.
 * @tparam T Natural number type
 * @param ceiling Ceiling to sieve up to
 * @param primes Primes found
 */
template <typename T = NN64>
void sieve_of_eratosthenes(T ceiling, std::vector<T> &primes) {
    std::cout << "Sieving primes..." << std::endl;

    std::vector<Primality> primality(ceiling + 1, Primality::PRIME);
    primality[0] = primality[1] = Primality::NEITHER;

    for (T number = 2; number * number <= ceiling; number++) {
        if (primality[number] == Primality::PRIME) {
            for (T i = number * number; i <= ceiling; i += number) {
                primality[i] = Primality::COMPOSITE;
            }
        }
    }
    for (T number = 2; number <= ceiling; number++) {
        if (primality[number] == Primality::PRIME) {
            primes.push_back(number);
        }
    }
}

#endif // PRIMAL_SIEVE_OF_ERATOSTHENES_H
