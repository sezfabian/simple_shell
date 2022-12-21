#include "shell.h"

/**
 * main - shell main entry point
 * Return: 0 success close
 */

int main(void)
{
	int runit = 1;
	ssize_t getv;
	size_t buffer = 0;
	char *line = NULL;
	char **tokens;
	struct stat fileStat;

	while (runit == 1)
	{
		write(1, "#cisfun$ ", 9);
		getv = getline(&line, &buffer, stdin);
		if (getv == -1 || getv == 255)
		{
			printf("Exiting shell");
			return (-1);
		}
		tokens = split_line(line);
		if (tokens[0] != NULL)
		{
			if (stat(tokens[0], &fileStat) >= 0)
			{
				_exec(tokens);
				free(tokens);
			}
			else if (isfiledefault(tokens[0]) == 2)
			{
				tokens[0] = _usrbin2(tokens[0]);
				_exec(tokens);
				free(tokens);
			}
			else if (isfiledefault(tokens[0]) == 1)
			{
				tokens[0] = _usrbin(tokens[0]);
				_exec(tokens);
				free(tokens);
			}
			else
				perror("./Shell: ");
		}
	}

	return (0);
}
