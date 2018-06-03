#include "settings.h"
#include "data_global.h"

void settings_inital(void)
{
    int tmp = 0;
    FILE * Fset = fopen("data/Game/SET.txt", "r");
    if (Fset == NULL) {
        Fset = freopen("data/Game/SET.txt", "a", Fset);
        fprintf(Fset, "%s%d%c", "timer ", 5, '\n');
        fprintf(Fset, "%s%d%c", "strings ", 5, '\n');
        timer = 5;
        strings = 5;
    }
    
    if (Fset != NULL) {
        fscanf(Fset,"timer %d\n", &tmp);
        ((tmp > 0) && (tmp <= 99)) ? (timer = tmp) : (timer = 5);
        fscanf(Fset,"strings %d\n", &tmp);
        ((tmp > 0) && (tmp <= 99)) ? (strings = tmp) : (strings = 5);
        Fset = freopen("data/Game/SET.txt", "w+", Fset);
        fprintf(Fset, "%s%d%c", "timer ", timer, '\n');
        fprintf(Fset, "%s%d%c", "strings ", strings, '\n');
    }
    fclose(Fset);
}

int settings_user(void) /*correct ? return 1 : return 0*/
{
    char Sset_t[5] = {0}, Sset_s[5] = {0};
    int set_t = 0, set_s = 0;
    printf("now TIMER is %d and STRINGS to write is %d\n", timer, strings);
    printf("\tyour settings:\n");
    fgetc(stdin);
    printf("-->TIMER = ");
    scanf("%3s", Sset_t);
    set_t = atoi(Sset_t);
    if (strlen(Sset_t)) while (getc(stdin) != '\n');
    printf("-->STRINGS = ");    
    scanf("%3s", Sset_s);
    if (strlen(Sset_t)) while (getc(stdin) != '\n');
    set_s = atoi(Sset_s);
    system("clear");
    if (correct_set(set_t, set_s)) { 
        FILE *Fset = fopen("data/Game/SET.txt", "w+");
        fprintf(Fset, "%s%d%c", "timer ", timer, '\n');
        fprintf(Fset, "%s%d%c", "strings ", strings, '\n');
        fclose(Fset);
    } else {
        return 0;
    }
    return 1;     
}

int correct_set(int set_t, int set_s) /*correct ? return 1 : return 0*/
{ 
    if ((set_t <= 0) || (set_t > 99)) {
        return 0;
    }
  
    if ((set_s > 0) && (set_s < 100)) {
        timer = set_t;  
        strings = set_s;
    } else {
        return 0;
    }
    return 1;
}
