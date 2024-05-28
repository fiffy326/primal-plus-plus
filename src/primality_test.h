#ifndef PRIMAL_PRIMALITY_TEST_H
#define PRIMAL_PRIMALITY_TEST_H

#include "natural_number.h"
#include "primality.h"

/**
 * Performs a primality test on a number.
 * @tparam T Natural number type
 * @param number Number to test
 * @return Result of primality test
 */
template <typename T = NN64>
Primality primality_test(T number) {
    if (number == 1) {
        return Primality::NEITHER;
    }
    if ((number == 2) || (number == 3)) {
        return Primality::PRIME;
    }
    if (!(number % 2) || !(number % 3)) {
        return Primality::COMPOSITE;
    }
    for (T divisor = 5; divisor * divisor <= number; divisor += 6) {
        if (!(number % divisor) || !(number % (divisor + 2))) {
            return Primality::COMPOSITE;
        }
    }
    return Primality::PRIME;
}

#endif // PRIMAL_PRIMALITY_TEST_H
