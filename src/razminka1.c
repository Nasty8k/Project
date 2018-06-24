#include "game_opening.h"

int razminka(int timer)
{
    float mist = 0.0, correct = 0.0;
    char vvod, ch;
    float accuracy;
    long int s_time1, s_time2, total = 0.0;

    while (total < timer) {
        s_time1 = time (NULL);
        ch = ('A' + rand()%('z'-'A'));
        printf("%c --> ", ch);
        while ((vvod = getc(stdin)) != '\n') {
            (ch -= vvod) ? mist++ : correct++;
        }
        s_time2 = time (NULL);
        total += difftime(s_time2, s_time1);
    }
    accuracy = (correct/(mist + correct));
    printf("Mistakes: %.0f\n", mist); 
    printf("Correct: %.0f\n", correct);
    printf("Accuracy: %.2f%%\n", accuracy*100);
}

