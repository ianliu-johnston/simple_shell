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
		{"alias", _alias},
		{"cd", _cd},
		{"env", _env},
		{"exit", _exit_with_grace},
		{"history", _history},
		{"setenv", _setenv_usr},
		{"bowie", bowie},
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
int _exit_with_grace(char **tokens, env_t *linkedlist_path, char *buffer)
{
	unsigned char exit_status;
	int i;

	for (i = 0; tokens[1] && tokens[1][i]; i++)
	{
		if (!_isdigit(tokens[1][i]))
		{
			simple_print("numeric argument required, exiting\n");
			break;
		}
	}
	exit_status = tokens[1] && i >= _strlen(tokens[1]) ? _atoi(tokens[1]) : 0;
	if (linkedlist_path && buffer && tokens)
	{
		free_list(linkedlist_path);
		linkedlist_path = NULL;
		free(buffer);
		buffer = NULL;
		free(tokens);
		tokens = NULL;
	}
	exit(exit_status);
	return (-1);
}
/**
  * _env - prints out the current environment
  * @tokens: tokenized strings
  * @environment: linked list environment
  * Return: 0 on success, -1 on catastrophic failure
  */
int _env(char **tokens, env_t *environment)
{
	char **envir;

	if (tokens[1])
		simple_print("No arguments are necessary\n");
	envir = environ;
	if (!envir || !environ)
		return (-1);
	for ( ; *envir; envir++)
	{
		write(STDOUT_FILENO, *envir, _strlen(*envir));
		write(STDOUT_FILENO, "\n", 1);
	}
	environment++;
	return (0);
}
/**
  * _cd - changes working directory
  * @tokens: argument list
  * Return: 0 on success
  */
int _cd(char **tokens)
{
	char *target;
	char pwd[BUFSIZE];
	char *home;

	home = _getenv("HOME");
	if (tokens[1])
	{
		if (tokens[1][0] == '~' && !tokens[1][1])
			target = home;
		else if (tokens[1][0] == '-' && !tokens[1][1])
			target = _getenv("OLDPWD");
		else
			target = tokens[1];
	}
	else
		target = home;
	if (target == home)
		chdir(target);
	else if (access(target, F_OK | R_OK) == 0)
		chdir(target);
	else
		simple_print("Could not find directory\n");
	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("PWD", getcwd(pwd, sizeof(pwd)), 1);
	return (0);
}
