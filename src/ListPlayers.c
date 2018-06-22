/*
 Нужна проверка и дороботка.

 Создание файла <NAME>.txt игрока в data/Users
 Построение выбора меню
 
*/
#include "include/ListPlayers.h"

int main(){
    char s[16] = {0};
    char *p = s, c;
    int i = 0, in = 0, f = 1;

    printf("Enter Your num or New name: ");
    while((c = getc(stdin))!='\n')
    {   
        if (i < 15) {
            s[i] = c;
            (c >= '0' && c <= '9') ? (f *=f) : (f = 0);
        }
        i++;
    }
    
    in = atoi(p);
    (in * f == 0) ? (in = check_in_name(p, i)) : (in = check_list(in));
    printf("IN = %d\n", in);
    
    printf("Your choose: ");
    scanf("%s", p);
    printf("--> [%s]", p);
    return 0;
}

int schr(const char * str, const char ch)
{
    int i, idx = -1;
    for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
    if (str[i] == ch) idx = i;
    return idx;
}

int check_individual(char new_name[]) /* ok ? new_num : 0;*/
{
    char str[16];
    char profile[30] = "data/Users/";
    int n = -1;
    FILE *l = fopen("data/Game/ListPlayers.txt", "r");
    if (l != NULL) {
        while (!feof(l)) {
            fscanf(l, "%d.%s\n", &n, str);
            if (strcmp(new_name, str) == 0) {
                printf("Sorry. Think of another nicknamen\n");
                return 0;     
            }
        }
        player.number = n + 1;
        strcpy( player.name, new_name);
    } else printf("Error of openning List\n");
    printf("NEW, [%d %s]\n", player.number, player.name);
    printf("Hello, %s! You are registered\n", new_name);
    freopen("data/Game/ListPlayers.txt", "a+", l);
    fprintf(l, "%d.%s\n", player.number, player.name);
    strcat(profile, player.name);
    strcat(profile, ".txt\0");
    printf("PROF[%s]\n", profile);
    freopen(profile, "w", l);
    fclose(l);
    return player.number;
}

int check_in_name(char new_name[], int all)
{
    int len = strlen(new_name);
    if ((all >= 15) || (all == 0)) {
        printf("The lenght of name from 1 to 15\n");
        return 0;
    }
    if ((new_name[0] >= '0') && (new_name[0] <= '9')) {
        printf("the first letter must be a symbol\n");
        return 0;
    }
    for(int i = 0; i < len; i++)
        if (schr(RUS, new_name[i]) >= 0) {
            printf("Only ABC. Do not use space or <\\> and <#>\n");
            return 0;
        }
    return check_individual(new_name);
}

int check_list(int num) /* ok ? num : 0;*/
{
    char str[16];
    int n = -1;
    FILE *l = fopen("data/Game/ListPlayers.txt", "r");
    if (l != NULL) {
        while (!feof(l)) {
            fscanf(l, "%d.%s\n", &n, str);
            if (num == n) {
                player.number = n;
                strcpy( player.name, str);
                break;
            }
        }
    } else printf("Error of openning List\n");
    fclose(l);
    (player.number == 0) ? (printf("Not found\n")) : (printf("Welcome back, %s\n", str));
    return player.number;
}

