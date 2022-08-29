#include "main.h"

/**
 * execute - executes a UNIX command
 *
 * @argv: array of command and arguments
 *
 * Return: 1 on succes, 0 on failure
 */
int execute(char **argv)
{
	int status;
	pid_t child_pid;

	if (_strncmp("/", argv[0], 1) != 0)
		argv[0] = find_path(argv[0]);

	if (argv[0] == NULL)
	{
		perror("Error");
		return (0);
	}

	child_pid = fork();
	if (child_pid == -1)
		return (0);
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(argv[0]);
			return (0);
		}
		else
		{
			return (1);
		}
	}
	else
	{
		wait(&status);
		free(argv[0]);
		return (0);
	}
}
