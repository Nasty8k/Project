#ifndef _TRAIN_
#define _TRAIN_

#include <stdlib.h>
#include <string.h>

struct progress{
	int wrong_s;
	int right_s;
	float accur;
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
