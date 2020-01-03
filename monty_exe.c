#include "monty.h"

/**
 * get_op_func - search the code with its function.
 * @opcode: The func code.
 * Return: function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _pall},
		{"pall", _push},
		{NULL, NULL}
	};
	int i = 0;

	for (; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].func);
	}

	return (NULL);
}

/**
 * run_monty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */

int monty_exe(FILE *fd)
{
stack_t *new = NULL;
char *buffer = NULL, **tokens_op;
unsigned int lines = 0;
size_t len = 0, exit_status = EXIT_SUCCESS;
void (*op_f)(stack_t **h, unsigned int lineNumber);

new = malloc(sizeof(stack_t));
if (!new)
	return(1);
	
new->n = STACK;
new->prev = NULL;
new->next = NULL;

while (getline(&buffer, &len, fd) != 1)
{
	lines++;

	tokens_op = split_str(buffer, " \t\n");
	op_f = get_op_func(tokens_op[0]);
	op_f(&new, lines);
	break;

}
if (buffer == 0)
{
	free(buffer);
	return (EXIT_FAILURE);
}

free(buffer);
return (exit_status);
}
