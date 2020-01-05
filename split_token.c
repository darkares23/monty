#include "monty.h"
stack_t *head = NULL;
/**
 *split_str - Function to copy
 *@str: edited variable
 *@delim: edited variable
 *Return: always 0
 */
void split_str(char *str, int linenum)
{
	char *opcode, *buff, *delim;

	delim = "\n \t";
	opcode = strtok(str, delim);
	buff = strtok(NULL, delim);

	if (opcode != NULL)
	{
		if (opcode[0] == '#')
			return;
		op_validation(buff, opcode, linenum);
	}
}

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