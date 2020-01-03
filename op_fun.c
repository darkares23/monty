#include "monty.h"

void _push(stack_t **stack, unsigned int linenum)
{
	stack_t *new = *stack, *tmp;

	if (linenum > 0)
	{
		tmp = (*stack)->next;
			new->prev = *stack;
			new->next = tmp;
			if (tmp)
				tmp->prev = new;
			(*stack)->next = new;

		printf("im alive!!!!");
	}
	printf("im alive!!!!");
}
void _pall(stack_t **stack, unsigned int linenum)
{
	stack_t *new = *stack, *tmp;

	if (linenum > 0)
	{
		tmp = (*stack)->next;
			new->prev = *stack;
			new->next = tmp;
			if (tmp)
				tmp->prev = new;
			(*stack)->next = new;

		printf("im alive!!!!");
	}
	printf("im alive!!!!");
}