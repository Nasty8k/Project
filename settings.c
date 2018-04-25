#include <stdio.h>
#include <stdlib.h>


struct SET {
        int timer;
        int strings;
};

int settings_inital(FILE * Fset, struct SET * Pset);
int settings_user(FILE * Fset, struct SET * Pset);


int main()
{   
    struct SET set; 
    struct SET * Pset = &set;  
    FILE * Fset = NULL;
      
    int rez = 0;
    rez = settings_inital(Fset, Pset);  /* Установка в начале игры. Добавить в главный main */
    /* Эти данные можно вывести в меню */
    if (rez) {
        printf("\nTIMER is %d and STRINGS to write is %d\n", set.timer, set.strings);
    }    
    /* Сама функция настройки от пользователя*/
    rez = settings_user(Fset, Pset);
    
    /* Здесь должен быть выход в меню*/
    if (rez == 0) {
        printf("return to main menu\n");
        main( );
    }
    
    /* А здесь вопросы из главного меню о перезапуске или отмена усановки */
    if (rez == -1) {        
        printf("NOT\nTIMER is %d and STRINGS to write is %d\n", set.timer, set.strings);
        printf("need function overrides from main menu\n");
    }
    return 0;
}


int settings_inital(FILE * Fset, struct SET * Pset)
{

    int tmp = 0;
    
    Fset = fopen("SET.txt", "r");
    if (Fset == NULL) {
        printf("not filr\n");
        Fset = freopen("SET.txt", "a", Fset);
        fprintf(Fset, "%s%d%c", "timer ", 5, '\n');
        fprintf(Fset, "%s%d%c", "strings ", 5, '\n');
        
    } else {
        
        printf("yes filr\n");
        fscanf(Fset,"timer %d\n", &tmp);
        ((tmp > 0) && (tmp <= 99)) ? (Pset->timer = tmp) : (Pset->timer = 5);
        fscanf(Fset,"strings %d\n", &tmp);
        ((tmp > 0) && (tmp <= 99)) ? (Pset->strings = tmp) : (Pset->strings = 5);
        Fset = freopen("SET.txt", "w+", Fset);
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
    Fset = fopen("SET.txt", "r");
    if (Fset == NULL) { 
        Fset = freopen("SET.txt", "a", Fset);
        fprintf(Fset, "%s%d%c", "timer ", 5, '\n');
        fprintf(Fset, "%s%d%c", "strings ", 5, '\n');
        Fset = freopen("SET.txt", "r", Fset);       
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
        Fset = freopen("SET.txt", "w+", Fset);
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

