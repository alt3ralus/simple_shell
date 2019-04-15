#include "shell.h"

/**
 * exc_built - check if an argumment is a builtin function
 * @args: the argumment to evaluate
 * Return: 0 if the argumment is a built-in function, 1 otwerwise
 */
int exc_built(char **args)
{
	int count;

	built_s builts[] = {

		{"exit", xexit},
		{ "env", xenv},
		{NULL, NULL}

	};


	for (count = 0; builts[count].name != NULL; count++)
	{
		if (_strcmp(args[0], builts[count].name) == 0)
		{
			(builts[count].fun)();
			return (0);
		}
	}
	return (1);
}
/**
 * xexit - exit function
 *
 * Return: - always 0
 */
int xexit(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
