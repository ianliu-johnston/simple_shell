#include "shell.h"
/**
  * is_builtin - checks if cmd is a builtin
  * @cmd: command to find
  * Return: On success - pointer to function, On Failure - NULL pointer
 (* other useful shell builtins:
 (* pwd, echo, pushd, popd, type
 (* * requires ^Z
 (* fg, bg
 (*  * Requires ^R
 (* reverse-i-search **HISTORY**
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
  * _exit_with_grace - Frees any remaining malloc'd spaces, and exits
  * @linkedlist_path: Linked list to free.
  * @buffer: buffer to free
  * @tokens: Check for other inputs
 (* * CHANGE TO VARIADIC LIST.
  * Return: -1 if exit fails.
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
	return(-1);
}
/**
  * _env - prints out the current environment
  * Return: 0 on success, -1 on catastrophic failure
  */
int _env(void)
{
	char **envir;

	envir = environ;
	if (!envir || !environ)
		return (-1);
	for ( ; *envir; envir++)
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
int _cd(env_t *linkedlist_path, char *buffer, char **tokens)
{
	printf("Changes the current working directory.\n");
	printf("The default location is $HOME\n");
	printf("'cd', 'cd -' and 'cd $HOME' all change to the default location\n");
	printf("%p\n", (void *)linkedlist_path);
	printf("%s\n", buffer);
	printf("%p\n", *tokens);
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
int _history(void)
{
	printf("history: manipulate or view the history of commands\n ");
	printf("'history', without any options, displays the list");
	printf("of previously used commands, and the number of those commands.\n");
	printf("'history -c' clears the history\n");
	printf("See the list of history entries in bash with 'help history'\n");
	return (0);
}
/**
  * _help - display help pages for builtin commands
  * @str: argument list
  */
int _help(void)
{
	printf("help with no arguments prints a list of builtins\n");
	printf("Options: -d, -s, -m, Arguments: PATTERN\n");
	printf("If no arguments match PATTERN, return 1\n");
	return (0);
}
