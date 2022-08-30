#include "main.h"

/**
 * find_path - searchs the environmental variable $PATH for user input command
 *
 * @command: user input command
 *
 * Return: on success the relative path of user input command
 * NULL otherwise
 */
char *find_path(char *command)
{
	int i;
	char **dirs, *full_path;
	struct stat st;
	DIR *dir;

	dirs = get_dirs();

	i = 0;
	while (dirs[i] != NULL)
	{
		dir = opendir(dirs[i]);
		full_path = _strcat(dirs[i], _strcat("/", command));
		if (stat(full_path, &st) != 0)
		{
			full_path = NULL;
		}
		else
		{
			closedir(dir);
			break;
		}
		i++;
	}

	free(dirs);
	return (full_path);
}
