#ifndef PRIMALITY_H
#define PRIMALITY_H

#include <iostream>

#include <cstddef>
#include <cstdlib>

#include "unsigned.h"

using std::cout;
using std::endl;
using std::exit;

/* Enums */
typedef enum { NEITHER, COMPOSITE, PRIME } Primality;

/* Functions */
/**
 * Performs a primality test on a number
 * @tparam T Unsigned integer
 * @param number Number to test
 * @return Primality enum of the test outcome
 */
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
    for (size_t divisor = 5; divisor * divisor <= number; divisor += 6) {
        if (!(number % divisor) || (!(number % (divisor + 2)))) {
            return COMPOSITE;
        }
    }
    return PRIME;
}

/**
 * Prints the prime at the given index in the series
 * @tparam T Unsigned integer
 * @param index Index of the prime to print
 */
template <typename T>
void find_nth_term(T index) {
    T i = 3;
    for (T number = 5; number <= U64_MAX; number += 2) {
        if (primality_test(number) != PRIME) {
            continue;
        } else {
            if (i == index) {
                cout << "Prime #" << i << " = " << number << endl;
                exit(EXIT_SUCCESS);
            }
            i++;
        }
    }
}

/**
 * Prints every prime below a given ceiling value
 * @tparam T Unsigned integer
 * @param ceiling Ceiling value
 */
template <typename T>
void list_terms(T ceiling) {
    T i = 3;
    for (T number = 5; number <= ceiling; number += 2) {
        if (primality_test(number) == PRIME) {
            cout << "Prime #" << i << " = " << number << endl;
            i++;
        }
    }
}

/**
 * Prints the result of a primality test for given candidate number
 * @tparam T Unsigned integer
 * @param candidate Number to test
 */
template <typename T>
void test_candidate(T candidate) {
    if (primality_test(candidate) == PRIME) {
        cout << candidate << " is prime" << endl;
    }
    else if (primality_test(candidate) == COMPOSITE) {
        cout << candidate << " is composite" << endl;
    }
    else {
        cout << candidate << " is neither prime nor composite" << endl;
    }
    exit(EXIT_SUCCESS);
}

#endif // PRIMALITY_H