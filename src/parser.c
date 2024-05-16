#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "unsigned.h"

U64 parse_u64(const char* buffer, const char* name) {
    U64 value;
    if ((value = strtoull(buffer, NULL, 10)) > U64_MAX) {
        fprintf(stderr, "Error: The %s provided was above the maximum allowed "
                "value (max: %lu)\n", name, U64_MAX);
        exit(EXIT_FAILURE);
    }
    if (!value) {
        fprintf(stderr, "Error: The %s provided was invalid or below the "
                "minimum allowed value (min: %lu)\n", name, U64_MIN);
        exit(EXIT_FAILURE);
    }
    return value;
}

U64 parse_ceiling(const char* buffer) {
    return parse_u64(buffer, "ceiling");
}

U64 parse_number(const char* buffer) {
    return parse_u64(buffer, "number");
}

U64 parse_index(const char* buffer) {
    return parse_u64(buffer, "index");
}

Mode parse_mode(const char* buffer) {
    Mode mode = (Mode)(U8)atoi(buffer);
    if ((mode > sizeof(Mode) - 1) || (mode == NONE)) {
        fprintf(stderr, "Error: Invalid mode\n");
        exit(EXIT_FAILURE);
    }
    else
        return mode;
}

U64 request_ceiling(void) {
    char buffer[BUFFER_SIZE];
    printf("Ceiling: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    printf("\n");
    return parse_number(buffer);
}

U64 request_number(void) {
    char buffer[BUFFER_SIZE];
    printf("Number: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    printf("\n");
    return parse_number(buffer);
}

U64 request_index(void) {
    char buffer[BUFFER_SIZE];
    printf("Prime index: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    printf("\n");
    return parse_index(buffer);
}

Mode request_mode(void) {
    char buffer[BUFFER_SIZE];
    printf("[1] = List primes below a ceiling\n");
    printf("[2] = Check if a number is prime\n");
    printf("[3] = Find the Nth prime\n");
    printf("[0] = Exit\n\n");
    printf("Mode: ");
    fflush(stdout);
    fgets(buffer, sizeof(buffer), stdin);
    printf("\n");
    return parse_mode(buffer);
}

void parse_options(Options* options, int argc, char** argv) {
    // Initialize default option
    options->mode = DEFAULT_MODE;
    options->ceiling = DEFAULT_CEILING;
    options->number = DEFAULT_NUMBER;
    options->index = DEFAULT_INDEX;

    // Add program name to usage message
    char* program_name = argv[0];
    int usage_len = strlen(USAGE_MESSAGE) + strlen(program_name) + 1;
    char usage_message[usage_len];
    snprintf(usage_message, usage_len, USAGE_MESSAGE, program_name);

    // Parse options
    int opt;
    const char optstring[] = ":c:i:n:";
    while ((opt = getopt(argc, argv, optstring)) != -1) {
        switch (opt) {
            case 'c':
            case ':':
                options->mode = LIST_PRIMES;
                options->ceiling = parse_ceiling(optarg);
                break;
            case 'n':
                options->mode = CHECK_NUMBER;
                options->number = parse_number(optarg);
                break;
            case 'i':
                options->mode = FIND_PRIME_INDEX;
                options->index = parse_index(optarg);
                break;
            case '?':
                fprintf(stderr, "%s\n", usage_message);
                exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Error: Invalid options\n%s\n", usage_message);
                exit(EXIT_FAILURE);
        }
    }

    // Handle additional arguments
    U8 extra_args = argc - optind;
    if (extra_args > 0) {
        fprintf(stderr, "Error: Invalid arguments\n%s\n", usage_message);
        exit(EXIT_FAILURE);
    }
}
