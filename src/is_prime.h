#ifndef IS_PRIME_H
#define IS_PRIME_H

#include "primality.h"
#include "unsigned.h"

/* Functions */
Primality is_prime(U64 number);
Primality is_prime_u8(U8 number);
Primality is_prime_u16(U16 number);
Primality is_prime_u32(U32 number);
Primality is_prime_u64(U64 number);

#endif
