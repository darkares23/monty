#include "monty.h"

/**
 * get_op_func - search the code with its function.
 * @opcode: The func code.
 * Return: function.
 */
void (*get_op_func(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
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
 * monty_exe - Primary function to execute a Monty bytecodes script.
 * @fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */

void monty_exe(FILE *fd)
{
	char *buff = NULL;
	size_t n = 0;
	int line_number = 1;

	while (getline(&buff, &n, fd) != EOF)
	{
		split_str(buff, line_number);
		line_number++;
	}
	free(buff);
}
