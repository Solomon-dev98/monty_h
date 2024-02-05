#include "monty.h"

/**
 * execute_opcode - Executes the opcode based on the instructions
 * @opcode: The opcode to execute
 * @stack: Pointer to the head
 * @line_number: Line number
 */
void execute_opcode(const char *opcode, stack_t **stack, unsigned int line_number)
{
    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
}
