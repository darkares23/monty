#include "monty.h"

/**
 * main - Interpreter of the Monty Language
 * @argc: argument count
 * @argv: the list of arguments
 * Return: 1 if passed
 */

int main(int argc, char **argv)
{
	int exit_status = EXIT_SUCCESS;
	FILE *fd = NULL;

	if (argc != 2)
		return (use_err());

	fd = fopen(argv[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fd);
		return (EXIT_FAILURE);
	}

	exit_status = monty_exe(fd);

	fclose(fd);
	return (exit_status);
}
