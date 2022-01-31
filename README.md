# Simple Shell Group Project for Alx school

            
 Description:
            A simple UNIX command interpreter is a program that reads commands from the standard input or files and executes them in order to display a result.

            * Read or watch:
            * Unix shell

            * Thompson shell

             * Ken Thompson


            * Everything you need to know to start coding your own shell concept 

    
     Who wrote the first version of the UNIX shell

     Who invented the B programming language (the direct predecessor to the C programming language)

     Who is Ken Thompson

     How does a shell work

     What is a pid and a ppid

     How to manipulate the environment of the current process

     What is the difference between a function and a system call

     How to create processes

     What are the three prototypes of main

     ow does the shell use the PATH to find the programs

     How to execute another program with the execve system call

     How to suspend the execution of a process until one of its children terminates

     What is EOF / “end-of-file”?



### Requirements

### General

           Allowed editors: vi, vim, emacs

           All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std
		   =gnu89

          All your files should end with a new line

         A README.md file, at the root of the folder of the project is mandatory

          Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

         Your shell should not have any memory leaks

           No more than 5 functions per file

           All your header files should be include guarded

           Use system calls only when you need to (why?)

### Example of error with sh:

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

         ### List of allowed functions and system calls


              * access (man 2 access)

              * chdir (man 2 chdir)

              *  close (man 2 close)

              * closedir (man 3 closedir)

              * execve (man 2 execve)

              * exit (man 3 exit)

              *  _exit (man 2 _exit)

               * fflush (man 3 fflush)

               * fork (man 2 fork)

               * free (man 3 free)

               * getcwd (man 3 getcwd)

               *  getline (man 3 getline)

               * getpid (man 2 getpid)

               * isatty (man 3 isatty)

               * kill (man 2 kill)

               * malloc (man 3 malloc)

               *  open (man 2 open)

               * opendir (man 3 opendir)

               *  perror (man 3 perror)

               * read (man 2 read)

               * readdir (man 3 readdir)

               * signal (man 2 signal)

               * stat (__xstat) (man 2 stat)

               * lstat (__lxstat) (man 2 lstat)

               * fstat (__fxstat) (man 2 fstat)

               * strtok (man 3 strtok)

               * wait (man 2 wait)

               * waitpid (man 2 waitpid)

               * wait3 (man 2 wait3)

               * wait4 (man 2 wait4)

               * write (man 2 write)


   ##### Compilation #####
   ##### Our shell will be compiled this way:#####

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


              hsh main.c shell.c test_ls_2


              $ cat test_ls_2

              /bin/ls

              /bin/ls

             $

             $ cat test_ls_2 | ./hsh

             hsh main.c shell.c test_ls_2

             hsh main.c shell.c test_ls_2

             $

      ### Tasks
          ~~~~
            0. README, man, AUTHORS

            1. Write a README

            2.Write a man for your shell.
   
           3.You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. 
		   Format, see Docker
           ~~~~
         .GitHub repository: https://github.com/sentayehut/simple_shell

         .File: README.md, man_1_simple_shell, AUTHORS

                     1. Betty would be proud

                            Write a beautiful code that passes the Betty checks


                           GitHub repository: https://github.com/sentayehut/simple_shell

                     2. Simple shell 0.1

                      Write a UNIX command line interpreter.

                         : simple_shell
              ### Your Shell should:


              .Display a prompt and wait for the user to type a command. A command line always ends with a new line.

              .The prompt is displayed again each time a command has been executed.

              .The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.

               .The command lines are made only of one word. No arguments will be passed to programs.

               .If an executable cannot be found, print an error message and display the prompt again.

               .Handle errors.

            ### .You have to handle the “end of file” condition (Ctrl+D)
