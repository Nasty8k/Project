#include <stdio.h>
#include "training.h"

int check;
void compare_string(char *s1,char *s2, struct progress *prog){
	

	
	for (int len = 0; len < (strlen(s1)); len++){
		if (s1[len] == s2[len]){
			if(s1[len] != ' '){
		        prog->points = prog-> points +1;
		        prog-> right_s = prog-> right_s +1;
		    }
		}else prog-> wrong_s = prog-> wrong_s +1;
	}
	
	fprintf(stdout,"%d\t%d\t%d\n",prog-> points, prog-> right_s, prog-> wrong_s );
	
	
	
}	
int write_string(char *string, struct progress *prog){
	
	char s2[69];
	check = 0;
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

    compare_string(string,s2, prog);
  //  fprintf(stdout, "%s\n", string);
    
    
    
    return 0;
}

int training(int n_string, struct User *player)
{
	
	int level;
	FILE *file;
	char string1[n_string][69], s[69];
	struct progress prog;
	prog.wrong_s = -1;
	prog.right_s= 0;
	prog.accur = 0;
	prog.points = 0;
	struct progress *p_prog;
	p_prog =&prog;
	
	file = fopen("test.txt", "r");
	level = (player -> level)-1;
	
	for (int i = 0; i < (level + n_string); i++){
		fgets(s, 69, file);
		if (i == level)
		   for (int g = 0; g < n_string; g ++){
			   fgets(string1[g], 69, file);
		   }
		}
	
	for (int i = 0; i < n_string; i++){
		    check = write_string(string1[i], p_prog);
		    if (check == -1)
		    	return -1;
    }
    
			
	
return 0;	
	
	

	
}
