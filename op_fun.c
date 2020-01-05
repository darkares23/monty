#include "monty.h"
/**
 * _push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _push(stack_t **stack, unsigned int linenum)
{
	stack_t *new, *tmp;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		malloc_err();
		return;
	}
	if (tokens_op[1] == NULL)
	{
		malloc_err();
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
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next, new->prev = tmp, new->next = NULL, tmp->next = new;
	}
}

/**
 * _pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top
 * @linenum: line number.
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
/**
 * _pint - Prints the top value of a stack_t.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _pint(stack_t **stack, unsigned int linenum)
{
	(void)linenum;

	if ((*stack)->next == NULL)
	{
		printf("L<line_number>: can't pint, stack empty");
		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * _pop - Removes the top value element.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _pop(stack_t **stack, unsigned int linenum)
{
	stack_t *next = NULL;

	(void)linenum;

	if ((*stack)->next == NULL)
	{
		printf("L<line_number>: can't pop, stack empty");
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * _swap - Swaps the top two value elements.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _swap(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp;

	(void)linenum;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		printf("L<line_number>: can't swap, stack empty");
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}