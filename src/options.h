#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>

#include "mode.h"
#include "unsigned.h"

/* Structs */
typedef struct {
    Mode mode;
    U64 ceiling;
    U64 index;
    U64 candidate;
} Options;

/* Functions */
std::string usage_message(const std::string& program_name);
void parse_options(Options* options, int argc, char** argv);

#endif // OPTIONS_H