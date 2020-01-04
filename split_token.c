#include "monty.h"
/**
 *split_str - Function to copy
 *@str: edited variable
 *@delim: edited variable
 *Return: always 0
 */
char **split_str(char *str, const char *delim)
{
	int len = 0, numLetters = 0, i = 0;
	char **token_list = NULL;
	char *tempStr = NULL;
	char *token = NULL;

	tempStr = malloc(sizeof(char *) + strlen(str));
	if (tempStr == NULL)
	{
		perror("Error");
		free(tempStr);
	}
	/*letters count*/
	while (str[len] != '\0')
	{
		if (str[len] == '\n')
			str[len] = '\0';
		if (str[len] != delim[0])
			numLetters++;
		len++;
	}
	tempStr = strcpy(tempStr, str);
	token_list = malloc((sizeof(char *) * (numLetters + 1)));
	if (token_list == NULL)
	{
		perror("Error");
		free(token_list);
	}
	token = strtok(tempStr, DELIMS);
	while (token)
	{
		token_list[i] = malloc(sizeof(char) * ((strlen(token)) + 1));
		if (token_list[i] == NULL)
			token_free(token_list);
		strcpy(token_list[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	token_list[i] = NULL;
	free(tempStr);
	return (token_list);
}
