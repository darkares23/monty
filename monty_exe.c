#include "monty.h"

char **tokens_op = NULL;

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

int monty_exe(FILE *fd)
{
	stack_t *new = NULL;
	char *buffer = NULL;
	unsigned int lines = 0, prev_line = 0;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	void (*op_f)(stack_t **h, unsigned int lineNumber);

	new = malloc(sizeof(stack_t));
	if (!new)
		return (EXIT_FAILURE);
	while (getline(&buffer, &len, fd) != -1)
	{
		lines++, tokens_op = split_str(buffer, DELIMS);
		if (!tokens_op)
			return (EXIT_FAILURE);
		op_f = get_op_func(tokens_op[0]);
		if (!op_f)
		{
			token_free(tokens_op), stack_free(&new);
			exit_status = EXIT_FAILURE;
			break;
		}
		prev_line = tokens_len(), op_f(&new, lines);
		if (tokens_len() != prev_line)
		{
			if (tokens_op && tokens_op[prev_line])
				exit_status = atoi(tokens_op[prev_line]);
			else
				exit_status = EXIT_FAILURE;
			break;
		}
		token_free(tokens_op);
	}
	stack_free(&new);
	if (buffer == 0)
	{
		free(buffer);
		return (EXIT_FAILURE);
	}
	free(buffer);
	return (exit_status);
}
