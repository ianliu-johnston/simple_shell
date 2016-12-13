/* remove this library call later */
#include <string.h>
int _strlen(char *s)
{
	int i;

	for (i = 0; *s; s++, i++)
		;
	return (i);
}
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}
/** All Functions below are unimplemented **/
/*** They are all here as place holders ***/
char *_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
