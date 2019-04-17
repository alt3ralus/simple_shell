## Simple SHELL
This project is about building a shell with the basic functions.

### Requirements
You need a SO unix like (Linux). This program was make it on Ubuntu 14.05.5 LTS

 ### Testing
* You can test with interactive mode:
```
$ ./hsh
($) / bin / ls
hsh main.c shell.c
($)
($) exit
$
```
* But also in non-interactive mode:
```
$ echo "/ bin / ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/ bin / ls
/ bin / ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Who designed and implemented the original Unix operating system
BELL lab: Ken Thompson feat. Dennis Ritchie, Douglas Mcllroy, (...).

### Who wrote the first version of the UNIX shell
Ken Thomson, who wrote the Thompson shell.

### Who invented the B programming language (the direct predecessor to the C programming language)
Ken Thompson and Dennis Ritchie at Bell lab.

### Who is Ken Thompson
Pioneer of computing. Writes B language, precursor to Dennis Ritchie's C language.
He has worked at Google since 2006 and he's Co Inventor of the Go language.

### How does a shell work
The shell is the interface to communicate with the kernel.
The shell receives commands written in commands.
The system that is used to enter the instructions is the standard input (what is written in the keyboard),
and to visualize uses the standard output (what appears on the screen).
