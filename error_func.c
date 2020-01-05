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
 * unknown_op_error - Prints unknown instruction error.
 * @opcode: Opcode where error occurred.
 * @lines: Line number where error occured.
 * Return: (EXIT_FAILURE).
 */
int unknown_op_error(char *opcode, unsigned int lines)
{
	fprintf(stderr, "L%u: unknown instruction %s\n",
		lines, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_error - invalid _push arg error.
 * @lines: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE).
 */
int no_int_error(unsigned int lines)
{
	fprintf(stderr, "L%u: usage: push integer\n", lines);
	return (EXIT_FAILURE);
}
