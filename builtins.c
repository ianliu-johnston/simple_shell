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
		{"help", _help},
		{"history", _history},
		{"setenv", _setenv_usr},
		{"unsetenv", _unsetenv_usr},
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
	free_list(linkedlist_path);
	linkedlist_path = NULL;
	free(buffer);
	buffer = NULL;
	free(tokens);
	tokens = NULL;
	exit(exit_status);
	perror("Exit failed\n");
	return(-1);
}
/**
  * _env - prints out the current environment
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
  * @str: argument list
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
	else if(access(target, F_OK | R_OK) == 0)
			chdir(target);
	else
		perror("Could not find directory\n");
	setenv("OLDPWD", _getenv("PWD"), 1);
	setenv("PWD", getcwd(pwd, sizeof(pwd)), 1);
	return (0);
}
/**
  * _help - display help pages for builtin commands
  * @tokens: list of arguments. tokens[1] is the only one needed
  * Return: 0 on success, 1 if PATTERN not found.
  */
int _help(char **tokens)
{
	if (!tokens[1])
	{
		simple_print("These shell commands are defined internally.\n");
		simple_print("\texit <RETURN_CODE>\n\tcd [ - | ~ ] <DIRECTORY>\n\tenv\n\thelp <BUILTIN>\n");
	}
	else if(!_strncmp(tokens[1], "help", 5))
	{
		simple_print("help: usage: help <BUILTIN>\n");
		simple_print("\tDisplays a help page for builtin functions.\n");
		simple_print("\tWith no arguments, print a list of all builtins\n");
		simple_print("\tIf no arguments match BUILTIN, return 1\n");
	}
	else if(!_strncmp(tokens[1], "cd", 3))
	{
		simple_print("cd: usage: cd [ - | ~ ] [DIRECTORY]\n");
		simple_print("\tChange working directory to [DIRECTORY]\n");
		simple_print("\t'cd' without any arguments or 'cd ~' brings the user to $HOME\n");
		simple_print("\t'cd -' brings the user to the last accessed directory\n");
	}
	else if (!_strncmp(tokens[1], "env", 4))
	{
		simple_print("env: usage: env\n");
		simple_print("\tPrints out the current environment\n\tAccepts no arguments\n");
	}
	else if (!_strncmp(tokens[1], "exit", 5))
	{
		simple_print("exit: usage: exit [n]\n\tExits the shell.\n");
		simple_print("\tIf [n] is supplied, exit with status of [n], ");
		simple_print("otherwise, exit status is 0\n");
	}
	else if (!_strncmp(tokens[1], "history", 8))
	{
		simple_print("history: usage: history [-c]\n\tView the history of commands\n");
		simple_print("\t'history -c' clears the history\n");
	}
	else if (!_strncmp(tokens[1], "setenv", 6))
	{
		simple_print("setenv: usage: setenv KEY=VALUE\n");
		simple_print("\tsetenv creates environmental variables with KEY=VALUE\n");
		simple_print("\tIt always overwrites existing variables\n");
		simple_print("\tThe command fails if the number of arguments is not exactly 1\n");
		simple_print("\tor if the argument is not in the format KEY=VALUE\n");
	}
	else
	{
		simple_print("No help topics found.\n");
		return (1);
	}
	return (0);
}
