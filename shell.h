#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*### Main program Shell file ###*/
int main(int argc, char **argv, char **envp);

/*### functions to Initialize shell ###*/
void prompt_handler(void);
void handle_signal(int signals);
void handle_eof(char *buffer);
void handle_exit(char **input_command);


/*### functions to child process Creation ###*/
void execute_child(char **command, char *shell_name, char **envp, int loops);
int dir_changes(const char *dir);


/*### functions to execute command ###*/
void execute_command(char **command, char *name, char **env, int cicles);
void print_env(char **env);
char **_dirsPATH(char **env);
void command_error(char *name, int loops, char **command);


/*### functions to tokenize input ###*/
char **tokenize(char *buffer, const char *delim);


/*### functions to free memory ###*/
void free_memory(char **command);
void freeMem_and_exit(char **command);


/*### Auxiliary functions ###*/
int _strcmp(char *str1, char *str2);
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
int _strint(char *s);
char *_strcat(char *dest, char *src);

#endif /*### _SHELL_H_ ###*/
