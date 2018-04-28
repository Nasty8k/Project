#include "game_opening.h"
#include "settings.h"

char * settime(struct tm *u)
{
  char s[29];
  char *tmp;
  for (int i = 0; i<29; i++) s[i] = 0;
  strftime(s, 29, "%d.%m.%Y %H:%M, %A", u);
  tmp = (char*)malloc(sizeof(s));
  strcpy(tmp, s);
  return(tmp);
}

void opening(void)
{
    const time_t timer = time(NULL);
    char *day = settime(localtime(&timer));
    struct SET set; 
    struct SET * Pset = &set;  

    settings_inital(Pset); 
    system("clear");
    printf("\n");
    printf("%s ██╗  ██╗███████╗██╗   ██╗  ██████╗  ██████╗  █████╗ ██████╗ ██████╗  \n", RED); 
    printf("%s ██║ ██╔╝██╔════╝╚██╗ ██╔╝  ██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██╔══██╗ \n", CYAN);
    printf("%s █████╔╝ █████╗   ╚████╔╝   ██████╔╝██║   ██║███████║██████╔╝██║  ██║ \n", GREEN);
    printf("%s ██╔═██╗ ██╔══╝    ╚██╔╝    ██╔══██╗██║   ██║██╔══██║██╔══██╗██║  ██║ \n", YELOW);
    printf("%s ██║  ██╗███████╗   ██║     ██████╔╝╚██████╔╝██║  ██║██║  ██║██████╔╝ \n", WHITE);
    printf("%s ╚═╝  ╚═╝╚══════╝   ╚═╝     ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝%s\n", RESET, RESET); 
    printf("%s══════════════%s══════════════%s═══════════════%s════════════════%s═══════════\n%s", RED, CYAN, GREEN, YELOW, WHITE, RESET);
    printf("\t\t\t\t  ____  ____  ____  ____  ____  ____ \n");
    printf(" %s\t %s||n |||%s|i ||%s||n ||%s||j |||%s|a ||||%s¤ ||\n", day, RED, CYAN, GREEN, YELOW, WHITE, RESET);
    printf("\t\t\t\t ||__||||__||||__||||__||||__||||__||\n"
                " %s: %s %2d %s %2d\t |/__\\||/__\\||/__\\||/__\\||/__\\||/__\\|\n",  "SET", "time", set.timer, "|strings", set.strings);
    printf("===========================\n%s 1.PLAY\n%s 2.QUICK GAME\n%s 3.SETTINGS\n%s 4.TABLE\n%s 5.INFO\t\tEXIT #%s\n===========================\n", RED, CYAN, GREEN, YELOW, WHITE, RESET);
                                                                          
     
}


