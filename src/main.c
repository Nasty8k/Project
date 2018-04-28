#include "game_opening.h"
/* Нуждается в доработке проверок на корректность ввода
   и дальнейшего продолжения действий игры */


int main(void){

    char var;
    opening();
    
    printf("YOUR CHOICE: ");
    var = getchar();
    while( var != '#'){
    switch(var) {
        case '1':
            printf("Play:\n");
            break;
        case '2':
            printf("Quick game\n");
            break;
        case '3':
            printf("Settings\n");
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
    var = '#';  //Предворительное завершение
    }
    printf("SEE YOU\n");
    return 0;
}
