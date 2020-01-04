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
 * tokens_len - Gets the len of tokens_op.
 * Return: Len.
 */
unsigned int tokens_len(void)
{
	unsigned int len = 0;

	while (tokens_op[len])
		len++;
	return (len);
}