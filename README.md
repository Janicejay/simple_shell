# SIMPLE SHELL

## Description

`Shell` refers to a command-line interface (CLI) or program that provides a user the ability to interact with a computer's operating system and execute various commands.
	The `Simple Shell` project is designed to function like a typical shell, with some limitations compared to more complex shells. It supports common shell commands, both in interactive and non-interactive modes.

***Built with: Implemented in C language, with adherence to POSIX standards.***

## Concepts to Understand:
> To effectively contribute to or utilize this project, it's helpful to have knowledge of the following concepts:

1. Basic shell scripting and commands
2. Command-line interfaces (CLI)
3. Process management and execution
4. POSIX standards and system calls

### Usage

- Arguments are separated by whitespace (no quoting or backslash escaping).
- Supports most commands found in `/bin/`.
	- Builtin commands are limited to: `env`, `cd` and `exit`.
- No redirection, piping, or globbing.
- Handles ; as a command separator.
- Can read and execute commands from files (work in progress).

### List of allowed functions and system calls in the project
> Every other required function or system call must be custom-made.
> NOTE: `man` is a built-in manual for using Linux commands.

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

### AUTHORS
This `Simple Shell` project was developed by a team of two contributors:
- [Faith Istifanus](https://github.com/Janicejay)
- [Oluwatamilore Olugbesan](https://github.com/Tamilore-0)

_Unfortunately we won't be accepting pull requests on this repository, for the sole reason of it being a school project under [ALX Africa](https://www.alxafrica.com/), but suggestions on how to improve the functionality of our shell will be welcomed and highly appreciated, kindly reach out to either of us on our `respective emails` anytime, Thank You._

### Contact Information
Feel free to reach out to us with any suggestions or questions:

- **Faith Istifanus:** Contact: janicejay5@gmail.com
- **Oluwatamilore Olugbesan:** Contact: findtamilore@gmail.com
##
This section should give potential contributors or users a better understanding of the knowledge required to work with your ***Simple Shell*** project. Feel free to modify or expand this section to fit your project's specific requirements.

