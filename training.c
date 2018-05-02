#include <stdio.h>
#include "training.h"

int check;
int compare_string(char *string, struct progress *prog){
	
	char s2[69];
	check = 0;
	int len;
	len = strlen(string);
	fprintf(stdout, "%s\n", string);
	
	printf("Начинайте ввод\n");
	
	int i =0;
	do{
		scanf("%c",&s2[i]);	
		if (s2[i] == '#')
			return -1;
		i++;
	}while(s2[i-1] != '\n');
	s2[i-1] = '\0';

    
  //  fprintf(stdout, "%s\n", string);
    
    
    
    return 0;
}

int training(int n_string, struct User *player)
{
	
	int level;
	FILE *file;
	char string1[n_string][69], s[69];
	struct progress prog;
	struct progress *p_prog;
	
	file = fopen("test.txt", "r");
	level = (player -> level)-1;
	
	for (int i = 0; i < (level + n_string); i++){
		fgets(s, 69, file);
		if (i == level)
		   for (int g = 0; g < n_string; g ++){
			   fgets(string1[g], 69, file);
			   //fprintf(stdout, "%s\n", string1[g]);
		   }
		}
	
	for (int i = 0; i < n_string; i++){
		    check = compare_string(string1[i], p_prog);
		    if (check == -1)
		    	return -1;
    }
    
			
	
return 0;	
	
	

	
}
