#ifndef PARSER_H
#define PARSER_H

#include "unsigned.h"

/* Enums */
typedef enum {
    NONE = 0,
    LIST_PRIMES = 1,
    CHECK_NUMBER = 2,
    FIND_PRIME_INDEX = 3
} Mode;

/* Structs */
typedef struct {
    Mode mode;
    U64 ceiling;
    U64 number;
    U64 index;
} Options;

/* Constants */
static const char USAGE_MESSAGE[] = "Usage %s [-?] [-n number] [-i index] "
                                    "[-c ceiling]";
static const U64 MIN_VALUE = U64_MIN;
static const U64 MAX_VALUE = U64_MAX - 1;
static const U64 MAX_DIGITS = 20;
static const U64 BUFFER_SIZE = MAX_DIGITS + 1;
static const Mode DEFAULT_MODE = NONE;
static const U64 DEFAULT_CEILING = 0;
static const U64 DEFAULT_NUMBER = 0;
static const U64 DEFAULT_INDEX = 0;

/* Functions */
U64 parse_u64(const char* buffer, const char* name);
U64 parse_ceiling(const char* buffer);
U64 parse_number(const char* buffer);
U64 parse_index(const char* buffer);
Mode parse_mode(const char* buffer);
U64 request_ceiling(void);
U64 request_number(void);
U64 request_index(void);
Mode request_mode(void);
void parse_options(Options* options, int argc, char** argv);

#endif
