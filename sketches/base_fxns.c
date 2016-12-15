#include "shell.h"
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
		return (NULL);
	}
	token = _strtok(str, delimit);
	tokenized[0] = token;
	i = 1;
	while (token)
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
	char *prompt, *buffer, **tokens;
	char *ex = "exit";
	env_path_t *linkedlist_path;

	prompt = "And baby says: ";
	linkedlist_path = list_from_path();
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		buffer = _getline(STDIN_FILENO);
		if (_strncmp(ex, buffer, 5))
		{
			tokens = parser(buffer);
			executor(tokens, linkedlist_path);
		}
		else
		{
			free_list(linkedlist_path);
			linkedlist_path = NULL;
			free(buffer);
			exit(0);
		}
	}
}
