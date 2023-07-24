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
typedef struct cmd_tab {
	char *cmd;
	int (*find_cmd)(char **);
} cmd;


/*function prototypes*/
char *get_line(void);
char **tokenizer(char *);
int executor(char **);
int process(char **);
int rune_cd(char **);
int run_ls(char **);
int run_pwd(char **);
int run_exit(char **);
#endif
