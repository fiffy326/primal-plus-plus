#ifndef PRIMALITY_TEST_H
#define PRIMALITY_TEST_H

#include <type_traits>

#include "enum/primality.h"

/**
 * Performs a primality test on a number using trial division.
 * @tparam T Unsigned integer type
 * @param number Number to test for primality
 * @return Primality enum of test outcome
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, Primality>::type
primality_test(T number) {
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

#endif // PRIMALITY_TEST_H
