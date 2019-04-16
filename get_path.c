#include "shell.h"
/**
 * get_env - finds the var enviroment given by the user
 * @var: the type of var that the userts wants, example: HOME or PATH
 * @own_envir: the direction of the pointer to alocate the variable
 * Return: always 0 (for now)
 */

int get_env(char *var, char **own_envir)
{
	unsigned int i = 0;
	unsigned int len = 0;
	char *compare = NULL;

	len = _strlen(var);
	compare = malloc(sizeof(char) * (len + 1));
	compare[len] = '\0';
	while (environ[i] != NULL)
	{
		compare = _strncpy(compare, environ[i], len);
		if (_strcmp(compare, var) == 0)
		{
			len = _strlen(environ[i]);
			break;
		}
		i++;
	}
	free(compare);
	if (environ[i] == NULL)
		return (0);
	*own_envir = malloc(sizeof(char) * (len + 1));
	*own_envir = _strncpy(*own_envir, environ[i], len);
	return (0);

}
/**
 * _strcmp - compare two strings.
 *
 * @s1: the pointer that point the first string.
 * @s2: the pointer that point the second string.
 *
 * Return: return 0 if the strings are equal, otherwise if are different.
 */
int _strcmp(char *s1, char *s2)
{
	int p = 1;
	int number = 0;
	int i = 0;

	while (p)
	{
		number = s1[i] - s2[i];
		if ((s1[i] == '\0') && (s2[i] == '\0'))
			p = 0;
		if (number != 0)
			p = 0;
		else
			i++;
	}
	return (number);
}
/**
 * _strlen - find the size of a string.
 *
 * @s: the string to count
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int l;

	for (l = 0; *s != 0; s++)
		l++;
	return (l);
}
/**
 * _strncpy - copy a string.
 *
 * @dest: the pointer that point the destinity of the string.
 * @src: the pointer thar point the string origin to be copied.
 * @n: the number of bytes to be copied.
 *
 * Return: return the copy string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && (*(src + i) != '\0'))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
