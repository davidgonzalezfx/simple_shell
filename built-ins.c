#include "shell.h"

/**
 * check_word - evalute alpha chars in string
 * @argv: arguments
 * Return: 1 if no alpha chars, 0 if yes
 */
int check_word(char **argv)
{
	int i;

	for (i = 0; i < _strlen(argv[1]); i++)
		if (!isdigit(argv[1][i]))
			return (0);
	return (1);
}

/**
 * exit_built_in - Handler of exit built-in command
 * Description: exit stop the shell, exit(status)
 * stops and 'return' status
 * @p: struct with all vars inside
 * Return: 1 if no alpha chars
 */
int exit_built_in(params p)
{
	if (p.argv[1])
	{
		if (check_word(p.argv))
		{
			int status = atoi(p.argv[1]);

			free(p.cmd);
			free(p.buff);
			free(p.argv);
			exit(status);
		}
		else
		{
			char error_msg[64] = "./hsh: ";
			char *cnt = _itoa(*(p.loop));

			_strcat(error_msg, cnt);
			_strcat(error_msg, ": ");
			_strcat(error_msg, p.argv[0]);
			_strcat(error_msg, ": Ilegal number: ");
			_strcat(error_msg, p.argv[1]);
			_strcat(error_msg, "\n");
			free(cnt);
			int error_len = _strlen(error_msg);

			write(2, error_msg, error_len);
			return (1);
		}
	}
	free(p.cmd);
	free(p.buff);
	free(p.argv);
	exit(0);
}

/**
 * env_built_in - Handler of exit built-in command
 */
void env_built_in(void)
{
	int i = 0;

	while (environ[i] != NULL)
		printf("%s\n", environ[i++]);
}
