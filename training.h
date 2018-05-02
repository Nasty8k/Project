#ifndef _TRAIN_
#define _TRAIN_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100
struct progress{
	int wrong_s;
	int right_s;
	int points;
};

struct User{

    int number;    
    char name[15];
    int points;
    int level;
    float accur;
};

int training( int n_string, struct User *player);

#endif
