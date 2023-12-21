#include <stdio.h>
#include "color.h"
#include <time.h>
#include "board.h"
#include "compelet_squar.h"
#include "winner.h"
#include "redo.h"
int row ,col ;
int valid_move(char board[row][col],int r,int c) {
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
void makemove(char board[row][col],int r,int c,int movetype,int player) {
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
int maingame(int roow , int cool) {
    clock_t start_time,end;
    double cpu_time_used;
    int minutes, seconds;
   row=roow*2 +1;
   col=cool*2 +1;
   scan(row,col);
   scan2(row,col);
    int score[3]={0,0,0};
    char board[row][col];
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if ((i%2==0)&&(j%2==0)){
                board[i][j] = '.';
                }
                else if (i%2!=0 && j%2!=0)
                {
                    board[i][j]='a';
                    
                }
                else{
                board[i][j] = ' ';}}}
    displayboard(board,row,col);    //initial board

    int currentPlayer=1;
    int moves=0;
    start_time = clock();
    while (moves !=roow*(cool+1)+cool*(roow+1)) {
        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        minutes = (int)(cpu_time_used / 60);  
        seconds = (int)(cpu_time_used) % 60;
        printf(yellow"player 1 score : %d\t"rest blue"player 2 score : %d\n"rest ,score[1],score[2]);
        printf(green"Time: %d:%d \n"rest, minutes, seconds);
        if (currentPlayer == 1)
        {
            printf(yellow"Player %d's turn:\n"rest , currentPlayer);
        }
        else
        {
             printf(blue"Player %d's turn:\n"rest , currentPlayer);
        }

        int r,c;
        printf(red"for exit (-1,-1)\n"rest);
        printf(white"Enter row and column to place a line: "rest);
        scanf("%d %d", &r,&c);
        if (r== -1 && c== -1)
        {
            return 0 ;
        }
        
        int movetype = valid_move(board,r,c);
        if (movetype!=0) {
            makemove(board,r,c,movetype,currentPlayer);
           int play_agin = comp_squer(board,currentPlayer,score);
            if (play_agin==1)
            {
                currentPlayer=(currentPlayer==1)?2:1; // Switch to the next player
            }
            else
            {
                
            }
            displayboard(board,row,col);
            moves++;
            
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    winner(score);
    cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
    minutes = (int)(cpu_time_used / 60);
    seconds = (int)(cpu_time_used) % 60;
    printf(green"Total time taken: %d minutes %d seconds\n"rest, minutes, seconds);
    return 0;
}


