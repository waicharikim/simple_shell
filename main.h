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
char *ispath(char *, char **);
char *isalias(char *);
int exec_utor(char **, char **, char *, int);
char *get_path(char **env);

/*custom made fuctions*/
int str_len(char *);
int str_ncmp(char *, char *, int);
char *str_cat(char *, char *);
int str_cmp(char *, char *);
char *str_cpy(char *, char *);
char *str_dup(char *);
void free_argv(char **);

/* commands prototypes */
int run_cd(char **);
int run_ls(char **);
int run_pwd(char **);
int run_exit(char **, char *);
int run_help(char **);
#endif
