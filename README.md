# Holberton School - Holberton Shell(hsh)
Code a simple shell for [Holberton School](https://www.holbertonschool.com/). This assignment incorporates all topics covered so far, and marks the conclusion of the section of the course that is strictly about learning C programming.

### Prerequisites
Only use the following functions and system calls:
```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
fstat (man 2 fstat)
getcwd (man 3 getcwd)
getline (man 3 getline)
kill (man 2 kill)
lstat (man 2 lstat)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (man 2 stat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
_exit (man 2 _exit)
```

### Installing
Compile like this:
```
gcc -Wall -Wextra -Werror -pedantic -g *.c -o hsh
```
The ``-g`` is for tracing Valgrind errors

## Usage
Currently, when run, it looks like this:
```
vagrant:simple_shell $ ./hsh
Dance Magic Dance
and baby says: cat main.c
#include "shell.h"

int main(void)
{
	printf("Dance Magic Dance\n");
	reader();
	return(0);
}
and baby says: exit 
vagrant:simple_shell$ 
```

## Description of File Structure
1. [shell.h](shell.h) - Header file: Contains all struct definitions, macros, standard library includes, and function prototypes.
2. [main.c](main.c) - Entry point to program. May be deleted. 
3. [parser.c](parser.c) - Includes all string parsing related functions: ``_getline()``, ``_strtok()``, ``parser()``, ``reader()``
4. [executor.c](executor.c) - Includes all functions related to executing an external program from the simple shell: ``executor()``
5. [environment.c](environment.c) - Includes all functions that deal with the environment and linked lists: ``add_node()``, ``list_from_path()``, ``free_list()``, ``search_os()``. The following are not built: ``_getenv()``, ``_setenv()``, ``_unsetenv()`` <em>(NOTE: there are a little too many functions in there.)</em>
6. [memory_management.c](memory_management.c) - Includes all utility functions that deal with memory management: ``_realloc()``, ``_memset()``
7. [strtok.c](strtok.c) - Includes the strtok function, as well as helper functions that do not need to be referenced elsewhere.
8. [string_operations.c](string_operations.c) - Includes all utility functions that deal with string operations: ``_strlen()``, ``_strcmp()``, ``_strdup()``, ``_strcat_realloc()`` 
7. [builtins.c](builtins.c) - Includes all builtin functions: <em>Currently, none have been built</em> ``env``, ``cd``, ``alias``, ``history``, and ``help`` are planned. 
9. [man_1_simple_shell](man_1_simple_shell) - Basic manual page. Currently does not have much in it, and is not very descriptive.
10. [LINKS.md](LINKS.md) - List of links used for learning how to make this project.
11. [AUTHORS](AUTHORS) - List of contributors.

## TODO
### Mandatory
- [x] Deal with EOF -- Is is correct?
- [x] Parser interprets ``exit`` -- Currently, if the first 4 characters of the string are ``exit``, the shell will exit. Does it need to call a function to gracefully kill all running processes and exit the program?
- [x] Deal with path
- [x] Build env function

### Advanced
- [x] ``exit`` handles arguments to exit -- What is ``exit status 4``?

#### Parser
- [~] Catch ``^C`` (CTRL + C) -- Find the signal and how to ignore it? Disabled for development. 
- [ ] Handle ``;``
- [ ] Handle ``&&``, and ``||``
- [ ] Handle ``#`` Comments

#### Recreate standard library functions
- [x] getline
- [x] strtok
- [ ] getenv
- [ ] setenv
- [ ] unsetenv

#### Shell Builtins
- [x] register builtins before executing commands
- [ ] cd
- [ ] alias
- [ ] help
- [ ] history
- [ ] Deal with variables
- [ ] Scripts as input

## Bugs
- [x] When ``enter`` is hit, it segfaults
- [ ] When ``^C`` is hit, it stays on one line.
- [x] EOF (``^D``) it segfaults
- [x] Two unfreed mallocs somewhere. (Check with Valgrind.)
- [ ] Only delimiters handled are spaces and newlines.
- [ ] Optimization: Change the linked list for path to an array of strings
- [ ] ``_exit_with_grace()`` should have a void type.
- [ ] Change input type for ``_exit_with_grace()`` to a variadic function, instead of declaring each free call separately.

## Links
For a list of resources and commands used, refer to [LINKS.md](LINKS.md)

## Authors
* **Ian Liu-Johnston** [Personal Website:](http://ianxaunliu-johnston.com) || [Twitter](https://twitter.com/Concativerse)
* **David Knoppers** [LinkedIn](https://www.linkedin.com/in/dknoppers) || [Twitter](https://twitter.com/dxknoppers)
