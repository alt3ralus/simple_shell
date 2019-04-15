#include "shell.h"
/**
 * execute - look in the path if a command exist, then execute
 * @path: the path separated in an array of strings
 * @args: the args of the comand to execute in an array of pointers with his
 * arguments.
 * Return: 0 on sucess. -1 in fail. Print the error with perror.
 */
int execute(char **path, char **args)
{
	int i = 0, status, len;
	char *path_arg;

	path_arg = args[0];
	while (path[i] != NULL)
	{
		i++;
		if (access(path_arg, F_OK) == 0)
		{
			if (fork() == 0)
			{
				if (execve(path_arg, args, NULL) != 0)
				{
					perror("./shell");
					exit(-1);
				}
			}
			else
			{
				wait(&status);
				if (i > 1)
					free(path_arg);
				return (0);
			}
		}
		else
		{
			if (path[i] != NULL)
			{
				len = _strlen(args[0]);
				if (i > 1)
					free(path_arg);
				path_arg = str_concat(path[i], args[0], len);
			}
		}
	}
	free(path_arg);
	perror("./shell");
	return (-1);
}
/**
 * str_concat - alloc a memory with malloc property to conc two strings
 * @s1: the first string to concatenate
 * @s2: the second string to concatenate
 * @n: the ammount to the s2 to concatenate
 * Return: the pointer that points to the new string
 */
char *str_concat(char *s1, char *s2, unsigned int n)
{
	unsigned int sz1;
	unsigned int sz2;
	unsigned int szt, i, j;
	char *s;

	sz1 = _strlen(s1) + 1;
	sz2 = _strlen(s2) + 1;
	if (n >= sz2)
		n = sz2;
	else
		n++;
	szt = sz1 + n - 1 + 1;
	s = malloc(sizeof(char) * (szt));
	if (s == NULL)
		return (NULL);
	for (i = 0; i < (sz1 - 1); i++)
		s[i] = s1[i];
	s[i] = '/';
	for (i = (sz1), j = 0; i < (szt - 1); i++)
	{
		s[i] = s2[j];
		j++;
	}
	s[i] = '\0';
	/* free(s2); */
	return (s);
}
