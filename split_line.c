#include "shell.h"

/**
 * split_line - splits line input to string tokens
 * @line: string input
 * Return: pointer to tokens
 */

char **split_line(char *line)
{
	int length = 0;
	int capacity = 1;
	char **tokens = malloc(capacity * sizeof(char *));

	char *delimiters = " \t\r\n";
	char *token = strtok(line, delimiters);

	while (token != NULL)
	{
		tokens[length] = token;
		length++;

		if (length >= capacity)
		{
			capacity = (int) (capacity + 1);
			tokens = realloc(tokens, capacity * sizeof(char *));
		}

		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}
