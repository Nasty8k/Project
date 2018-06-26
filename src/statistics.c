#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"

void scopy(char *s1)//добавляет в ".txt"
{
    char s2[] = ".txt";
    strcat(s1,s2);
}

int counter(char *file_name)// считает '\n'
{
    FILE *file;
    int i = 0;
    char c;
    file = fopen(file_name, "r");
    if (file == NULL) {
	    printf("Can't open file");
	    return -1;
	}
    while ((c = fgetc(file)) != EOF){
        if (c == '\n') i++;
    }
    fclose(file);
    return i;
}
    
void own_statistics(char *name)
{
    char file_name[17] = {"data/Users/"};
    char string[50] = {0};
    char *str = string;
    strcat(file_name, name);
    strcat(file_name,".txt");
    FILE *namef = fopen(file_name, "r");
    if (namef == NULL) {
        printf("Sorry, we can't show your statistics. Registered or check in\n ");
        return ;
    }
    printf("YOUR STATISTICS\n");   
    for ( int i = 0; i <= counter(file_name)- 1; i++){
        fgets(str, 49, namef);
        fprintf(stdout, "%s", str);
    } 
}

void general_statistics(void)
{
    FILE *listf;
    FILE *namef;
    char c;
    printf("GENERAL STATISTICS\n");
    
   
    int i = 0;
    char list_string[] = {"data/Game/ListPlayers.txt"};
    i = counter(list_string);
    
    listf = fopen("data/Game/ListPlayers.txt", "r");
     if (listf == NULL) {
	    printf("ERROR");
		return;
	}
    
    char dir[] = {"data/Users/"};
    char list[i][100];
    char players[i][100];
    int num;
	

    for (int j = 0; j < i; j++){
        fscanf(listf,"%d%c%s", &num, &c, players[j]);
        strcpy(list[j],dir);
        strcat(list[j],players[j]);   
    }
    
    //добавление  к имени игрока ".txt"
    for ( int j = 0; j < i; j++){
       scopy(list[j]);
    }
    
    for (int g = 0; g < i; g ++){// открытие файла типа NAME.txt
        namef = fopen(list[g], "r"); 
        char name[100];
        
        fprintf(stdout,"%s|", players[g]);
        
        for (int p =0; p < counter(list[g]); p++)
			fgets(name, 100, namef);
            fprintf(stdout, "%s", name);
            fclose(namef);
        }   
    fclose(listf);
    
}
