#include "monty.h"

/**
 * use_err - Prints usage error messages.
 *
 * Return: EXIT_FAILURE.
 */
int use_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}
