#include "game_opening.h"
#include "settings.h"
#include "INFO.h"
#include "data_global.h"

int menu(char vvod)
{
    opening();
    int rez = 0;
    char in = '#';
        switch(vvod) {
            case '1':
                printf("Play:\n");
                break;
            case '2':
                printf("Quick game\n");
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
                    menu(in); 
              }                                            
            break;
        case '4':
            printf("Table\n");
            break;
        case '5':
            information();
            printf("%sLet's go to...%s", YELOW, RESET);
            while (getc(stdin) != '\n');
            scanf("%c", &in);
            menu(in);            
            break;
        case '#':
            printf("exit game\n");
            break;
        default:
            while (getc(stdin) != '\n');
            system("clear");
            main();
            break;
            
    }
    
    return 0;
}


