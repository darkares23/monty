#include "monty.h"
/**
 * _push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @linenum: The current working line number of a Monty bytecodes file.
 */
void _push(stack_t **stack, unsigned int linenum)
{
	stack_t *new, *tmp;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("error %i", linenum);
		return;
	}
	if (tokens_op[1] == NULL)
	{
		printf("error %i", linenum);
		return;
	}
	for (i = 0; tokens_op[1][i]; i++)
	{
		if (tokens_op[1][i] == '-' && i == 0)
			continue;
		if (tokens_op[1][i] < '0' || tokens_op[1][i] > '9')
		{
			printf("error %i", linenum);
			return;
		}
	}
	new->n = atoi(tokens_op[1]);
	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		printf("aca2\n");
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
	
}

/**
 * _pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @linenum: The line number of a Monty bytecodes file.
*/

void _pall(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)linenum;
}