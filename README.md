# Simple Shell Group Project

.Resources

.Read or watch:

.Unix shell

.Thompson shell

.Ken Thompson


.Everything you need to know to start coding your own shell concept page

..General

Who designed and implemented the original Unix operating system

Who wrote the first version of the UNIX shell

Who invented the B programming language (the direct predecessor to the C programming language)

Who is Ken Thompson

How does a shell work

What is a pid and a ppid

How to manipulate the environment of the current process

What is the difference between a function and a system call

How to create processes

What are the three prototypes of main

How does the shell use the PATH to find the programs

How to execute another program with the execve system call

How to suspend the execution of a process until one of its children terminates

What is EOF / “end-of-file”?



Requirements

General

Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=g
nu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

Your shell should not have any memory leaks

No more than 5 functions per file

All your header files should be include guarded

Use system calls only when you need to (why?)

Example of error with sh:

$ echo "qwerty" | /bin/sh

/bin/sh: 1: qwerty: not found

$ echo "qwerty" | /bin/../bin/sh

/bin/../bin/sh: 1: qwerty: not found

$

Same error with your program hsh:


$ echo "qwerty" | ./hsh

./hsh: 1: qwerty: not found

$ echo "qwerty" | ./././hsh

./././hsh: 1: qwerty: not found

$

List of allowed functions and system calls


.access (man 2 access)

.chdir (man 2 chdir)

.close (man 2 close)

.closedir (man 3 closedir)

.execve (man 2 execve)

.exit (man 3 exit)

._exit (man 2 _exit)

.fflush (man 3 fflush)

.fork (man 2 fork)

.free (man 3 free)

.getcwd (man 3 getcwd)

.getline (man 3 getline)

.getpid (man 2 getpid)

.isatty (man 3 isatty)

.kill (man 2 kill)

.malloc (man 3 malloc)

.open (man 2 open)

.opendir (man 3 opendir)

.perror (man 3 perror)

.read (man 2 read)

.readdir (man 3 readdir)

.signal (man 2 signal)

.stat (__xstat) (man 2 stat)

.lstat (__lxstat) (man 2 lstat)

.fstat (__fxstat) (man 2 fstat)

.strtok (man 3 strtok)

.wait (man 2 wait)

.waitpid (man 2 waitpid)

.wait3 (man 2 wait3)

.wait4 (man 2 wait4)

.write (man 2 write)