#include <stdio.h>
#include <string.h>

int main()
{
    char Player[15]; 
    int i;
    FILE *file = fopen("ListPlayers.txt", "a+");

    if (file!=NULL)
        printf("Удалось открыть файл для чтения и дополнения\n");
    else printf("Не удалось открыть файл");

    printf("Please, enter a name: \n");
    scanf("%s", Player);

    for(i=0; i<15; i++) {
        if ((Player[i]=='#') || (Player[i]=='/'))
        printf ("Имя не должно содержать знаков # и /!\n");
    }

    fprintf(file, "%s", Player );
    fclose(file);
}