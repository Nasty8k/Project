#ifndef  LISTPLAYERS_H
#define  LISTPLAYERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_global.h"
#define RUS "#\\ АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя"

int schr(const char * str, const char ch);
int check_individual(char new_name[]);
int check_in_name(char new_name[], int all);
int check_list(int num);
void show_ListPlayers(void);
int check_in(void);
#endif
