#ifndef  GAME_H
#define  GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED   "\033[1;31m"
#define CYAN  "\033[1;36m"
#define YELOW "\033[1;33m"
#define WHITE "\033[37m"
#define BLACK "\033[0;30m" 


char * settime(struct tm *u);
void opening(void);


#endif

