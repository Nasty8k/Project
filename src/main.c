#include "game_opening.h"
#include "settings.h"
/* Нуждается в доработке проверок на корректность ввода
   и дальнейшего продолжения действий игры */


int main(void){
    
    struct SET set; 
    struct SET * Pset = &set;  
    FILE * Fset = NULL;
    int rez = 5;
    char vvod;
    opening();
    
    printf("YOUR CHOICE: ");
    vvod = getchar();
    while( vvod != '#'){
    switch(vvod) {
        case '1':
            printf("Play:\n");
            break;
        case '2':
            printf("Quick game\n");
            break;
        case '3':
            while(rez != 0) {
                rez = settings_user(Pset);
                if (rez == 0) {
                    main( );
                    break;              
                } else {                  
                    rez = 0; /* Проблемка с меню выбором */
                    main();
                }
            }                                  
            break;
        case '4':
            printf("Table\n");
            break;
        case '5':
            printf("About game\n");
            break;
        default:
            main();
            break;
    }
    vvod = '#';  //Предворительное завершение
    }
    printf("SEE YOU\n");
    return 0;
}
