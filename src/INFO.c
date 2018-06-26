#include "INFO.h"

void information(void)
{
    system("clear");
    opening();
    printf("%sW E L L %s\n", WHITE, RESET);
    printf("[%s>PLAY%s]       is the main of game process\n", RED, RESET);
    printf("[%s>QUICK GAME%s] is just for fun\n", CYAN, RESET);
    printf("[%s>SETTINGS%s]   You can change TIME and STRINGS (from 1 to 99)\n", GREEN, RESET);
    printf("[%s>TABLE%s]      statistic of game and users\n", YELOW, RESET);
    printf("[%s>INFO%s]       is here\n", WHITE, RESET);
}
