#ifndef PRIMALITY_H
#define PRIMALITY_H

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "natural_number.h"

/* Enums */
typedef enum { NEITHER, COMPOSITE, PRIME } Primality;

/* Function templates */
template <typename T>
Primality primality_test(T number) {
    if (number == 1) {
        return NEITHER;
    }
    if ((number == 2) || (number == 3)) {
        return PRIME;
    }
    if ((!(number % 2)) || (!(number % 3))) {
        return COMPOSITE;
    }
    for (T divisor = 5; divisor * divisor <= number; divisor += 6) {
        if (!(number % divisor) || (!(number % (divisor + 2)))) {
            return COMPOSITE;
        }
    }
    return PRIME;
}

template <typename T>
void sieve_of_eratosthenes(T ceiling, std::vector<T>& primes) {
    std::cout << "Sieving primes..." << std::endl;

    std::vector<Primality> primality(ceiling + 1, PRIME);
    primality[0] = primality[1] = NEITHER;

    for (T number = 2; number * number <= ceiling; number++) {
        if (primality[number] == PRIME) {
            for (T i = number * number; i <= ceiling; i += number) {
                primality[i] = COMPOSITE;
            }
        }
    }

    for (T number = 2; number <= ceiling; number++) {
        if (primality[number] == PRIME) {
            primes.push_back(number);
        }
    }
}

template <typename T>
void find_nth_prime(T n) {
    // Prime number theorem approximation of the Nth prime.
    T ceiling_estimate = n * std::log(n) + n * std::log(std::log(n));

    // Minimum sieve ceiling value (in case the approximation fails)
    T ceiling_min = 15;

    // Sieve ceiling
    T ceiling;

    std::vector<T> primes;
    while (true) {
        // (Re)calculate the sieve ceiling
        ceiling = std::max(ceiling_estimate, ceiling_min);

        sieve_of_eratosthenes(ceiling, primes);

        if (n <= primes.size()) {
            std::cout << "Prime #" << n << " = " << primes[n - 1] << std::endl;
            return;
        } else {
            // Increase ceiling if the sieve didn't find the desired prime
            std::cout << "Increasing sieve ceiling..." << std::endl;
            ceiling_min = ceiling * 1.25;
            primes.clear();
        }
    }
}

template <typename T>
void list_primes(T ceiling) {
    std::vector<T> primes;
    sieve_of_eratosthenes(ceiling, primes);
    
    for (T i = 0; i < primes.size(); i++) {
        std::cout << "Prime #" << (i + 1) << " = " << primes[i] << "\n";
    }
}

template <typename T>
void test_number(T number) {
    switch (primality_test(number)) {
        case PRIME:
            std::cout << number << " is prime." << std::endl;
            break;
        case COMPOSITE:
            std::cout << number << " is composite." << std::endl;
            break;
        case NEITHER:
            std::cout << number << " is neither prime nor composite." << std::endl;
            break;
    }
}

#endif // PRIMALITY_H
