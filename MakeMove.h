#include<stdio.h>
void makemove(char **board,int r,int c,int movetype,int player) {
    int dash = 196;int dash1 = 195;int dash2 = 197;int slash1 = 123;int slash2 = 125;
    if(player==1){
    if (movetype==1) { //horizontal line
        board[r][c] = dash1;
    } else if (movetype == 2) { //vertical line
        board[r][c] = slash1;
    }
    }
    else 
    {
       if (movetype==1) { //horizontal line
        board[r][c] = dash2;
    } else if (movetype == 2) { //vertical line
        board[r][c] = slash2;
    }
    }
}