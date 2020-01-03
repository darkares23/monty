#include "monty.h"
/**
 * myfree - frees a string of strings
 * @pp: string of strings
 *
 * Return: 0 exit success
 */
void myfree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}
