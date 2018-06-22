#ifndef  LISTPLAYERS_H
#define  LISTPLAYERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RUS "#\\ АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя"

struct User{
    int number;    
    char name[15];
    int points;
    int level;
    float accur;
} player;

int schr(const char * str, const char ch);
int check_individual(char new_name[]);
int check_in_name(char new_name[], int all);
int check_list(int num);
#endif
