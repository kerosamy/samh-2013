#include<stdio.h>
int valid_move(char **board,int r,int c,int row ,int col) {
    if (r<0 || r>=row || c<0 || c>=col || (r%2==0 && c%2==0)){
        return 0; // invalid move
    }

    if (r%2==0 && c%2!=0 && board[r][c]==' ') {
        return 1; //valid horizontal
    } else if (r%2!=0 && c%2==0 && board[r][c]==' ') {
        return 2; //valid vertical
    }

    return 0; //invalid move
}