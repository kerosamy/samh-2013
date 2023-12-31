#include <stdio.h>
#include <stdlib.h>
#include"winnercomp.h"

int row ,col ;
int checkcomplete_sq(char **board, int r, int c,int row,int col) { //check if the computer has opportunity to complete a square
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
                    makemove(board,r,c,1,2);  //if yes make this move which is horizontal
                    return 1;
                } else {
                   makemove(board,r,c,2,2);   //vertical
                    return 1;
                }
            }
        }
    }
    return 0;
}
int maingamec(int roow ,int cool) {
    int saveOne= 0;
    int mode=0;
    int BackArr[70];
    int dfsArr[row][col];
    int box1,box2 ,Totalline=(roow*(cool+1)+cool*(roow+1)); 
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
      
        
         
        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        minutes = (int)(cpu_time_used / 60);  
        seconds = (int)(cpu_time_used) % 60;
        if (NoPrint==0){
        displayboard(board,row,col);
        printf(BMAG"player 1 score : %d             "rest blue"player 2 score : %d\n"rest ,score[1],score[2]);
        printf(yellow"Time: %d:%d                      "rest, minutes, seconds);
        printf(yellow"Number of remaining lines : %i\n"rest,Totalline-line1-line2) ;
        printf(BMAG"Number of lines for P1: %i      "rest,line1);printf(blue"Number of lines for computer: %i\n"rest,line2);
         if (currentPlayer == 1)
        {
            printf(BMAG"Player %d's turn:\n"rest , currentPlayer);
            }}
        if(currentPlayer==1){
        printf(red"for exit (-1,-1)     "rest green"for undo (0,0)     "rest cyan"for redo (1,1)"rest      black"for save (-2,-2)\n"rest);
        printf(white"Enter row and column to place a line: "rest);
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
            return 0 ;
        }
         if (r==0 && c==0)
        {
           if (undo>=1)
           {  
             delet(board,BackArr,&ind);
             check(board,row,col,score,currentPlayer);
             moves--;
             line1--;
              
              redo++;
              dots=dots+2;
           }
        }
         if (r==1 && c==1)
        {  
            if (redo>=1)
            {
               
                 redo--;
                 r = BackArr[ind];
                 c=BackArr[ind+1];
            }
        }
         if(r==-2 &&c==-2){
            savegame(board,row,col,score,currentPlayer,line1,line2,minutes,seconds,moves,mode,&saveOne);
            printf("\033[2J\033[1;1H");
            printf(green"game saved successefuly\n"rest);
        }
        int movetype = valid_move(board,r,c,row,col);
        if (movetype!=0) {
            makemove(board,r,c,movetype,currentPlayer);
           int play_agin = comp_squer(board,currentPlayer,score,row,col,&box1,&box2);
            if (play_agin==1)
            {
                currentPlayer=2; // Switch to the next player
                 undo = 0;
                 redo =0;
            }
            else
            {
                undo++;
                BackArr[ind]=r;
                BackArr[ind+1]=c;
                ind=ind+2;
                
                
            }
            moves++;
            line1++;
        } else {
            if (r==0 && c==0 && undo>=1)
            {
               undo--; 
            }
            else
            {    
                if (r==-2 && c==-2)
                {
                }
                else{
                 printf(red"Invalid move! Try again.\n"rest);}
            }
        }
    }
    if(currentPlayer!=1){
        printf(blue"Computer's turn:\n"rest );
        int po;
        po=checkcomplete_sq(board,r,c,row,col);    
        if(po==1){           //he found a move that complete a square
            comp_squer(board,2,score,row,col,&box1,&box2);
              NoPrint=1;
               moves++;
               line2++;
               
        }
        else{ 
            int movefound=0;
            for (int i = 0; i < row && !movefound; i++) {   //enter the loop until he found a valid move then break
                for (int j = 0; j < col && !movefound; j++) {
                    movetype=valid_move(board,i,j,row,col);
                    if (movetype!=0){
                    makemove(board,i,j,movetype,2);
                    movefound=1;
                    moves++;
                    line2++;
                    currentPlayer=1;
                    NoPrint=0;
                    comp_squer(board,2,score,row,col,&box1,&box2);
                    break;}
            }  
        }
        } }}
    displayboard(board,row,col);
    cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
    minutes = (int)(cpu_time_used / 60);
    seconds = (int)(cpu_time_used) % 60;
    winnerc(score,minutes,seconds,roow,cool);   //calculate the score and check the winner 
    for (int i = 0; i < row; i++) {
        free(board[i]);
    }
    free(board);
    return 1;}
