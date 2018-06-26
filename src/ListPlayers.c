#include "ListPlayers.h"
#include "game_opening.h"
int check_in(void)
{
    show_ListPlayers();
    char s[16] = {0};
    char *p = s, c;
    int i = 0, in = 0, f = 1;

    printf("Enter Your %snum%s or %sNew name%s: ", RED, RESET, RED, RESET);
    while ((c = getc(stdin)) != '\n') {   
        if (i < 15) {
            s[i] = c;
            (c >= '0' && c <= '9') ? (f *= f) : (f = 0);
        }
        i++;
    }
    
    in = atoi(p);
    (in * f == 0) ? (in = check_in_name(p, i)) : (in = check_list(in));
    if (in != 0) return User_data();
    return in;
}

int User_data(void)
{
    char profile[30] = "data/Users/";
    char data[50] = {0}, tmp[10] = {0};
    char *d = data, *t = tmp;
    strcat(profile, player.name);
    strcat(profile, ".txt\0");
    FILE *f = fopen(profile, "r");
    FILE *tmpf = fopen("data/tmpf.txt", "w");
    if (f == NULL) return 0;   

    while (!feof(f)) fgets(d, 49, f);
    fputs(d + schr(d, '|'), tmpf);
    freopen("data/tmpf.txt", "r", tmpf);
    fscanf(tmpf, "|%d|%d|%f|%s\n", &player.points, &player.level, &player.accur, t);
    fclose(f);
    fclose(tmpf);
    system("rm data/tmpf.txt");
    return 1;
}

int schr(const char * str, const char ch)
{
    int i, idx = -1;
    for(i = 0; (str[i] != '\0') && (str[i] != ch); i++);
    if (str[i] == ch) idx = i;
    return idx;
}

int check_individual(char new_name[]) /* ok ? 1 : 0;*/
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
    printf("Hello, %s! You are registered\n", new_name);
    freopen("data/Game/ListPlayers.txt", "a+", l);
    fprintf(l, "%d.%s\n", player.number, player.name);
    strcat(profile, player.name);
    strcat(profile, ".txt\0");
    freopen(profile, "w", l);
    fprintf(l, "%s|%d|%d|%d|%s\n", day, 0, 1, 0, "DW");
    fclose(l);
    return 1;
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
            printf("Only ABC. Don't use space or \\ and #\n");
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

void show_ListPlayers(void)
{
    FILE *l = fopen("data/Game/ListPlayers.txt", "r");
    int n;
    char str[16];
    if (l != NULL) {
        while (!feof(l)) {
            fscanf(l, "%d.%s\n", &n, str);
            fprintf(stdout, "%s%d%s -> %s\n", GREEN, n, RESET, str);
        }
    } else printf("Error of openning List\n");
}
