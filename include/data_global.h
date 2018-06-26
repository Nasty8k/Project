#ifndef  DATA_H
#define  DATA_H

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define RED   "\033[1;31m"
#define CYAN  "\033[1;36m"
#define YELOW "\033[1;33m"
#define WHITE "\033[37m"
#define BLACK "\033[0;30m" 

struct User{
    int number;    
    char name[15];
    int points;
    int level;
    float accur;
} player;

char *day;
int timer, n_strings;
int menu(char vvod);

#endif
