#ifndef PRIMAL_TEST_NUMBER_H
#define PRIMAL_TEST_NUMBER_H

#include <iostream>

#include "natural_number.h"
#include "primality.h"
#include "primality_test.h"

/**
 * Prints the result of a primality test on a number.
 * @tparam T Natural number type
 * @param number Number to test
 */
template <typename T = NN64>
void test_number(T number) {
    switch (primality_test<T>(number)) {
        case Primality::PRIME:
            std::cout << number << " is prime.";
            break;
        case Primality::COMPOSITE:
            std::cout << number <<" is composite.";
            break;
        case Primality::NEITHER:
            std::cout << number << " is neither prime nor composite.";
            break;
    }
    std::cout << std::endl;
}

#endif // PRIMAL_TEST_NUMBER_H
