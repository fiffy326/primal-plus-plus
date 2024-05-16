#include <stdio.h>
#include <stdlib.h>
#include "list_primes.h"
#include "is_prime.h"
#include "unsigned.h"

void list_primes_u8(U8 ceiling) {
    U8 index = 3;
    for (U8 number = 5; number <= ceiling; number += 2) {
        if (is_prime_u8(number)) {
            printf("Prime #%u = %u\n", index, number);
            index++;
        }
    }
}

void list_primes_u16(U16 ceiling) {
    U16 index = 3;
    for (U16 number = 5; number <= ceiling; number += 2) {
        if (is_prime_u16(number)) {
            printf("Prime #%u = %u\n", index, number);
            index++;
        }
    }
}

void list_primes_u32(U32 ceiling) {
    U32 index = 3;
    for (U32 number = 5; number <= ceiling; number += 2) {
        if (is_prime_u32(number)) {
            printf("Prime #%u = %u\n", index, number);
            index++;
        }
    }
}

void list_primes_u64(U64 ceiling) {
    U64 index = 3;
    for (U64 number = 5; number <= ceiling; number += 2) {
        if (is_prime_u64(number)) {
            printf("Prime #%lu = %lu\n", index, number);
            index++;
        }
    }
}

void list_primes(U64 ceiling) {
    if (ceiling < 2) {
        printf("No primes were found\n");
        exit(EXIT_SUCCESS);
    }
    printf("Prime #1 = 2\n");
    printf("Prime #2 = 3\n");

    if (ceiling <= U8_MAX) list_primes_u8((U8)ceiling);
    else if (ceiling <= U16_MAX) list_primes_u16((U16)ceiling);
    else if (ceiling <= U32_MAX) list_primes_u32((U32)ceiling);
    else list_primes_u64(ceiling);
}
