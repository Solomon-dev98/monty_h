#ifndef MONTY_H
#define MONTY_H

#include <stdio.h> 

/**
 * struct stack_s - repr of a stack
 * @n: integer
 * @prev: points to the pre
 * @next: points to the next
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: functions to handle the opcode
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
int is_integer(const char *str);


#endif /* MONTY_H */
