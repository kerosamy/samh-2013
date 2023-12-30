#include <stdio.h>
#include "color.h"
#include <time.h>
#include "stdlib.h"      
#include "board.h"
#include "check_sq.h"
#include "redo.h"
#include "valid.h"
#include "MakeMove.h"
#include "DFS.h"
#include"nextBox.h"
#include"chain.h"
#include"test_top.h"
#include "save.h"

int row ,col , undo = 0 , ind=0 ,redo = 0;int mode=1;
int maingame(int roow , int cool) {
   int saveOne= 0;
    int box1,box2,Totalline=(roow*(cool+1)+cool*(roow+1));
    int BackArr[70];
    int r,c;
    int line1=0 ,line2=0;
    clock_t start_time,end;
    double cpu_time_used;
    int minutes, seconds;
   row=roow*2 +1;
   col=cool*2 +1;
    int score[3]={0,0,0};
    char **board;
    int dfsArr[row][col];
    board=(char**)malloc(row*sizeof(int*));       //reserve place in the memory 
    for (int i = 0; i < row; i++)
   {
   board[i]=(char*)malloc(col*sizeof(int));
   }
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if ((i%2==0)&&(j%2==0)){               //for display the initial board
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
    start_time = clock();        //start the time
    while (moves !=roow*(cool+1)+cool*(roow+1)) {
        displayboard(board,row,col);    //initial board

        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        minutes = (int)(cpu_time_used / 60);  
        seconds = (int)(cpu_time_used) % 60;
         printf(BMAG"player 1 score : %d             "rest blue"player 2 score : %d\n"rest ,score[1],score[2]);
        printf(BMAG"Number of lines for P1: %i      "rest,line1);printf(blue"Number of lines for p2: %i\n"rest,line2);
        printf(yellow"Time: %d:%d                      "rest, minutes, seconds);   printf(yellow"Number of remaining lines : %i\n"rest,(Totalline-line1-line2)) ;
      
       
        if (currentPlayer == 1)
        {
            printf(BMAG"Player %d's turn:\n"rest , currentPlayer);
        }
        else                                                        //printing the rest of the game
        {
             printf(blue"Player %d's turn:\n"rest , currentPlayer);
        }
          printf(red"for exit (-1,-1)     "rest green"for undo (0,0)     "rest cyan"for redo (1,1)     "rest black"for save (-2,-2)\n");
        printf(white"Enter row and column to place a line: "rest);
          ////////////////////////////////////////////////////////////////////////////////////

         while (scanf("%d %d", &r,&c)!=2){
            printf(red "\nNOT VALID!!.Please enter numbers.\n\n" rest);
            while (getchar() != '\n'); 
            continue;
        }
        printf("\033[2J\033[1;1H");
        if (r== -1 && c== -1)
        {
             for (int i = 0; i < row; i++)    //free the board
           {
            free(board[i]);
           }
           free(board);
            return 0 ;    //exit 
        }
        if (r==0 && c==0)
        {
           if (undo>=1)
           {  
             delet(board,BackArr,&ind);
             check(board,row,col,score,currentPlayer);    //undo function 
             if (currentPlayer==1)
             {
               line1--;
             }
             else{line2--;}
             moves--;
              redo++;
           }
        }
         if (r==1 && c==1)
        {  
            if (redo>=1)
            {
                 redo--;                           //redo function
                r = BackArr[ind];
                c=BackArr[ind+1];
            } 
        }
        if(r==-2 &&c==-2){
            end= clock(); 
            cpu_time_used = ((double)(end - start_time)) / CLOCKS_PER_SEC;
            minutes = (int)(cpu_time_used / 60);
            seconds = (int)(cpu_time_used) % 60;
            savegame(board,row,col,score,currentPlayer,line1,line2,minutes,seconds,moves,mode,&saveOne);
            printf("\033[2J\033[1;1H");
            printf(green"game saved successefuly\n"rest);
            
        }
         int movetype = valid_move(board,r,c,row,col);    //check if it is valid or not (if it is not it returns o)
        if (movetype!=0) {
            if (currentPlayer==1)
            {
                line1++;
            }
            else{line2++; }
            makemove(board,r,c,movetype,currentPlayer);      //make the move on the board
           int play_agin = comp_squer(board,currentPlayer,score,row,col,&box1,&box2); //check if the player completed a square
            if (play_agin==1)    //didn't complete a square so we have to switch the players
            {
                currentPlayer=(currentPlayer==1)?2:1; // Switch to the next player
                undo = 0;
                redo =0;
            }
            else
            {
                undo++;
                BackArr[ind]=r;
                BackArr[ind+1]=c;
                ind=ind+2;
                int x = 1;
                zeroArr(col,row,dfsArr);
                nextbox(board,movetype,r,c,&box1,&box2,row,col);
                if (box1!=0 && box2!=0)
                {
                    if (DFS(board,row,col,box1,box2,dfsArr,&x))    //check if it exist a chain and complete it
                {
                   
                    if (noTchain(row,col,dfsArr,board))
                    {
                         chain(board,row,col,dfsArr,currentPlayer,score,BackArr,&ind,&undo,&line1,&line2,&moves);
                    }
                }
                }
            }
            moves++;
        } else {
            if (r==0 && c==0 && undo>=1)
            {
                undo--; 
            }
            else
            {    if (r==-2 && c==-2)
                {
                }
                else{
                 printf(red"Invalid move! Try again.\n"rest);}
            }

        }
    }
    displayboard(board,row,col);
    cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;   //calculate the time at this instant
    minutes = (int)(cpu_time_used / 60);
    seconds = (int)(cpu_time_used) % 60;
    winner(score,minutes,seconds,roow,cool,1);    //calculate the score 
    
    for (int i = 0; i < row; i++)    //free the board
    {
        free(board[i]);
    }
    free(board);
    return 1;
}


