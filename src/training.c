#include "data_global.h"
#include "training.h"
#include "game_opening.h"

void compare_string(char *s1, char *s2, struct progress *prog)
{	
    int mas[strlen(s1)], i, len;
    for ( len = 0; len < (strlen(s1)); len++) {
		if (s1[len] == s2[len]) {
			if (s1[len] != ' ') {
				prog->right_s = prog->right_s + 1;
				mas[len] = 1;
				if ((s1[len] >= '!') && (s1[len]) <= '/') {
		            prog->points = prog->points + 2;
			    }
			}
		} else {
			prog->wrong_s = prog->wrong_s + 1;
			prog->points = prog->points - 1;
			mas[len] = 0;
		}
	}
	if (strlen(s1) < strlen(s2)) {
		prog->wrong_s = prog->wrong_s + strlen(s2) - strlen(s1);
   }
   system("clear");
   opening();
   printf("%sREZULT%s\t", YELOW, RESET);
   for ( i = 0; i < strlen(s1); i++)
       (mas[i] == 0) ? printf("%s%c%s", RED, s1[i], RESET) : printf("%s%c%s", GREEN, s1[i], RESET);
   printf("\n");  
}

int write_string(char *string, struct progress *prog)
{	
    char s2[N];
    printf("%sFor stop # + Enter%s\n", YELOW, RESET);
    fprintf(stdout, "%s%s%s\n", CYAN, string, RESET);
    fgets(s2, N, stdin);
	if (strchr(s2, '#')) return -1;
    compare_string(string, s2, prog);
    return 0;
}

int training(void)
{
	int level, i;
	float total;
	FILE *file = fopen("data/Game/GAME.txt", "r");
	char string1[n_strings][69], s[69];
	struct progress *prog;

    prog = (struct progress*)malloc(sizeof(struct progress));
	prog->wrong_s = -1.0;
	prog->right_s= 0.0;
	prog->points = 0;
	level = player.level - 1;

	for (i = 0; i != level; i++) fgets(s, 69, file);
	for (i = 0; i < n_strings; i++) {
        fgets(string1[i], 68, file);
        if (feof(file)) break;
		if (write_string(string1[i], prog) == -1) break;
    }
    if (feof(file)) printf("%sCONGRATULATE%sCONGRATULATE%sCONGRATULATE"
                           "%sCONGRATULATE%sCONGRATULATE%s\n", RED, CYAN, GREEN, YELOW, WHITE, RESET);
    fclose(file);
    
    total = (prog->right_s/(prog->right_s + prog->wrong_s)) * 100;
    if (total > 50.00) {
        player.level = level + i;
        printf("Your %sLevelUP   is %d%s\n", RED, player.level, RESET);
    } else {
        printf("Your %sLevelNotUp   is %d%s\n", RED, player.level, RESET);
    }
	
	player.points = player.points + prog->points;
	if (player.points < 0) player.points = 0;
	printf("Your %spoints  is %d%s [-%.0f]\n", YELOW, player.points, RESET, prog->wrong_s + 1);
    player.accur = total;
    printf("Your %saccur   is %.0f%%%s\n", GREEN, player.accur, RESET);
    write_data();
    free(prog);
    return 0;	
}

void write_data(void)
{
    char name_string[30] = {"data/Users/"};
    char *name_P = name_string;
    char tmp[4] = {0};
    char *out = malloc(50 * sizeof(char)), *Ptmp = tmp;  
    strcat(name_P, player.name);
    strcat(name_P, ".txt");
    printf("[%s]", name_P);
    FILE *f = fopen(name_P, "a+"); (f == NULL) ? (printf("!NULL\n")) : (printf("!OK\n"));
    while(fgets(out, 49, f));
    (player.accur > 50) ? (strcpy(Ptmp, "UP")) : (strcpy(Ptmp, "DW"));
    fprintf(f, "%s|%d|%d|%.0f|%s\n", day, player.points, player.level, player.accur, Ptmp);
    fclose(f);
}
