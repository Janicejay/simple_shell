# SIMPLE SHELL (CREATE YOUR OWN SHELL)

## ABOUT

`Shell` refers to a command-line interface (CLI) or program that provides a user the ability to interact with a computer's operating system and execute various commands.
In this simple `shell` project we are going to be looking at how the interaction process works. However, there will be some limitations with this shell as it will not be as complex as the original.

## OBJECTIVES

- How does a shell work?
- Create a custom `simple shell` that functions exactly as the original.
- What is a `pid` and a `ppid`?
- How to manipulate the environment of the current process
- Difference between a function and a system call
- How to create processes
- Know the three prototypes of `main`
- How the shell uses `PATH` to find programs.
- How to execute another program with the `execve` system call
- How to suspend the execution of a process until one of its children terminates
- What is `EOF` / “end-of-file”?

## List of allowed functions and system calls

- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)

## Testing
To test the functionality of this custom shell, follow the steps below:
1. Clone this repository

2. Compile it using `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

3. Run it using `./hsh`

## CONTRIBUTIONS
This `simple shell` project was done in teams of 2 people, the contributors are:
- [Faith Istifanus](https://github.com/Janicejay): janicejay5@gmail.com
- [Oluwatamilore Olugbesan](https://github.com/Tamilore-0): findtamilore@gmail.com

Unfortunately we won't be accepting pull requests on this repository, for the sole reason of it being a school project, but suggestions on how to improve the functionality of our shell will be welcomed and highly appreciated, kindly reach out to either of us on our `respective emails` anytime, Thank You.
