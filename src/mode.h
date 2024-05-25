#ifndef MODE_H
#define MODE_H

#include <string>

/* Enums */
typedef enum { NONE, LIST_PRIMES, FIND_NTH_PRIME, TEST_NUMBER } Mode;

/* Functions */
Mode parse(const std::string &input);
Mode input(const std::string &prompt);

#endif // MODE_H
