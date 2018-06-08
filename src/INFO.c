#include "data_global.h"
#include "game_opening.h"
/*После заполнения информацией для пользователя INFO будет включен в 5 пункт меню*/
void information(void)
{
    opening();
    printf("WELCOME!\n");
    printf("[1. PLAY] is the main of game process\n");
    printf("[2. QUICK GAME] is just for fun\n");
    printf("[3. SETTINGS] You can change TIME and STRINGS (from 1 to 99)\n");
    printf("[4. TABLE] statistic of game and users\n");
    printf("[5. INFO] is here\n");
}
