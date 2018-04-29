#include <stdio.h>
#include <stdlib.h>
#include "statistics.h"


void own_statistics(FILE *name)
{
     char string[50];
     
     printf("YOUR STATISTICS\n");
     
     while(fscanf(name,"%s",string)  != '\n'){
         fscanf(name,"%s",string);
         printf("%s\n", string);
    }
}

/*void general_statistics()
{

     char string1[15];
     char string2[15];
     
     while(fscanf(name, %s,string1)  != EOF){
         fscanf(name,%s, string1);
         if (string1 != EOF){
                 string2 = string1;
         }
}*/
