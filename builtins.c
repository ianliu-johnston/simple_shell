#include "shell.h"
/**
  * get_cmd_fun - gets commands
  * @cmd: command to find
  * Return: Result of command on success, -1 on failure
  */
int (*is_builtin(char *cmd))()
{
	unsigned int i;
	builtin_cmds_t builds[] = {
		{"exit", _exit_with_grace},
		{"env", _env},
		{"cd", _cd},
		{"alias", _alias},
		{"history", _history},
		{"help", _help},
		{NULL, NULL}
	};

	/*
	   other useful shell builtins:
	   fg, echo, pushd, popd, type
	 */
	i = 0;
	while (*builds[i].fun != NULL)
	{
		if (_strncmp(builds[i].cmd_str, cmd, _strlen(builds[i].cmd_str)) == 0)
			return (builds[i].fun);
		i++;
	}
	return (NULL);
}
/**
  * _exit_with_grace - prints out the current environment
  * @linkedlist_path: Linked list to free.
  * @buffer: buffer to free
  * @tokens: Check for other inputs
  * Return: DON't NEED RETURN. Fix.
  */
int _exit_with_grace(env_t *linkedlist_path, char *buffer, char **tokens)
{
	int exit_status;

	exit_status = tokens[1] ? _atoi(tokens[1]) : 0;
	free_list(linkedlist_path);
	free(buffer);
	linkedlist_path = NULL;
	tokens = NULL;
	exit(exit_status);
	return(exit_status);
}
/**
  * _env - prints out the current environment
  * @str: argument list
  */
int _env(void)
{
	char **envir;
	for (envir = environ; *envir; envir++)
	{
		write(STDOUT_FILENO, *envir, _strlen(*envir));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
/**
  * _cd - changes working directory
  * @str: argument list
  */
int _cd(char *str)
{
	printf("cd skeleton works: %s\n", str);
	return (0);
}
/**
  * _alias - sets aliases or prints them out when no options are supplied
  * @str: argument list
  */
int _alias(char *str)
{
	printf("alias skeleton works: %s\n", str);
	return (0);
}
/**
  * _history - prints out history with no options,
  *  or does other operations on the history file
  * @str: argument list
  */
int _history(char *str)
{
	printf("history skeleton works: %s\n", str);
	return (0);
}
/**
  * _help - display help pages for builtin commands
  * @str: argument list
  */
int _help(char *str)
{
	printf("help skeleton works: %s\n", str);
	printf("help with no arguments prints a list of builtins\n");
	printf("Options: -d, -s, -m, Arguments: PATTERN\n");
	printf("If no arguments match PATTERN, return 1\n");
	return (0);
}
