#ifndef MODE_H
#define MODE_H

#include <string>

/* Enums */
typedef enum { NONE, LIST_TERMS, FIND_NTH_TERM, TEST_CANDIDATE } Mode;

/* Functions */
Mode parse_mode(const std::string& arg_input);
Mode prompt_mode();

#endif // MODE_H