#ifndef _TRAIN_
#define _TRAIN_
#define N 1000
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct progress {
	float wrong_s;
	float right_s;
	int points;
} prog;

int training(void);
int write_string(char *string, struct progress *prog);
void compare_string(char *s1, char *s2, struct progress *prog);
void write_data(void);
#endif
