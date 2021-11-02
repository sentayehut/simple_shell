# Simple Shell Group Project
<<<<<<< HEAD

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

Compilation
our shell will be compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Testing

Your shell should work like this in interactive mode:

$ ./hsh

($) /bin/ls

hsh main.c shell.c

($)

($) exit

$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh

hsh main.c shell.c test_ls_2

$

$ cat test_ls_2

/bin/ls

/bin/ls

$

$ cat test_ls_2 | ./hsh

hsh main.c shell.c test_ls_2

hsh main.c shell.c test_ls_2

$

         Tasks

0. README, man, AUTHORS
=======
Table of contents

    What is the shell?
    About this project
    Essential Functionalities of the Simple Shell
    File description
    List of allowed functions and system calls for this project
    USAGE
    Example of Usage
    Bugs
    TEAM

What is the shell?

The shell is a program that takes commands from the keyboard via the terminal, and gives them to the operating system to perform.
To better understand how the shell actually works, you can read our Article.
About this project

This project is a simple version of the linux shell made for Holberton School taking part of the "Low-level programming & Algorithm - Linux and Unix system programming" projects.
It is created using the C programming Language and it can do many functionalities that a real shell does.
Essential Functionalities of the Simple Shell:

    Displays a prompt "#cisfun$ " and waits for user input.
    Runs all commands of type "executable program" (ls and /bin/ls).
    Runs the following build_in commands: exit, env, setenv and unsetenv.
    Handles commands with arguments.
    Handles the PATH global variable.
    Handles The EOF (End Of File) condition.
    Handles the Ctrl + C signal -> It doesn't exit the shell

Files description

    AUTHORS -> List of contributors to this repository
    man_1_simple_shell -> Manual page for the simple_shell
    shell.h -> Header file
    shell.c -> main function
        sig_handler -> handles the Ctrl + C signal
        _EOF -> handles the End Of File condition
    string.c
        _putchar -> prints a character
        _puts -> prints a string
        _strlen -> gives the length of a string
        _strdup -> copies a string in a newly allocated memory
        concat_all -> concatenates 3 strings in a newly allocated memory
    line_exec.c
        splitstring -> splits a string into an array of words
        execute -> executes a command using execve
        realloc -> reallocates a memory block
        freearv -> frees a 2 dimensional array
    linkpath.c
        _getenv -> returns the value of a global variable
        add_node_end -> adds a node in a singly linked list
        linkpath -> creates a singly linked list for PATH directories
        _which -> finds the pathname of a command
        free_list -> frees the linked list of PATH value
    checkbuild.c
        checkbuild -> checks if a command is a build-in command
    buildin.c
        exitt -> handles the exit buildin command
        _atoi -> converts a string into an integer
        env -> prints the current environment
        _setenv -> Initialize a new global variable, or modify an existing one
        _unsetenv -> remove a global variable

List of allowed functions and system calls for this project

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)
USAGE

You can try our shell by following these steps:

    Step 1: Clone our repository using this command, (you need to have git installed on your machine first)

git clone https://github.com/sentayehut/simple_shell


    Step 2: Change directory to simple_shell:

cd simple_shell

    Step 3: Compile the C files in this way:

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

    Step 4: Run the shell

./hsh

Exiting the shell When you want to exit the shell, you can use one of the following methods:

    1: Type the command "exit"

exit

    2: Press on Ctrl + D
     Tasks

    README, man, AUTHORS
>>>>>>> Readme file for sinple shell project

.Write a README

.Write a man for your shell.

.You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

.Repo:

<<<<<<< HEAD

=======
>>>>>>> Readme file for sinple shell project
.GitHub repository: simple_shell

.File: README.md, man_1_simple_shell, AUTHORS

<<<<<<< HEAD

   1. Betty would be proud
=======
    Betty would be proud
>>>>>>> Readme file for sinple shell project

Write a beautiful code that passes the Betty checks

Repo:

GitHub repository: simple_shell

<<<<<<< HEAD
2. Simple shell 0.1

Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

=======
    Simple shell 0.1

Write a UNIX command line interpreter.

Usage: simple_shell Your Shell should:
>>>>>>> Readme file for sinple shell project

.Display a prompt and wait for the user to type a command. A command line always ends with a new line.

.The prompt is displayed again each time a command has been executed.

.The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

.The command lines are made only of one word. No arguments will be passed to programs.

.If an executable cannot be found, print an error message and display the prompt again.

.Handle errors.
<<<<<<< HEAD

.You have to handle the “end of file” condition (Ctrl+D)
=======
>>>>>>> Readme file for sinple shell project
