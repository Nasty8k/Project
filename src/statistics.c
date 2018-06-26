#include "statistics.h"

int counter(char *file_name)// считает '\n'
{
    FILE *file = fopen(file_name, "r");
    if( file == NULL) return 0;
    int i = 0;
    char c;
    while ((c = fgetc(file)) != EOF){
        if (c == '\n')
            i++;
    }
    fclose(file);
    return i;
}
    
void own_statistics(char *name)
{
    char file_name[17] = {"data/Users/"};
    char string[50] = {0};
    char *str = string;
    strcat(file_name, name);
    strcat(file_name,".txt");
    FILE *namef = fopen(file_name, "r");
    if (namef == NULL) {
        printf("Sorry, file not found\n");
        return ;
    }
    printf("YOUR STATISTICS\n");   
    for ( int i = 0; i <= counter(file_name); i++){
        fscanf(namef, "%s", str); 
        fprintf(stdout, "%s\n", str);
    } 
}

void general_statistics(void)
{
    FILE *F_LP, *NAME_F;
    char c, out[50] = {0}, l_name[20] = {0};
    char list_string[30] = {"data/Game/ListPlayers.txt"};
    char *list_pointer = list_string, *out_p = out, *list = l_name;
    int num, j, i;
    printf("GENERAL STATISTICS\n");
                   
    //F_LP = fopen("data/Game/ListPlayers.txt", "r"); 
    //(F_LP != NULL) ? printf("!!!!!") : printf("!!");
    //i = counter(list_pointer); printf("%d I[]", i);

    //for (j = 0; j < i; j++) fscanf(F_LP, "%d.%s", &num, list); printf("%d%s, ", num, list);
    
    //добавление  к имени игрока ".txt"
   /* for (j = 0; j < i; j++) strcat(list,".txt");
    
    for (j = 0; j < i; j++){// открытие файла типа NAME.txt
        char *name_pointer;
        char name_string[30] = {"data/Users/"};
        strcat(name_pointer, list);
        NAME_F = fopen(name_pointer, "r");
        if (NAME_F != NULL) {
            while (fgets(out_p, 49, NAME_F) != NULL);
            fprintf(stdout, "%s| %s\n", list, out_p);       
            fclose(NAME_F);
        }
    }   
    fclose(F_LP);*/
}
/*
void write_data(void)
{
    char name_string[30] = {"data/Users/"};
    char *name_P = name_string;
    char *out = malloc(50 * sizeof(char));   
    strcat(name_P, player.name);
    strcat(name_P, ".txt");
    printf("[%s]", name_P);
    FILE *f = fopen(name_P, "a+"); (f == NULL) ? (printf("!NULL\n")) : (printf("!OK\n"));
    while(fgets(out, 49, f));
    fprintf(f, "%s|%d|%d|%.0f|%c%c\n", day, player.points, player.level, player.points, player.points, player.accur, player.ps[0], player.ps[1]);
    fclose(f);
}*/
