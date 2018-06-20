/*
 Нужна проверка и дороботка.
 1) Существует ли имя в списке
 2) Создание файла <NAME>.txt игрока в data/Users
 3) Варианты выхода с успехом (1) или ошибкой (-1)
   проверку на латинские буквы
   проверку списка
   построение выбора меню
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_in_name(char *new_name, int all)
{
    int len = strlen(new_name);
    if ((all >= 15) || (all == 0)) {
        printf("The lenght of name from 1 to 15\n");
        return 0;
    }
    if ((*new_name >= '0') && (*new_name <= '9')) {
        printf("the first letter must be a symbol\n");
        return 0;
    }   
    for(int i = 0; i < len; i++)
        if ((new_name[i] == ' ')
            || (new_name[i] == '#')
               || (new_name[i] == '\\')) {
            printf("Do not use space or <\\> and <#>\n");
            return 0;
        }
    return 1;
}

int check_list(int num)
{
    printf("LIST \n");
    
    return num;
}

int main(){
    char s[16] = {0};
    char *p = s, c;
    int i = 0, in = 0, f = 1;

    printf("Enter Your num or New name: ");
    while((c = getc(stdin))!='\n')
    {   
        if (i < 15) {
            s[i] = c;
            (c >= '0' && c <= '9') ? (f *=f) : (f = 0);
        }
        i++;
    }
    in = atoi(p);

    (in * f == 0) ? (in = check_in_name(p, i)) : (in = check_list(in));
    printf("IN = %d\n", in);
    
    printf("Yor choose: ");
    scanf("%s", p);
    printf("--> [%s]", p);
    return 0;

}
