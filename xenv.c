#include "shell.h"
/**
 * xenv - print environment.
 *
 * Return: Always 0.
 */
int xenv(void)
{

	int count = 0;


	for (count = 0; environ[count] != NULL; count++)
	{
		write(1, environ[count], _strlen(environ[count]));
		write(1, "\n", 1);


	}
	return (0);
}
