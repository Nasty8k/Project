#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct User{
    int number;    
    char name[15];
    int points;
    int level;
    float accur;
} PLAYER;

int choice_name(struct User * player );
