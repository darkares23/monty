#include "monty.h"
/**
 * _add - adds two top value element.
 * @stack: A pointer to the top
 * @linenum: line number.
 */
void _add(stack_t **stack, unsigned int linenum)
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
		tmp_value = tmp_node->n + tmp_node->next->n;
		tmp_node->next->n = tmp_value;
		_pop(stack, linenum);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", linenum);
		free_head(head);
		exit(EXIT_FAILURE);
	}
}
/**
 * _nop - doesn’t do anything.
 *@stack: address of the head
 *@line_number: line number of the command in monty file
 *
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
}
/**
 *_sub - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 *@stack: A pointer to the top mode node of a stack_t linked list.
 *@linenum: The current working line number of a Monty bytecodes file.
 *Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void _sub(stack_t **stack, unsigned int linenum)
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
		tmp_value = tmp_node->next->n - tmp_node->n;
		tmp_node->next->n = tmp_value;
		_pop(stack, linenum);
	}
	else
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", linenum);
		free_head(head);
		exit(EXIT_FAILURE);
	}
}
