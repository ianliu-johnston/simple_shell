#include "shell.h"
/**
  * _setenv_usr - sets environmental variables as user defines
  * @tokens: KEY=VALUE pair
  * Return: 0 on success, -1 on failure
  */
int _setenv_usr(char **tokens)
{
	int i, status, wc;
	char *key, *value, *saveptr;

	for (i = 0, wc = 1; tokens[1][i]; i++)
		if (tokens[1][i] == '=')
			wc++;
	for (i = 0; tokens[i]; i++)
		;
	if (!tokens[1] || i == 0 || wc != 2)
	{
		simple_print("setenv: Usage: setenv KEY=VALUE\n");
		return (-1);
	}
	key = _strtok_r(tokens[1], "=", &saveptr);
	value = _strtok_r(NULL, "=", &saveptr);
	status = _setenv(key, value, 0);
	if (status == 0)
		return (status);
	return (-1);
}
/**
  * _alias - sets aliases or prints them out when no options are supplied
  * Return: 0
  */
int _alias(void)
{
	simple_print("alias: usage: alias [-p] [name[=value] ... ]\n");
	simple_print("\tSet or view aliases.\n\tSet with name=value\n");
	simple_print("\tView list of aliases with no arugments or -p\n");
	return (0);
}
/**
  * _history - prints out history with no options,
  *  or clears history with -c
  * Return: 0 on success, 1 if history cannot be cleared.
  */
int _history(void)
{
	simple_print("history: usage: history [-c]\n");
	simple_print("\tView the history of commands\n ");
	simple_print("\t'history -c' clears the history\n");
	return (0);
}
/**
  * bowie - easter egg. Displays ASCII picture of Bowie
  * Return: 1947, the year Bowie was born
  */
int bowie(void)
{
	int txt_file, total, read_status;
	size_t letters = 7483;
	char *filename = "bowie.txt";
	char buffer[BUFSIZE];

	if (filename == NULL)
		return (0);
	txt_file = open(filename, O_RDONLY);
	if (txt_file == -1)
		return (0);
	total = 0;
	read_status = 1;
	while (letters > BUFSIZE && read_status != 0)
	{
		read_status = read(txt_file, buffer, BUFSIZE);
		write(STDOUT_FILENO, buffer, read_status);
		total += read_status;
		letters -= BUFSIZE;
	}
	read_status = read(txt_file, buffer, letters);
	write(STDOUT_FILENO, buffer, read_status);
	total += read_status;
	close(txt_file);
	return (1947);
/**	return (total); */
}
