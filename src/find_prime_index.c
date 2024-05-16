#include <stdio.h>
#include <stdlib.h>
#include "find_prime_index.h"
#include "is_prime.h"

void find_prime_index(U64 prime_index) {
    U64 index = 3;
    for (U64 number = 5; number <= U64_MAX; number += 2) {
        if (!is_prime(number)) continue;
        else {
            if (index == prime_index) {
                printf("Prime #%lu = %lu\n", index, number);
                exit(EXIT_SUCCESS);
            }
            index++;
        }
    }
}
