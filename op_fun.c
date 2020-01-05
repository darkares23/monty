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
	stack_t *tmp_node;

	tmp_node = *stack;
	if (*stack != NULL)
		printf("%i\n", tmp_node->n);
	else
		pint_err(linenum);
}

/**
 * _pop - Removes the top value element.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _pop(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp, *eraser;

	tmp = *stack;
	if (tmp == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", linenum);
		free_head(head);
		exit(EXIT_FAILURE);
		}
	eraser = *stack;
	*stack = tmp->next;
	tmp = tmp->next;
	if (tmp != NULL)
		tmp->prev = NULL;
	free(eraser);
}

/**
 * _swap - Swaps the top two value elements.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _swap(stack_t **stack, unsigned int linenum)
{
	stack_t *tmp_node = *stack;
	int count = 0, tmp_value = 0;

	while (tmp_node)
	{
		tmp_node = tmp_node->next;
		count++;
	}
	if (count >= 2)
	{
		tmp_node = *stack;
		tmp_value = tmp_node->n;
		tmp_node->n = tmp_node->next->n;
		tmp_node->next->n = tmp_value;
	}
	else
	{
		printf("L<%d>: can't swap, stack empty\n", linenum);
		free_head(head);
		exit(EXIT_FAILURE);
	}
}
