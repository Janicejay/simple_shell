#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define MAX_WORDS 100
#define BUFFER_SIZE 1024

extern char **environ;

/* supporting functions*/
int putchar_stdout(char c);
int putchar_stderr(char c);
void print_number_stderr(int number);
int _strlen(const char *format);
char *str_cat(char *dest, char *src);
int _strncmp(char *s1, char *s2, size_t n);
int str_cmp(char *s1, char *s2);
char *str_cpy(char *dest, char *src);
void print_stderr(const char *str);
void print_stdout(const char *str);
char *_strdup(char *str);
char *concatenatePath(char *filename);
int str_chr(char *str, int character);
char **split_command(char *command);
int atoi_custom(char *str);
void error_msg(char *argv[], int linecount, char *str, char *message, char *command);


/* Main functions */
char *get_input(int input_fd);
char **split_input(char *input);
int execute_command(char **args, int interactive, char *argv[], int linecount);

/* Builtin commands */
int builtin_commands(char *args, char *argv[], int linecount);
void exit_builtin(char *args, char **command, char *argv[], int linecount);
void get_env(void);
void cd_builtin(char *argv[], int linecount, char **command);

/* custom getline function */
ssize_t custom_getline(char **line_ptr, size_t *n, int fd);
char *strtok_custom(char *str, char *delimeter);

/* supporting functions for getline */
int initialize_buffer(char **line_ptr, size_t *n);
ssize_t fill_buffer(int fd);
ssize_t reallocate_buffer(char **line_ptr, size_t *n);

/* memory */
void *shell_realloc(void *ptr, size_t size);
char *shell_memcpy(char *dest, char *src, unsigned int n);
void free_mem(char **args);

/* */
void compute_input(int interactive, int input_fd, int argc, char *argv[], int linecount);
#endif /* MAIN_H */
