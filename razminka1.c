#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int mist, correct, oshib = 0, timer;
    char vvod, ch;
    float accuracy;
    long int s_time1, s_time2, total = 0.0; //s_time2 - переменная для сохранения конца интервала

    s_time1 = time (NULL); //Считываем текущее системное время
    s_time2 = time (NULL);

    printf("\nSET TIME IS: ");// timer - это внешние данные
    scanf("%d", &timer);

    vvod = getc(stdin);

    while (total < timer){
        s_time1 = time (NULL);
        ch = ('A' + rand()%('z'-'A'));
        printf("%c --> ", ch);

            while((vvod = getc(stdin)) != '\n') {
                if(ch -= vvod)
                mist++;
                else correct++;
            }

            s_time2 = time (NULL);
            total += difftime (s_time2, s_time1); // Расчитываем разницу между двумя замерами времени с помощью функции difftime*
    }

    float zn; // Знаменатель
    zn = mist+correct;
    accuracy = (correct/zn);

    printf("Mistakes: %d\n", mist); 
    printf("Correct: %d\n", correct);
    printf("Accuracy: %.2f%%\n", accuracy*100); // Точность
    printf("\nPress enter to continue...\n");
go:
    getchar();
    printf("\nDo you want to go to the menu or go again?\n");
    printf("Press # if you want to go to the menu or ! to go through again: \n");

    char a;
    scanf("%c", &a);

    switch(a) {
        case '#':
            return 0;
            break;
        case '!':
            main();
            break;
        default:
            printf("\nTry it again\n");
            goto go;
            break;
    }
}

