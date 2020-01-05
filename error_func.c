#include "monty.h"

/**
 * use_err - Prints usage error messages.
 * Return: EXIT_FAILURE.
 */
int use_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
/**
 * malloc_err - Prints usage error messages.
 * Return: EXIT_FAILURE.
 */
int malloc_err(void)
{
	printf("Error: malloc failed");
	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Prints unknown instruction error messages.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in Monty bytecodes file where error occured.
 *
 * Return: (EXIT_FAILURE) always.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		line_number, opcode);
	return (EXIT_FAILURE);
}
