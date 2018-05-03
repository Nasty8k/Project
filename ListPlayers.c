/*
 Нужна проверка и дороботка.
 1) Существует ли имя в списке
 2) Создание файла <NAME>.txt игрока в data/Users
 3) Варианты выхода с успехом (1) или ошибкой (-1) 
*/
#include "ListPlayers.h"
int main() {
    
    struct User * player = &PLAYER;
    choice_name(player);
    return 0;
}

int choice_name(struct User * player)
{
    FILE *origin = fopen("data/Game/ListPlayers.txt", "r");
   
    char *t, tmp_file[20] = {0}, gamers[10][15] = {0};
    int input, i = 1, number = 0;
    t = malloc(15 * sizeof(char));
    while (fscanf(origin, "%d. %s\n", &number, gamers[i++]) != EOF) {
        fprintf(stdout,"%d. %s\n", number, gamers[number]); 
    }
    fprintf(stdout,"%d. SET NEW\n", ++number); 
    printf("Enter your number:  ");
    scanf("%d", &input);
    if (input == number) {
        printf("Pease, input your name (len < 14; without # and / )\n");
        scanf("%15s", t);
        if(strlen(t) == 0) printf("ERRRO\n");
        printf(" tmp strlen %ld -%s-\n", strlen(t), t);
        
        printf("In new gamers -%s-\n", gamers[number]);
    } else {
        strcpy(tmp_file, gamers[input]);
        printf("In tmp -%s-\n", tmp_file);
    }
        
    fclose(origin);
    
    return 0;
}

