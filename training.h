#ifndef _TRAIN_
#define _TRAIN_

#include <stdlib.h>
#include <string.h>

struct User{

    int number;    
    char name[15];
    int points;
    int level;
    float accur;
};

int training( int n_string, struct User *player);

#endif
