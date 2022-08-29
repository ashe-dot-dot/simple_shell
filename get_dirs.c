#include "main.h"

/**
 * get_dirs - returns the directoris in the PATH
 * Return: double pointer char array of directories in PATH
 */
char **get_dirs(void)
{
	int i, j;
	char **dirs, *token;

	i = 0;
	while (environ[i] != NULL)
	{
		if (_strncmp("PATH", environ[i], 4) == 0)
		{
			dirs = malloc(1024 * sizeof(char *));
			if (dirs == NULL)
				return (NULL);

			token = strtok(environ[i], "=");
			j = 0;
			while (token != NULL)
			{
				token = strtok(NULL, ":");
				dirs[j] = token;
				j++;
			}
		}
		i++;
	}

	return (dirs);
}
