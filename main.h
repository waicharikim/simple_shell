#ifndef MAIN_H
#define MAIN_H

/*header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

/*structures*/
/**
 * struct cmd_tab - structure holding command name and respective function
 * @cmd: command name
 * @find_cmd: pointer to a function
 */
typedef struct cmd_tab
{
	char *cmd;
	int (*find_cmd)(char **);
} cmd;

/**
 * struct a_tab - alias table
 * @a_name: name of alias
 * @cmd_name: command name
 */
typedef struct a_tab
{
	char *a_name;
	char *cmd_name;
} alias;

/*function prototypes*/
char *get_line(void);
char **tokenizer(char *);
int isbuiltin(char **);
char *ispath(char *);
char *isalias(char *);
int exec_utor(char **);
int run_cd(char **);
int run_ls(char **);
int run_pwd(char **);
int run_exit(char **);
int run_help(char **);
#endif
