#include<stdio.h>
#include "color.h"
void displayboard(char **board,int row ,int col){   //display the board
    printf("  ");
    
    int dash = 196;int dash1 = 195;int dash2 = 197;int slash1 = 123;int slash2 = 125;
    for (int i=0;i<col;i++) {
        if (i<10)
        {
        printf(black"%d "rest,i);
        }
        else
        {
            printf(black"%d "rest,i%10);
        }
    }
    printf("\n");
    for (int i=0;i<row;i++) {
        if (i<10)
        {
             printf(black"%d "rest ,i);
        }
        else
        {
            printf(black"%d"rest ,i);
        }
        
        for (int j=0;j<col;j++) {
            if (board[i][j]== '.')
            {
                printf(BWHT"%c "rest ,board[i][j]);
            }
            else if (board[i][j]=='a')
            {
                printf(green"%c "rest ,board[i][j]);
            }
            else if (board[i][j]=='k')
            {
                 printf(blue"%c "rest ,board[i][j]);
            }
            else if (board[i][j]=='c')
            {
                printf(BMAG"%c "rest ,board[i][j]);
            }
            else if (board[i][j]== (char) dash1 || board[i][j]== (char) slash1)
            {
                printf(BMAG"%c "rest ,board[i][j]+1);
            }
            else if (board[i][j]== (char) dash2 || board[i][j]== (char) slash2)
            {
                printf(blue"%c "rest ,board[i][j]-1);
            }
            else{
            printf("%c ",board[i][j]);
            }
        }
        printf("\n");}}