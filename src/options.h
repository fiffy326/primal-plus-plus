#ifndef OPTIONS_H
#define OPTIONS_H

#include "mode.h"
#include "natural_number.h"

/* Structs */
typedef struct {
    Mode mode;
    NN64 ceiling;
    NN64 index;
    NN64 number;
} Options;

/* Functions */
void parse_options(Options *options, int argc, char **argv);

#endif // OPTIONS_H
