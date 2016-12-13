# Holberton School - Holberton Shell(hsh)
Simple shell

## Getting Started
Brief intro on how to get the project up and running

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
Currently, the program segfaults unless you set the ``PS2`` variable.
```
export PS2="~> "
```
Compile like this:
```
gcc -Wall -Wextra -Werror -pedantic parser.c utilities.c main.c
```

## Usage
Currently, when run it looks like this:
```
vagrant:simple_shell $ ./a.out
$~> /bin/ls -l
exec.c main.c parser.c parser_functions.c
$~> ^C
vagrant:simple_shell$ 
```

## BUGS
1. If a space is before any tokens, function fails
2. Any tokens beyond the first is NULL.
3. There are sooo many more bugs...

## Test Suite
Describe

## Process
The process of building the shell is detailed in [process.md](process.md). For a list of resources and commands used, refer to [links.md](links.md)

## Authors
* **Ian Liu-Johnston** [Personal Website:](http://ianxaunliu-johnston.com) || [Twitter](https://twitter.com/Concativerse)
* **David Knoppers** [LinkedIn](https://www.linkedin.com/in/dknoppers) || [Twitter](https://twitter.com/dxknoppers)
