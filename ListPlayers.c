#include <stdio.h>
#include <string.h>

int main()
{
    char Player[15];
    int i;
    FILE *file = fopen("ListPlayers.txt", "a+");

    if (file!=NULL)
        printf("Successfully it was possible to open a file for reading and additions\n");
    else printf("Couldn't open file");

    printf("Please, enter a name: \n");
    scanf("%s", Player);

     for(i=0; i<15; i++) {
        if ((Player[i]=='#') || (Player[i]=='/'))
        printf ("The name can`t contain # and /!\n");
    }

    fprintf(file, "%s", Player );
    fclose(file);
}
