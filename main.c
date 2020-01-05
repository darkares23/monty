#include "monty.h"
stack_t *head = NULL;

/**
 * main - Interpreter of the Monty Language
 * @argc: argument count
 * @argv: the list of arguments
 * Return: 1 if passed
 */

int main(int argc, char **argv)
{
	FILE *fd = NULL;

	if (argc != 2)
		use_err();
	if (access(argv[1], R_OK) == -1)
		open_file_err(argv[1]);

	fd = fopen(argv[1], "r");

	if (!fd)
		open_file_err(argv[1]);

	monty_exe(fd);
	fclose(fd);

	free_head(head);

	return (0);
}
/**
 *split_str - Function to copy
 *@str: edited variable
 *@linenum: edited variable
 *Return: always 0
 */
void split_str(char *str, int linenum)
{
	char *opcode, *buff, *delim;

	delim = "\n \t\a\b";
	opcode = strtok(str, delim);
	buff = strtok(NULL, delim);

	if (opcode != NULL)
	{
		if (opcode[0] == '#')
			return;
		op_validation(buff, opcode, linenum);
	}
}
/**
 *op_validation - Function to copy
 *@buff: edited variable
 *@monty_opcode: edited variable
 *@line_number: line
 *Return: always 0
 */
void op_validation(char *buff, char *monty_opcode, int line_number)
{
	void (*op_f)(stack_t **, unsigned int);
	int signo = 1, j = 0;
	unsigned int int_value = 0;

	op_f = get_op_func(monty_opcode);
	if (op_f)
	{
		if (strcmp(monty_opcode, "push") == 0)
		{
			if (buff == NULL)
				push_err(line_number);
			else if (buff[0] == '-')
			{
				buff = buff + 1;
				signo = (signo * -1);
			}
			while (buff[j])
			{
				if (isdigit(buff[j]) == 0)
					push_err(line_number);
				j++;
			}
			int_value = atoi(buff) * signo;
			op_f(&head, int_value);
		}
		else
			op_f(&head, line_number);
		return;
	}
	unknown_op_error(monty_opcode, line_number);
}