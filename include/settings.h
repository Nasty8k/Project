#ifndef  SET_H
#define  SET_H

#include <stdio.h>
#include <stdlib.h>

struct SET {
        int timer;
        int strings;
};

int settings_inital(FILE * Fset, struct SET * Pset);
int settings_user(FILE * Fset, struct SET * Pset);

#endif
