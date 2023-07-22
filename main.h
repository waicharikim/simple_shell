#ifndef MAIN_H
#define MAIN_H

/*header files*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>

/*function prototypes*/
char *get_line(void);
char **tokenizer(char *);
#endif
