#include "game_opening.h"
#include "training.h"
#include "statistics.h"
#include "settings.h"
#include "ListPlayers.h"
#include "INFO.h"
#include "data_global.h"

int menu(char vvod)
{
    opening();
    int rez = 0, i = 0;
    char in = '#';
        switch(vvod) {
            case '1':
                system("clear");
                opening();
                if (player.number == 0) {
                    printf("%sPlease check in%s\n", YELOW, RESET);
                    rez = check_in();
                } else {
                    training();
                }
                printf("%sLet's go to...%s ", CYAN, RESET);
                scanf("%c", &in);
                while (getc(stdin) != '\n') i++;    
                menu(in); 
                break;
            case '2':
                razminka (timer);
                printf("%sLet's go to...%s ", GREEN, RESET);
                scanf("%c", &in);
                while (getc(stdin) != '\n') i++;    
                menu(in);
                break;
            case '3':
                rez = settings_user( );
                if (rez) {
                    main( );
                    return 0;              
                 } else {
                    opening( );
                    printf("%sNot correct%s(Have question? Look at INFO)%s\n"
                           "Let's go to...%s ", RED, GREEN, YELOW, RESET);
                    scanf("%c", &in);
                    while (getc(stdin) != '\n') i++;
                    menu(in);
                }
            break;
        case '4':
            system("clear");
            opening();
            printf("For %syou[1]%s OR %sgeneral[2]%s?\n", YELOW, RESET, YELOW, RESET);
            printf("%sView -> %s", YELOW, RESET);
            scanf("%c", &in);
            while (getc(stdin) != '\n') i++;
            switch(in) {
                case '1':
                     own_statistics(player.name);
                     break;
                 case '2':
                     general_statistics();
                     break;
                 default:
                     menu(4);
                     break;
            }
            printf("%sLet's go to...%s", GREEN, RESET);
            scanf("%c", &in);
            while (getc(stdin) != '\n') i++;
            menu(in);            
            break;
        case '5':
            information();
            printf("%sLet's go to...%s", YELOW, RESET);
            scanf("%c", &in);
            while (getc(stdin) != '\n') i++;
            menu(in);            
            break;
        case '#':
            printf("exit game\n");
            break;
        default:
            system("clear");
            main();
            break;
            
    }
    
    return 0;
}

