#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics.h"


void own_statistics(FILE *name)
{
     char  string[20][40];
     
     printf("YOUR STATISTICS\n");
     
     //while(fscanf(name,"%s",string)  != EOF){
     for ( int i = 0; i < 20; i++){
         fscanf(name,"%s",string[i]);
         if (strlen(string[i]) > 21)
             fprintf(stdout,"%s\n",string[i]);
    }
}

void general_statistics()
{

     char string1[15];
     char string2[15];
     
     while(fscanf(name, %s,string1)  != EOF){
         fscanf(name,%s, string1);
         if (string1 != EOF){
                 string2 = string1;
         }
}
