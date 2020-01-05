#include "monty.h"

/**
 * use_err - Prints usage error messages.
 * Return: EXIT_FAILURE.
 */
int use_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_head(head);
	exit(EXIT_FAILURE);
}
/**
 * malloc_err - Prints usage error messages.
 * Return: EXIT_FAILURE.
 */
int malloc_err(void)
{
	printf("Error: malloc failed");
	free_head(head);
	exit(EXIT_FAILURE);
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
	free_head(head);
	exit(EXIT_FAILURE);
}

/**
 * no_int_error - invalid _push arg error.
 * @lines: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE).
 */
int no_int_error(unsigned int lines)
{
	fprintf(stderr, "L%u: usage: push integer\n", lines);
	free_head(head);
	exit(EXIT_FAILURE);
}
