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
gcc -Wall -Wextra -Werror -pedantic *.c -o hsh
```

## Usage
Currently, when run, it looks like this:
```
vagrant:simple_shell $ ./hsh
and baby says: /bin/ls -l
exec.c main.c parser.c parser_functions.c
and baby says: ^C
vagrant:simple_shell$ 
```

## TODO
### Mandatory
- [ ] Deal with EOF -- Is is correct?
- [ ] Parser interprets ``exit`` -- Currently, if the first 4 characters of the string are ``exit``, the shell will exit. Does it need to call a function to gracefully kill all running processes and exit the program?
- [ ] Deal with path
- [ ] Build env function

### Advanced
- [ ] ``exit`` handles arguments to exit -- What is ``exit status 4``?

#### Parser
- [ ] Catch ``^C`` (CTRL + C) -- Find the signal and how to ignore it? 
- [ ] Handle ``;``
- [ ] Handle ``&&``, and ``||``
- [ ] Handle ``#`` Comments

#### Recreate standard library functions
- [x] getline
- [ ] strtok
- [ ] getenv
- [ ] setenv
- [ ] unsetenv

#### Shell Builtins
- [ ] cd
- [ ] alias
- [ ] help
- [ ] history
- [ ] Deal with variables
- [ ] Scripts as input

## Links
For a list of resources and commands used, refer to [links.md](links.md)

## Authors
* **Ian Liu-Johnston** [Personal Website:](http://ianxaunliu-johnston.com) || [Twitter](https://twitter.com/Concativerse)
* **David Knoppers** [LinkedIn](https://www.linkedin.com/in/dknoppers) || [Twitter](https://twitter.com/dxknoppers)
