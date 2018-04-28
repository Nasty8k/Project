#include "settings.h"


int settings_inital(FILE * Fset, struct SET * Pset)
{

    int tmp = 0;
    
    Fset = fopen("data/Game/SET.txt", "r");
    if (Fset == NULL) {
        printf("not filr\n");
        Fset = freopen("data/Game/SET.txt", "a", Fset);
        fprintf(Fset, "%s%d%c", "timer ", 5, '\n');
        fprintf(Fset, "%s%d%c", "strings ", 5, '\n');
        
    }
    
    if (Fset != NULL) {
        printf("yes filr\n");
        fscanf(Fset,"timer %d\n", &tmp);
        ((tmp > 0) && (tmp <= 99)) ? (Pset->timer = tmp) : (Pset->timer = 5);
        fscanf(Fset,"strings %d\n", &tmp);
        ((tmp > 0) && (tmp <= 99)) ? (Pset->strings = tmp) : (Pset->strings = 5);
        Fset = freopen("data/Game/SET.txt", "w+", Fset);
        fprintf(Fset, "%s%d%c", "timer ", Pset->timer, '\n');
        fprintf(Fset, "%s%d%c", "strings ", Pset->strings, '\n');
    }
    fclose(Fset);
    return 1;
}

int settings_user(FILE * Fset, struct SET * Pset)
{
    int vvod = 0;
    int tmp = 0;

    /* Если файла не существует, то создается + проверка на корректность данных */
    Fset = fopen("data/Game/SET.txt", "r");
    if (Fset == NULL) { 
        Fset = freopen("data/Game/SET.txt", "a", Fset);
        fprintf(Fset, "%s%d%c", "timer ", 5, '\n');
        fprintf(Fset, "%s%d%c", "strings ", 5, '\n');
        Fset = freopen("data/Game/SET.txt", "r", Fset);       
    } 

    printf("now TIMER is %d and STRINGS to write is %d\n", Pset->timer, Pset->strings);
    printf("\tyour settings: please from 1 to 99\n");
    printf("-->TIMER = ");
    
    scanf("%d", &vvod);
   
    if ((vvod > 0) && (vvod < 100)) {
        tmp = vvod;
    } else {
        printf("NOT CORRECT TIME FORM\n");
        fclose(Fset);
        return -1;
    }              
   
    printf("-->STRINGS = ");    
    scanf("%d", &vvod);
   
    if ((vvod > 0) && (vvod < 100)) {
        Pset->timer = tmp;  
        Pset->strings = vvod;
        Fset = freopen("data/Game/SET.txt", "w+", Fset);
        fprintf(Fset, "%s%d%c", "timer ", Pset->timer, '\n');
        fprintf(Fset, "%s%d%c", "strings ", Pset->strings, '\n');
    } else {
        printf("NOT CORRECT STRINGS FORM\n");
        fclose(Fset);
        return -1;
    }
    
    fclose(Fset);
    return 0;     
}

