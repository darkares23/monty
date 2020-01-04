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
		printf("no file error");
		return (EXIT_FAILURE);
	}

	exit_status = monty_exe(fd);

	fclose(fd);
	printf("exit sta %i\n", exit_status);
	return (exit_status);
}
