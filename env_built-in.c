#include "shell.h"

/**
 * env_builtin - Prints the current environment.
 * Description: Prints one variable per line in the
 *              format 'variable'='value'.
 * @args: An array of arguments passed to the shell.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs -> (-1).
 *	   Otherwise - 0.
 */

int env_builtin(char **args, char __attribute__((__unused__)) **front)
{
	int i;
	char nChar = '\n';

	if (!environ)
		return (-1);

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &nChar, 1);
	}

	(void)args;
	return (0);
}
