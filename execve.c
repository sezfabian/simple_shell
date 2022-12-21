#include "shell.h"

/**
 * _exec - executes comand in child process
 * @args: pointer to arguments
 * Return: void
 */

void _exec(char **args)
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execve(args[0], args, environ);
		perror("./Shell: ");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;

		do	{
			waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
		perror("Bash");
}
