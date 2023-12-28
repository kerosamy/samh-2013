#include <stdio.h>
#include <stdlib.h>
#include "color.h"
char nameof_file[50];

void savegame( char** board, int row, int col, int* score, int currentPlayer,int line1,int line2,int minutes,int seconds,int moves,int mode,int *p) {
    if(*p==0){
            printf(BMAG"Enter a name for file save!\n"rest);
            scanf ("%s",&nameof_file);
            *p=*p+1;
            } 
    FILE* file ;
    file= fopen(nameof_file, "w");
    if (file == NULL) {
        printf(red"Error opening file for writing.\n"rest);
        return;
    }
    fprintf(file, "%d %d\n", row, col);
    fprintf(file, "%d %d \n", score[1], score[2]);
    fprintf(file, "%d\n", currentPlayer);
    fprintf(file, "%d %d\n", line1,line2);
    fprintf(file, "%d %d\n",minutes,seconds);
    fprintf(file, "%d\n", moves);
    fprintf(file, "%d\n", mode);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fprintf(file, "%d ", board[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
