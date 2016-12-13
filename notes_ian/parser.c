#include "parser.h"
#include "utilities.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
  * executor - executes a command from an array of tokens
  * @argv: array of tokens, ie. argument vectors
  * @envp: environment variables
  * Return: 0 on success, -1 on failure
  */
int executor(char *argv[])
{
	int i;
	pid_t child_status = 0;
	char *env[] = { "PATH=/bin", NULL };

	printf("Command: %s\n", argv[0]);
	i = 1;
	if (argv[i])
		printf("Flags: ");
	while (argv[i])
	{
		printf("argv[%d]: %s, ", i, argv[i]);
		i++;
	}
	printf("\n");

	switch(child_status = fork()) {
	case -1:
		printf("Error.");
		exit(99);
	case 0:
		if (execve(argv[0], argv, env) == -1)
			printf("ERROR\n");
		exit(99);
		break;
	default:
		sleep(1);
		break;
	}
	free(argv);
	return (0);
}

/**
  * parser - parses a string into tokens
  * @str: string to parse
  * Return: Double pointer to array of tokens
  */
char **parser(char *str)
{ char **tokenized, *token; char *delimit = " \n\t"; unsigned int i, wc, flag;

	for (i = 0, wc = 1; str[i]; i++)
	{
		if (str[i] == ' ' && flag == 0)
			flag = 1, wc++;
		if (str[i] != ' ')
			flag = 0;
	}
	if ((tokenized = malloc((wc + 1) * sizeof(char *))) == NULL)
		printf("Malloc Error\n"), exit(99);
	token = strtok(str, delimit);
	tokenized[0] = token;
	i = 1;
	while (token != NULL)
	{
		token = strtok(NULL, delimit);
		tokenized[i] = token;
		i++;
	}
	return (tokenized);
}
/**
  * reader - reads user input and forms it into a string.
  * @envp: environment variables inherited from calling shell
  */
void reader(void)
{
	int bytes_read;
	size_t len;
	char *str,*PS2 = getenv("PS2");

	bytes_read =  len = 0;
	while (bytes_read != -1)
	{
		write(STDOUT_FILENO, PS2, _strlen(PS2));
		bytes_read = getline(&str, &len, stdin);
		executor(parser(str));
	}
}
