#include "game_opening.h"
#include "settings.h"
#include "data_global.h"
/* Нуждается в доработке проверок на корректность ввода
   и дальнейшего продолжения действий игры */

int main(void){ 
    char vvod;
    int i = 0;
    opening( );   
    printf("YOUR CHOICE: ");
    scanf("%c", &vvod);
    while (getc(stdin) != '\n') i++;    
    if ((vvod >= '1') && (vvod <= '5') && (i == 0)) {
       menu(vvod);
       return 0;
    } else {
       if (vvod == '#') {
           system("clear");
           printf("SEE YOU\n");
       } else {
           system("clear");
           main();
       }
    }
    return 0;
}
