int _strlen(char *s)
{
	int i;

	for (i = 0; *s; s++, i++)
		;
	return (i);
}
/* FUNCTIONS TO IMPLEMENT*/
/**
  * ssize_t getline(char **lineptr, size_t *n, FILE *stream)
  * int strncmp(char *s1, char *s2, unsigned int byes)
  * printf()
  * char *strtok(char *str, const char *delim)
  **/
