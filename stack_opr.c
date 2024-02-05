#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void push(stack_t **stack, unsigned int line_number) {
    if (!token || !is_integer(token)) {
        fprintf(stderr, "L%u: provide an integer\n", line_number);
        exit(1);
    }

    int value = atoi(token);

    stack_t *n_node = malloc(sizeof(stack_t));
    if (!n_node) {
        fprintf(stderr, "exe failed\n");
        exit(1);
    }

    n_node->n = value;
    n_node->prev = NULL;
    n_node->next = *stack;

    if (*stack) {
        (*stack)->prev = n_node;
    }

    *stack = n_node;
}

void pall(stack_t **stack, unsigned int line_number) {
    stack_t *current = *stack;
    while (current) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
