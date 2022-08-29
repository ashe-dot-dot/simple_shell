#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>

extern char **environ;

char **split(char *line);
int execute(char **argv);
char *find_path(char *command);
int _strncmp(char *str1, char *str2, int n);
char *_strcat(char *dest, char *src);
char **get_dirs(void);

#endif
