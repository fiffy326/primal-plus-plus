#include <limits.h>
#include "is_prime.h"
#include "primality.h"
#include "unsigned.h"

Primality is_prime_u8(U8 number) {
    if (number == 1) return COMPOSITE;
    if ((number == 2) || (number == 3)) return PRIME;
    if ((!(number % 2)) || (!(number % 3))) return COMPOSITE;
    for (U8 div = 5; div * div <= number; div += 6) {
        if (!(number % div) || (!(number % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

Primality is_prime_u16(U16 number) {
    if (number == 1) return COMPOSITE;
    if ((number == 2) || (number == 3)) return PRIME;
    if ((!(number % 2)) || (!(number % 3))) return COMPOSITE;
    for (U16 div = 5; div * div <= number; div += 6) {
        if (!(number % div) || (!(number % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

Primality is_prime_u32(U32 number) {
    if (number == 1) return COMPOSITE;
    if ((number == 2) || (number == 3)) return PRIME;
    if ((!(number % 2)) || (!(number % 3))) return COMPOSITE;
    for (U32 div = 5; div * div <= number; div += 6) {
        if (!(number % div) || (!(number % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

Primality is_prime_u64(U64 number) {
    if (number == 1) return COMPOSITE;
    if ((number == 2) || (number == 3)) return PRIME;
    if ((!(number % 2)) || (!(number % 3))) return COMPOSITE;
    for (U64 div = 5; div * div <= number; div += 6) {
        if (!(number % div) || (!(number % (div + 2)))) return COMPOSITE;
    }
    return PRIME;
}

Primality is_prime(U64 number) {
    if (number < U8_MAX) return is_prime_u8((U8)number);
    else if (number < U16_MAX) return is_prime_u16((U16)number);
    else if (number < U32_MAX) return is_prime_u32((U32)number);
    else return is_prime_u64((U64)number);
}
