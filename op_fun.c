#include "monty.h"
/**
 * _push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _push(stack_t **stack, unsigned int linenum)
{
	stack_t *new_node;
	stack_t *current = *stack;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		malloc_err();

	new_node->n = linenum;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (current != NULL)
	{
		current->prev = new_node;
	}
	head = new_node;
}

/**
 * _pall - Prints the values all stack.
 * @stack: A pointer to the top
 * @linenum: line number.
*/

void _pall(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp_node;

	(void)linenum;

	if (stack != NULL)
	{
		tmp_node = *stack;
		while (tmp_node != NULL)
		{
			printf("%d\n", tmp_node->n);
			tmp_node = tmp_node->next;
		}
	}
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
		printf("L<line_number>: can't pint, stack empty\n");
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
		printf("L<line_number>: can't pop, stack empty\n");
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
		printf("L<line_number>: can't swap, stack empty\n");
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