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
	if (access(argv[1], R_OK) == -1)
		open_file_err(argv[1]);

	fd = fopen(argv[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	monty_exe(fd);

	fclose(fd);
	return (exit_status);
}
