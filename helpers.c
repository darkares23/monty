#include "monty.h"
/**
 * token_free - frees a pointer of pointers
 * @pp: string of strings
 */
void token_free(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * stack_free - Frees a stack_t stack.
 * @stack: A pointer to the top stack
 */
void stack_free(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * head_free - frees head of linked list
 * @head: pointer to head
 */
void free_head(stack_t *head)
{
	if (head)
	{
		if (head->next)
			free_head(head->next);
		free(head);
	}
}
