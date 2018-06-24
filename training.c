#include <stdio.h>
#include "training.h"

#define N 1000000

int check;

void compare_string(char *s1,char *s2, struct progress *prog){ // сравнивает данную и введенную строку
	
	
	for (int len = 0; len < (strlen(s1)); len++){
		if (s1[len] == s2[len]){
			if(s1[len] != ' '){
				prog-> right_s = prog-> right_s +1;
				if (s1[len] != '-'){
		            prog->points = prog-> points +1;
			    }else prog->points = prog-> points +2;
			}
		}else {
			prog-> wrong_s = prog-> wrong_s +1;
			prog->points = prog-> points -1;
		}
	}
	if(strlen(s1) < strlen(s2))
		prog-> wrong_s = prog-> wrong_s + strlen(s2) - strlen(s1);
		
	fprintf(stdout,"Right symbols: %d\t Wrong symbols: %d\n", prog-> right_s,prog-> wrong_s );
}	

int write_string(char *string, struct progress *prog){
	
	char s2[N];
	check = 0;
	printf("Начинайте ввод\n");
	printf("Если хотите выйти нажмите # + Enter\n ");
	printf("\n");
    fprintf(stdout, "%s\n", string);
	
	//int i = 0;
	
	fgets(s2, N, stdin);

	if(strchr(s2, '#'))
			return -1;

	
	/*do{
	    scanf("%c",&s2[i]);	
	    if (s2[i] == '#')
           return -1;
	   
		i++;
	    }while(s2[i-1] != '\n');
	    s2[i-1] = '\0';*/
	   
    compare_string(string,s2, prog);
    
    return 0;
}

int training(int n_string, struct User *player)
{
	getc(stdin);// чистит входной поток от '\n'
	system("clear");
	
	int level;
	FILE *file;
	char string1[n_string][69], s[69];
	struct progress *p_prog;
	p_prog = (struct progress*)malloc(sizeof(struct progress));
	p_prog -> wrong_s = -1;
	p_prog -> right_s= 0;
	p_prog -> points = 0;
	
	
	
	file = fopen("GAME.txt", "r");
	level = (player -> level)-1;
	
	for (int i = 0; i < (level + n_string); i++){
		if (i == level)
		   for (int g = 0; g < n_string; g ++){
			   fgets(string1[g], 69, file);
			   check = write_string(string1[g], p_prog);
				if (check == -1)
					return 0;
		   }
		fgets(s, 69, file);
		}
	
	
    fclose(file);
    printf("Отлично\n");
	player -> level = level + n_string + 1;
	printf("Your level is %d\n", player -> level);
	player -> points = player-> points + p_prog -> points;
	printf("Your points  is %d\n", player -> points);
    player -> accur = MAX / player -> points;
    printf("Your accur is %f\n", player -> accur);
	
	free(p_prog);
	
    return 0;	
}
