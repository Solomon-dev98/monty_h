#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Open fail %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Can not open file %s\n", argv[1]);
        exit(1);
    }

    stack_t *stack = NULL;

    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, file) != -1) {
        line_number++;
        char *opcode = strtok(line, " \t\n");

        if (!opcode)
            continue;

        execute_opcode(opcode, &stack, line_number);
    }

    free(line);
    fclose(file);

    return 0;
}
