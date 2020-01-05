#include "monty.h"
/**
 * open_file_err - invalid _push arg error.
 * @argv: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE).
 */
void open_file_err(char *argv)
{
	fprintf(stderr, "Error: Can't open file %d\n", argv[1]);
	free_head(head);
	exit(EXIT_FAILURE);
}
/**
 * push_err - invalid _push arg error.
 * @linenum: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE).
 */
int push_err(int linenum)
{
	fprintf(stderr, "L%d: usage: push integer\n", linenum);
	free_head(head);
	exit(EXIT_FAILURE);
}
/**
 * pint_err - invalid _push arg error.
 * @linenum: Line number in Monty bytecodes file where error occurred.
 * Return: (EXIT_FAILURE).
 */
int pint_err(int linenum)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", linenum);
	free_head(head);
	exit(EXIT_FAILURE);
}
