#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"


void own_statistics(FILE *name)
{
     char  string[20][40];
     char c;
     printf("YOUR STATISTICS\n");
     
    for ( int i = 0; i < 20; i++){
        fscanf(name,"%s",string[i]); 
        if ((c = fgetc(name)) != EOF){
        fprintf(stdout,"%s\n",string[i]);
        }
    }
    
   
}

void general_statistics()
{

    FILE *listf;
    //FILE *name;
    char c;
    printf("GENERAL STATISTICS\n");
    
     
    listf = fopen("test.txt", "r");
    int i = 0;
    while ((c = fgetc(listf)) != EOF){
        if (c == '\n')
            i ++;
    }
    fprintf(stdout,"%d\n",i);
    fclose(listf);
    
    listf = fopen("test.txt", "r");
    char list[i][18];
    int num;

    for ( int j = 0; j < i; j++){
        fscanf(listf,"%d%c%s",&num,&c,list[j]); 
        if ((c = fgetc(listf)) != EOF){
        fprintf(stdout,"%s\n",list[j]);
        }
    }
    

    fclose(listf);
}
