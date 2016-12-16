#include "shell.h"
char *_getline(int file)
{
	unsigned int i;
	char *buffer;
	static unsigned int total = 0;
	unsigned int buffer_size = 1024;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		perror("malloc for buffer failed\n");
		return (NULL);
	}
	_memset(buffer, '\0', 1024);
	i = read(file, buffer, 1024);
	total += i;
	while (i >= 1024)
	{
		_realloc(buffer, buffer_size, buffer_size + 1024);
		if (buffer == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		i = read(file, buffer + buffer_size, 1024);
		total += i;
	}
	i = 0;
	while (i <= total)
	{
		if (buffer[i] == ';' || buffer[i] == EOF || buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}
	i = 0;
	while (buffer[i] != '\0')
		i++;
	return (buffer);
}
char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
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
int is_alias(char *cmd)
{
	cmd++;
	return (0);
}
/**
  * reader - reads user input and forms it into a string.
  */
void reader(void)
{
	int exit_status;
	char *prompt, *buffer, **tokens;
	char *ex = "exit";
	env_path_t *linkedlist_path;

	exit_status = 0;
	prompt = "And baby says: ";
	linkedlist_path = list_from_path();
	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		buffer = _getline(STDIN_FILENO);
		if (_strncmp(ex, buffer, 5))
		{
			tokens = parser(buffer);
			if (is_alias(tokens[0]))
				is_alias(tokens[0]);
			else if (get_cmd_fun(tokens[0]))
				get_cmd_fun(tokens[0])(tokens);
			else
				executor(tokens, linkedlist_path);
		}
		else
		{
			free_list(linkedlist_path);
			linkedlist_path = NULL;
			free(buffer);
			exit(exit_status);
		}
	}
}
