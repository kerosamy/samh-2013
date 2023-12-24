#include <stdio.h>
#include <stdlib.h>
#include "winnercomp.h"

int row ,col ;
int checkcomplete_sq(char **board, int r, int c,int row,int col) {
    for (int i = 1; i < row; i = i + 2) {
        for (int j = 1; j < col; j = j + 2) {
            int numberOfClosedEdges = 0;
            int shifts[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for (int shift = 0; shift < 4; shift++) {
                if (board[i + shifts[shift][0]][j + shifts[shift][1]] != ' ') {
                    numberOfClosedEdges++;
                 } else {
                    r = i + shifts[shift][0];
                    c = j + shifts[shift][1];
                }
            }
            if (numberOfClosedEdges == 3) {
                if (((r % 2) == 0) && ((c % 2) != 0)) {
                    makemove(board,r,c,1,2);
                    return 1;
                } else {
                   makemove(board,r,c,2,2);
                    return 1;
                }
            }
        }
    }
    return 0;
}
int maingamec(int roow ,int cool) {
    
    int BackArr[20];
    int r,c,movetype;
    clock_t start_time,end;
    double cpu_time_used;
    int minutes, seconds;
   row=roow*2 +1;
   col=cool*2 +1;
   int line1=0 ,line2=0, dots= (roow+1)*(cool+1);
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
    int moves=0; int NoPrint=0;
    start_time = clock();
    while (moves !=roow*(cool+1)+cool*(roow+1)) {
        if (NoPrint==0)
        {
            
            
        }
        
         
        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        minutes = (int)(cpu_time_used / 60);  
        seconds = (int)(cpu_time_used) % 60;
        if (NoPrint==0){
        displayboard(board,row,col);
        printf(yellow"player 1 score : %d             "rest blue"player 2 score : %d\n"rest ,score[1],score[2]);
        printf(green"Time: %d:%d                      "rest, minutes, seconds);
        printf(MAG"Number of dots : %i\n"rest,dots) ;
        printf(yellow"Number of lines for P1: %i      "rest,line1);printf(blue"Number of lines for computer: %i\n"rest,line2);
         if (currentPlayer == 1)
        {
            printf(yellow"Player %d's turn:\n"rest , currentPlayer);
            }}
        if(currentPlayer==1){
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
             moves--;
             line1--;
              
              redo2++;
              dots=dots+2;
              

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
            makemove(board,r,c,movetype,currentPlayer);
            
           int play_agin = comp_squer(board,currentPlayer,score,row,col);
            if (play_agin==1)
            {
                currentPlayer=2; // Switch to the next player
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
          
            line1++;
            
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
    if(currentPlayer!=1){
        printf(blue"Computer's turn:\n"rest );
        int po;
        po=checkcomplete_sq(board,r,c,row,col);
        if(po==1){
            comp_squer(board,2,score,row,col);
              NoPrint=1;
               moves++;
               line2++;
               
        }
        else{ 
            int movefound=0;
            for (int i = 0; i < row && !movefound; i++) {
                for (int j = 0; j < col && !movefound; j++) {
                    movetype=valid_move(board,i,j,row,col);
                    if (movetype!=0){
                    makemove(board,i,j,movetype,2);
                    movefound=1;
                    moves++;
                    line2++;
                    currentPlayer=1;
                    NoPrint=0;
                    comp_squer(board,2,score,row,col);
                    break;}
            }  
        }
        } }}
 winnerc(score);
    cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
    minutes = (int)(cpu_time_used / 60);
    seconds = (int)(cpu_time_used) % 60;
    printf(green"Total time taken: %d minutes %d seconds\n"rest, minutes, seconds);
    for (int i = 0; i < row; i++) {
        free(board[i]);
    }
    free(board);
    return 0;}
