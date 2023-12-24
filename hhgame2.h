#include <stdio.h>
#include "color.h"
#include <time.h>
#include "stdlib.h"
#include "board.h"
#include "check_sq.h"
#include "winner.h"
#include "redo.h"
#include "valid.h"
#include "MakeMove.h"
int row ,col , redo = 0 , ind=0 ,redo2 = 0;

int maingame(int roow , int cool) {
    int BackArr[20];
    int line1=0 ,line2=0;
    clock_t start_time,end;
    double cpu_time_used;
    int minutes, seconds;
   row=roow*2 +1;
   col=cool*2 +1;
    int score[3]={0,0,0};
    char **board;
    board=(char**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++)
   {
   board[i]=(char*)malloc(col*sizeof(int));
   }
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
    

    int currentPlayer=1;
    int moves=0;
    start_time = clock();
    while (moves !=roow*(cool+1)+cool*(roow+1)) {
        displayboard(board,row,col);    //initial board

        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        minutes = (int)(cpu_time_used / 60);  
        seconds = (int)(cpu_time_used) % 60;
         printf(yellow"player 1 score : %d             "rest blue"player 2 score : %d\n"rest ,score[1],score[2]);
        printf(green"Time: %d:%d                      "rest, minutes, seconds);
        printf(MAG"Number of dots : %i\n"rest,2) ;
        printf(yellow"Number of lines for P1: %i      "rest,line1);printf(blue"Number of lines for p2: %i\n"rest,line2);
        if (currentPlayer == 1)
        {
            printf(yellow"Player %d's turn:\n"rest , currentPlayer);
        }
        else
        {
             printf(blue"Player %d's turn:\n"rest , currentPlayer);
        }

        int r,c;
          printf(red"for exit (-1,-1)     "rest green"for undo (0,0)     "rest cyan"for redo (1,1)\n"rest);
        printf(white"Enter row and column to place a line: "rest);
        scanf("%d %d", &r,&c);
        printf("\033[2J\033[1;1H");
        if (r== -1 && c== -1)
        {
            return 0 ;
        }
        if (r==0 && c==0)
        {
           if (redo>=1)
           {  
             delet(board,BackArr,&ind);
             check(board,row,col,score,currentPlayer);
             if (currentPlayer==1)
             {
               line1--;
             }
             else{line2--;}
             moves--;
              redo2++;
           }
           
        }
       
         if (r==1 && c==1)
        {  
            if (redo2>=1)
            {
               
                 redo2--;
                r = BackArr[ind];
                c=BackArr[ind+1];
            }
            
            
        }
        
         int movetype = valid_move(board,r,c,row,col);
        if (movetype!=0) {
            if (currentPlayer==1)
            {
                line1++;
            }
            else{line2++; }
            makemove(board,r,c,movetype,currentPlayer);
           int play_agin = comp_squer(board,currentPlayer,score,row,col);
            if (play_agin==1)
            {
                currentPlayer=(currentPlayer==1)?2:1; // Switch to the next player
                redo = 0;
                redo2 =0;
            }
            else
            {
                redo++;
                BackArr[ind]=r;
                BackArr[ind+1]=c;
                ind=ind+2;
               
            }
           
            
            moves++;
            
        } else {
            if (r==0 && c==0 && redo>=1)
            {
                redo--; 
            }
            else
            {
                 printf(red"Invalid move! Try again.\n"rest);
            }

        }
    }
    winner(score);
    cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
    minutes = (int)(cpu_time_used / 60);
    seconds = (int)(cpu_time_used) % 60;
    printf(green"Total time taken: %d minutes %d seconds\n"rest, minutes, seconds);
    for (int i = 0; i < row; i++)
    {
        free(board[i]);
    }
    free(board);
    return 0;
}


