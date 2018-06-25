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
    while ((c = fgetc(file)) != EOF){
        if (c == '\n')
            i ++;
    }
    fclose(file);
    return i;
}
    
void own_statistics(char *name)
{
    FILE *namef;
    char  string[20][40];
    scopy(name);
    printf("YOUR STATISTICS\n");
    
    namef = fopen(name,"r");
    
    for ( int i = 0; i <= counter(name); i++){
        fscanf(namef,"%s",string[i]); 
        fprintf(stdout,"%s\n",string[i]);
    }
    
   
}

void general_statistics()
{

    FILE *listf;
    FILE *namef;
    char c;
    printf("GENERAL STATISTICS\n");
    
    char *list_pointer;
    int i = 0;
    char list_string[] = {"ListPlayers.txt"};
    list_pointer = &list_string;
    i = counter(list_pointer);
    
    listf = fopen("ListPlayers.txt", "r");
    char list[i][19];
    char players[i][16];
    int num;


    for ( int j = 0; j < i; j++){
        fscanf(listf,"%d%c%s",&num,&c,list[j]); 
        strcpy(players[j],list[j]);
    }
    
    //добавление  к имени игрока ".txt"
    for ( int j = 0; j < i; j++){
       scopy(list[j]);
    }
    
    for(int g = 0; g < i; g ++){// открытие файла типа NAME.txt
        char *name_pointer;
        name_pointer = &list[g]; 
        namef = fopen(name_pointer,"r"); 
        char name[counter(name_pointer)][32];
        
        fprintf(stdout,"%s|",players[g]);
        
        for( int p =0; p <= counter(name_pointer); p++){
            fscanf(namef,"%s",name[p]);
            if (p == (counter(name_pointer)) - 1) //Вывод последней строки на экран
            fprintf(stdout,"%s\n",name[p]);
        }
        
        fclose(namef);
    }

    
    
    fclose(listf);
}
