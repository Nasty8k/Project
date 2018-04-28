#ifndef  SET_H
#define  SET_H

#include <stdio.h>
#include <stdlib.h>

struct SET {
        int timer;
        int strings;
};

int settings_inital(struct SET * Pset);
int settings_user(struct SET * Pset);

#endif
