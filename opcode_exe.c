#include "monty.h"

// Add the following function to opcode_execution.c

/**
 * execute_opcode - Executes the opcode based on the instruction_t structure.
 * @opcode: The opcode to execute
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void execute_opcode(const char *opcode, stack_t **stack, unsigned int line_number)
{
    // TODO: Implement the switch/case structure to handle different opcodes
    // Example:
    if (strcmp(opcode, "push") == 0)
    {
        push(stack, line_number);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    // Add more cases for other opcodes
}
