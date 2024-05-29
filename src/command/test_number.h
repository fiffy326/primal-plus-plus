#ifndef COMMAND_TEST_NUMBER_H
#define COMMAND_TEST_NUMBER_H

#include <iostream>
#include <type_traits>

#include "../primality_test.h"
#include "../enum/primality.h"

/**
 * Prints the outcome of a primality test on a number.
 * @tparam T Unsigned integer type
 * @param number Number to test for primality
 */
template <typename T>
typename std::enable_if<std::is_unsigned<T>::value, void>::type
test_number(T number) {
    switch (primality_test<T>(number)) {
        case Primality::PRIME:
            std::cout << number << " is prime.\n";
            break;
        case Primality::COMPOSITE:
            std::cout << number << " is composite.\n";
            break;
        case Primality::NEITHER:
            std::cout << number << " is neither prime nor composite.\n";
            break;
    }
}

#endif // COMMAND_TEST_NUMBER_H
