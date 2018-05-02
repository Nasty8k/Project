#include <stdio.h>
#include "training.h"

int check;
int exit_print()
{
    char s;
    printf("Уверены что хотите выйти?\n"
            " YES(y) or NO(n)\n");	
	scanf("%c", &s);
	printf("%c\n",s);
	
	if( s == 'y')
	   return 2;
	 
	 return 0;
}
	

void compare_string(char *s1,char *s2, struct progress *prog){ // сравнивает данную и введенную строку
	
	
	for (int len = 0; len < (strlen(s1)); len++){
		if (s1[len] == s2[len]){
			if(s1[len] != ' '){
				prog-> right_s = prog-> right_s +1;
				if (s1[len] != '-'){
		            prog->points = prog-> points +1;
			    }else prog->points = prog-> points +2;
			}
		}else prog-> wrong_s = prog-> wrong_s +1;
	}
		
	fprintf(stdout,"%d\t%d\t%d\n",prog-> points, prog-> right_s,prog-> wrong_s );
}	

int write_string(char *string, struct progress *prog){
	
	char s2[69];
	check = 0;
	printf("Начинайте ввод\n");
	printf("Если хотите выйти нажмите # + Enter\n ");
	printf("\n");
	fprintf(stdout, "%s\n", string);
	
	int i =0;
	do{
	    scanf("%c",&s2[i]);	
	    if (s2[i] == '#')
           return -1;
	   
		i++;
	    }while(s2[i-1] != '\n');
	    s2[i-1] = '\0';
	   
    compare_string(string,s2, prog);
    
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
	prog.points = 0;
	struct progress *p_prog;
	p_prog =&prog;
	
	file = fopen("GAME.txt", "r");
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
    fclose(file);
    printf("Отлично\n");
	player -> level = level + n_string + 1;
	player -> points = player-> points + prog.points;
    player -> accur = MAX / player -> points;
	
	
    return 0;	
}
