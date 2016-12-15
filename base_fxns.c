#include "base_fxns.h"
#include "utilities.h"
#include "environment.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
/**
  * executor - executes a command from an array of tokens
  * @argv: array of tokens, ie. argument vectors
  * Return: 0 on success, -1 on failure
  */
void executor(char *argv[], env_path_t *linkedlist_path)
{
	pid_t child_status = 0;
	char *abs_path;

	abs_path = search_os(argv[0], linkedlist_path);
	if (!abs_path)
	{
		perror("command not found\n");
		return;
	}

	switch (child_status = fork())
	{
	case -1:
		perror("fork failed\n");
		break;
	case 0:
		if (execve(abs_path, argv, environ) == -1)
			perror("execution failed\n");
		break;
	default:
		free(abs_path);
		if (wait(NULL) == -1)
			perror("wait failed\n");
		break;
	}
}
/**
  * parser - parses a string into tokens
  * @str: string to parse
  * Return: Double pointer to array of tokens
  */
char **parser(char *str)
{
	char **tokenized, *token;
	char *delimit = "\n \t";
	unsigned int i, wc, flag;

	for (i = 0, wc = 1; str[i]; i++)
	{
		if (str[i] == ' ' && flag == 0)
			flag = 1, wc++;
		if (str[i] != ' ')
			flag = 0;
	}
	tokenized = malloc((wc + 1) * sizeof(char *));
	if (tokenized == NULL)
	{
		perror("malloc failed\n");
		return (0);
	}
	token = _strtok(str, delimit);
	tokenized[0] = token;
	i = 1;
	while (token != NULL)
	{
		token = _strtok(NULL, delimit);
		tokenized[i] = token;
		i++;
	}
	return (tokenized);
}
/**
  * reader - reads user input and forms it into a string.
  */
void reader(void)
{
	char *prompt, *buffer;
	char *ex = "exit";
	env_path_t *linkedlist_path;

	prompt = "And baby says: ";
	linkedlist_path = list_from_path();
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		buffer = _getline(STDIN_FILENO);
		if (_strncmp(ex, buffer, 5))
			executor(parser(buffer), linkedlist_path);
		else
			exit(0);
	}
}
