#include <stdio.h>
#include <stdlib.h>
#include "check_number.h"
#include "is_prime.h"
#include "unsigned.h"

void check_number_u8(U8 number) {
    if (is_prime_u8(number))
        printf("%u is prime\n", number);
    else
        printf("%u is not prime\n", number);

    exit(EXIT_SUCCESS);
}

void check_number_u16(U16 number) {
    if (is_prime_u16(number))
        printf("%u is prime\n", number);
    else
        printf("%u is not prime\n", number);

    exit(EXIT_SUCCESS);
}

void check_number_u32(U32 number) {
    if (is_prime_u32(number))
        printf("%u is prime\n", number);
    else
        printf("%u is not prime\n", number);

    exit(EXIT_SUCCESS);
}

void check_number_u64(U64 number) {
    if (is_prime_u64(number))
        printf("%lu is prime\n", number);
    else
        printf("%lu is not prime\n", number);

    exit(EXIT_SUCCESS);
}

void check_number(U64 number) {
    if (number <= U8_MAX) check_number_u8((U8)number);
    else if (number <= U16_MAX) check_number_u16((U16)number);
    else if (number <= U32_MAX) check_number_u32((U32)number);
    else check_number_u64(number);
}
