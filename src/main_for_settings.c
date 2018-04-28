#include "settings.h"

int main()
{   
    struct SET set; 
    struct SET * Pset = &set;  
    FILE * Fset = NULL;
      
    int rez = 0;
    rez = settings_inital(Fset, Pset);  /* Установка в начале игры. Добавить в главный main */
    /* Эти данные можно вывести в меню */
    if (rez) {
        printf("\nINITAL TIMER is %d | STRINGS is %d\n", set.timer, set.strings);
    }    
    /* Сама функция настройки от пользователя*/
    rez = settings_user(Fset, Pset);
    
    /* Здесь должен быть выход в меню*/
    if (rez == 0) {
        printf("return to main menu\n");
        return 0;
    }
    
    /* А здесь вопросы из главного меню о перезапуске или отмена усановки */
    if (rez == -1) {        
        printf("NOT\nTIMER is %d and STRINGS to write is %d\n", set.timer, set.strings);
        printf("need function overrides from main menu\n");
    }
    return 0;
}

