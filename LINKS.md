# Links for Learning

## Repository Management with Git
* [README template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [Github Markdown Cheatsheet](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)
* [Resolving Merge Conflicts](https://githowto.com/resolving_conflicts)
* [Differences between git fetch and git pull](https://longair.net/blog/2009/04/16/git-fetch-and-merge/)
* [Manage and create new branches](https://github.com/Kunena/Kunena-Forum/wiki/Create-a-new-branch-with-git-and-manage-branches)
* [Basics of branching and merging](https://git-scm.com/book/en/v2/Git-Branching-Basic-Branching-and-Merging)
* [Branch Management](https://git-scm.com/book/en/v2/Git-Branching-Branch-Management)
* [Delete local and remote branches](http://stackoverflow.com/questions/2003505/how-to-delete-a-git-branch-both-locally-and-remotely)
* git repository management commands: 
	* ``git diff <file>`` Displays the differences between your local repository and what is in the public repo
	* ``git reset`` Resets your local repository to the current working state. 
	* ``git reset --hard origin/master`` Resets your local repository changes to reflect the public repository and deletes any changes from your local repository.
	* ``git checkout -- <file>`` Resets local changes on <file> to reflect what is in the public repo.
	* ``git checkout <hash> <file>`` Rolls back changes on <file> to the commit with hash value <hash>
	* ``git fetch`` Gets changes from public repository, without merging them into the current working tree
	* ``git merge`` Merges two branches together.
	* ``git pull`` Automatically merges commits from the remote repository without letting you review them first
	* ``git branch -d <branch_name>`` Deletes a branch that has been merged.
	* ``git branch -D <branch_name>`` Force deletes a branch that has not been fully merged. May loose unmerged work!
	* ``git push origin --delete <branch_name`` Force deletes a branch locally and remote.

## Linux History
* [Cannonical: Ken Thompson and Dennis Ritchie explain UNIX](https://www.youtube.com/watch?v=XvDZLjaCJuw)
* [The Story of Linux](https://www.youtube.com/watch?v=XMm0HsmOTFI)
* [Linux Kernel source code](http://lxr.free-electrons.com/source/kernel/sys.c#L832)
* [GNU Shell Walkthrough](https://www.gnu.org/software/libc/manual/html_node/Initializing-the-Shell.html#Initializing-the-Shell)
* [In-depth "What happens when you type ls"](http://sysadvent.blogspot.com/2010/12/day-15-down-ls-rabbit-hole.html)

## C Programming
* [Primary Resource, The Linux Programming Interface](https://www.nostarch.com/tlpi) Kerrisk, Michael. <em>The Linux Programming Interface: A Linux and UNIX System Programming Handbook.<em> San Francisco: No Starch, 2010. Print. 
* [Primary Resource, Bash Reference Manual](https://www.gnu.org/software/bash/manual/) Ramey, Chet, and Brian Fox. Bash reference manual: <em>reference documentation for Bash edition 4.4b, for Bash version 4.04b</em>. Bristol: Network Theory, 2016.
* [About Getline](https://blog.udemy.com/c-getline/)
* [Purdue CS Overview of Shell Structure](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
* [Some crazy in-depth thoughts on handling user input](http://www.azillionmonkeys.com/qed/userInput.html)
* [Tutorials point simple strtok() example](https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm)
* [Difference between size_t and unsigned int](http://stackoverflow.com/questions/19732319/difference-between-size-t-and-unsigned-int) -- size_t is an unsigned struct definition that can accomodate any data types. ssize_t is the signed version of size_t.
* [What are static functions?](http://www.geeksforgeeks.org/what-are-static-functions-in-c/) -- They are functions that are restricted to the source file they are referenced in.
* [Testing File Access - GNU](https://www.gnu.org/software/libc/manual/html_node/Testing-File-Access.html)
* [Differences between `exit()` and `_exit()`](http://www.unixguide.net/unix/programming/1.1.3.shtml) -- ``exit()`` is usually called only once in a function. ``_exit()`` is usually called by child processes from ``fork()``

## Bash Ninja Skillz
* [Redirection from catonmat.net](http://www.catonmat.net/blog/bash-one-liners-explained-part-three/)
* [bash-hackers wiki on Redirection](http://wiki.bash-hackers.org/syntax/redirection)

## MISC
* [Picture to ASCII Art](http://picascii.com/)
