#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    if (argc != 2) {
        fprintf(stderr, "Open fail %s <file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!(file = fopen(argv[1], "r"))) {
        fprintf(stderr, "Can not open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1) {
        line_number++;
        char *opcode = strtok(line, " \t\n");

        if (!opcode)
            continue;

        execute_opcode(opcode, &stack, line_number);
    }

    free(line);
    fclose(file);

    return EXIT_SUCCESS;
}
