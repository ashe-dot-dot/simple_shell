#include "main.h"

/**
 * main - entry point of the program
 *
 * @ac: the number of argumnts passed to the program
 * @av: arguments passed to the program
 *
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char **av)
{
	ssize_t nread;
	char *line = NULL, **argv;
	size_t len;

	(void)av;
	if (ac != 1)
		return (1);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
		{
			write(1, "#cisfun$ ", 9);
		}
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		if (nread == 1)
			continue;
		if (_strncmp("exit", line, 4) == 0)
			exit(EXIT_SUCCESS);
		if (_strncmp("env", line, 3) == 0)
		{
			while (*environ)
				printf("%s\n", *environ++);
			continue;
		}

		argv = split(line);
		execute(argv);
		free(argv);
	}

	free(line);
	return (0);
}
