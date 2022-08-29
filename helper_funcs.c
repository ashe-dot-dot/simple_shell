#include "main.h"

/**
 * split - splits the user command into array of strings
 *
 * @line: the user input
 *
 * Return: string array
 */
char **split(char *line)
{
	int i;
	char **args;
	char *token;

	token = strtok(line, " \t\r\n\a");

	i = 0;
	args = malloc(1024 * sizeof(char *));
	if (args == NULL)
		exit(EXIT_FAILURE);
	while (token != NULL)
	{
		args[i] = token;
		token = strtok(NULL, " \t\r\n\a");
		i++;
	}

	return (args);
}

/**
 * _strncmp - compares to strings at most n bytes
 *
 * @str1: string 1
 * @str2: string 2
 * @n: number of bytes to compare
 *
 * Return: 0 if str1 and str2 are equal
 * negative number if str1 is less than str2
 * positive number if str1 is greater than str2
 */
int _strncmp(char *str1, char *str2, int n)
{
	int i, cmp;

	i = 0;
	cmp = 0;
	while (cmp == 0 && i < n)
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			break;
		cmp = str1[i] - str2[i];
		i++;
	}

	return (cmp);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return:  a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *str;
	int i, j;

	str = malloc(1024 * sizeof(char));
	if (str == NULL)
		return (NULL);

	i = 0;
	while (dest[i] != '\0')
	{
		str[i] = dest[i];
		i++;
	}

	j = 0;
	while (src[j] != '\0')
	{
		str[i] = src[j];
		i++;
		j++;
	}

	str[i] = '\0';
	return (str);
}
