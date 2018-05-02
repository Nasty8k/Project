#include <stdio.h>
#include "training.h"


int training(int n_string, struct User *player)
{
	
	int points, level, fall, right;
	float accur;
	FILE *file;
	char symbol;
	char string1[n_string][69], string2[69], s[69];
	
	file = fopen("test.txt", "r");
	points = player -> points;
	level = (player -> level)-1;
	
	for (int i = 0; i < (level+ n_string); i++){
		fgets(s, 69, file);
		if (i == level)
		
		   for (int g = 0; g < n_string; g ++){
			   fgets(string1[g], 69, file);
			   fprintf(stdout, "%s\n", string1[g]);
		   }
		}

			
	
return 0;	
	
	

	
}
