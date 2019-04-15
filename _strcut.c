#include "shell.h"
/**
 * _strcut - A function that cuts every word from a sentence.
 * @line: str.
 * @separator: char.
 * @arg_0: the pointer that save the origin malloc allocation of the
 * array of strings
 * Return: Double pointer to.
 */

char **_strcut(char *line, const char *separator, char **arg_0)
{
	int count = 0;
	char *duplicate = NULL;
	char *token = NULL;
	char **retorno = NULL;

	duplicate = _strdup(line);
	*arg_0 = duplicate;
	token = strtok(line, separator);
	count++;
	while (token != NULL)
	{
		token = strtok(NULL, separator);
		count++;
	}

	retorno = malloc(sizeof(char *) * count);

	count = 0;

	retorno[count] = strtok(duplicate, separator);

	while (retorno[count] != NULL)
	{
		count++;
		retorno[count] = strtok(NULL, separator);
	}

	return (retorno);
}
/**
 * _strdup - create a copy of string recived as a parameter
 * @str: the string to copy
 *
 * Return: the pointer that point to the array created.
 */
char *_strdup(char *str)
{
	char *p;
	int i;
	int size;

	if (str == NULL)
		return (NULL);
	for (size = 0; str[size] != '\0'; size++)
		;
	size++;
	p = malloc(sizeof(char) * size);
	/* printf("_strdup malloc %p\n", (void*)p); */
	if (p == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		p[i] = str[i];

	return (p);
}
