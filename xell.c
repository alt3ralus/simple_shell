#include "shell.h"
/**
 * main - This is the minishell!
 * Return: 0 on sucess
 */
int main(void)
{
	char *arg_0 = NULL,  *path_0 = NULL,  *arg_sc_0, *line = NULL;
	char **arg_spl = NULL, **path_spl = NULL, **arg_scolon;
	size_t len = 0;
	ssize_t read = 0;
	char *sep_arg = "\t \n", *sep_var = "=:", *var = "PATH", *own_env = NULL;
	int i;

	signal(SIGINT, SIG_IGN);
	while (read != -1)
	{
		read = getline(&line, &len, stdin);
		i = 0;
		if (read != 1 && read != -1)
		{
			arg_scolon = _strcut(line, ";", &arg_sc_0);
			i = 0;
			while (arg_scolon[i] != NULL)
			{
				arg_spl = _strcut(arg_scolon[i], sep_arg, &arg_0);
				if (arg_spl[0] != NULL)
				{
					get_env(var, &own_env);
					if (exc_built(arg_spl) == 1)
					{
						path_spl = _strcut(own_env, sep_var, &path_0);
						execute(path_spl, arg_spl);
						free(own_env), free(arg_0), free(arg_spl);
						free(path_0), free(path_spl);
					}
				}
				i++;
			}
			free(arg_sc_0), free(arg_scolon);
		}
	}
	free(line);
	exit(EXIT_SUCCESS);
}
