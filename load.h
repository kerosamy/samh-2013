#include<stdio.h>
#include<stdlib.h>
#include "color.h"
char nameof_file[50];
int print (){
    int i =0;
    while (i!=1)
    {
        printf(cyan"Enter the name of your file:\n"rest);
        printf(red"For exit enter (1):\n"rest);
       scanf ("%s",nameof_file);
       printf("\033[2J\033[1;1H");
        FILE *file=fopen(nameof_file, "r");
        if (nameof_file[0]=='1'&&nameof_file[1]=='\0')
        {
           return 0;
        }
        
      if (file==NULL)
       {
         printf(red"The game does not exist\n"rest);
       }
       else
       {
        i = 1;
       }
    }
    FILE *file=fopen(nameof_file, "r");
    int row, col,moves;
    int score[3];
    int currentPlayer;
    int line1,line2,savedminutes,savedseconds;
    int mode;
    fscanf(file, "%d %d", &row, &col);
    fscanf(file, "%d %d", &score[1], &score[2]);
    fscanf(file, "%d", &currentPlayer);
    fscanf(file, "%d %d", &line1,&line2);
    fscanf(file, "%d %d", &savedminutes,&savedseconds);
    fscanf(file, "%d", &moves);
    fscanf(file, "%d", &mode);
char board[row][col];
char **board2;
int Totalline=((row/2)*((col/2)+1)+(col/2)*((row/2)+1));
board2=(char**)malloc(row*sizeof(int*));
    for (int i = 0; i < row; i++)
   {
   board2[i]=(char*)malloc(col*sizeof(int));
   }
for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            fscanf(file, "%d", &board[i][j]);
        }
    }
int dash = 196;int dash1 = 195;int dash2 = 197;int slash1 = 123;int slash2 = 125;
    for (int i=0; i<row;i++){
        for (int j = 0; j < col; j++) {
        if (board[i][j] == 46) {
            board2[i][j]='.';
        } else if (board[i][j] == 97) {
             board2[i][j]='a';
        } else if (board[i][j] == 99) {
            board2[i][j]='c';
        }else if (board[i][j] == 107) {
            board2[i][j]='k';
        }else if (board[i][j] == -61) {
            board2[i][j]=dash1;
        }else if (board[i][j] == -59) {
             board2[i][j]=dash2;
        }else if (board[i][j] == 125) {
             board2[i][j]=slash2;
        }else if (board[i][j] == 123) {
             board2[i][j]=slash1;
        }else if (board[i][j] == 32) {
             board2[i][j]=' ';
        }
        }
        
} 
int BackArr[70];
    int r,c,saveOne=1;
    int box1,box2;
    int dfsArr[row][col];
    int  undo = 0 , ind=0 ,redo = 0;
fclose(file);
clock_t start_time,end;
double cpu_time_used;
int minutes,seconds;
int total_saved_seconds = savedminutes * 60 + savedseconds;
if (mode==1)
{
    start_time = clock(); 
    while (moves!=(row/2)*((col/2)+1)+(col/2)*((row/2)+1)) {
        displayboard(board2,row,col);    //initial board
        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        int total_seconds= cpu_time_used + total_saved_seconds;
        minutes = (int)(total_seconds / 60);  
        seconds = (int)(total_seconds) % 60;
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
            free(board2[i]);
           }
           free(board2);
            return 0 ;    //exit 
        }
        if (r==0 && c==0)
        {
           if (undo>=1)
           {  
             delet(board2,BackArr,&ind);
             check(board2,row,col,score,currentPlayer);    //undo function 
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
            savegame(board2,row,col,score,currentPlayer,line1,line2,minutes,seconds,moves,mode,&saveOne);
            printf("\033[2J\033[1;1H");
            printf(green"game saved successefuly\n"rest);
        }
         int movetype = valid_move(board2,r,c,row,col);    //check if it is valid or not (if it is not it returns o)
        if (movetype!=0) {
            if (currentPlayer==1)
            {
                line1++;
            }
            else{line2++; }
            makemove(board2,r,c,movetype,currentPlayer);      //make the move on the board
           int play_agin = comp_squer(board2,currentPlayer,score,row,col,&box1,&box2); //check if the player completed a square
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
                nextbox(board2,movetype,r,c,&box1,&box2,row,col);
                if (box1!=0 && box2!=0)
                {
                    if (DFS(board2,row,col,box1,box2,dfsArr,&x))    //check if it exist a chain and complete it
                {
                    if (noTchain(row,col,dfsArr,board2))
                    {
                         chain(board2,row,col,dfsArr,currentPlayer,score,BackArr,&ind,&undo,&line1,&line2,&moves);
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
            {
                if(r==-2 && c==-2){
                }
                else{
                 printf(red"Invalid move! Try again.\n"rest);}
            }

        }
    }
    displayboard(board2,row,col);
 
    cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;   //calculate the time at this instant
     int total_seconds= cpu_time_used + total_saved_seconds;
        minutes = (int)(total_seconds / 60);  
        seconds = (int)(total_seconds) % 60;
        winner(score,minutes,seconds,row/2,col/2,1);    //calculate the score 
 for (int i = 0; i < row; i++)    //free the board
    {
        free(board2[i]);
    }
    free(board2);
  ask(row/2,col/2,1);
}
else if (mode==0)
{
         int NoPrint=0;
    start_time = clock(); 
    while (moves!=(row/2)*((col/2)+1)+(col/2)*((row/2)+1)) {
        int movetype;
        if (NoPrint==0){
        displayboard(board2,row,col);
        cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;
        int total_seconds= cpu_time_used + total_saved_seconds;
        minutes = (int)(total_seconds / 60);  
        seconds = (int)(total_seconds) % 60;
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
            free(board2[i]);
           }
           free(board2);
            return 0 ;
        }
         if (r==0 && c==0)
        {
           if (undo>=1)
           {  
             delet(board2,BackArr,&ind);
             check(board2,row,col,score,currentPlayer);
             moves--;
             line1--;
              
              redo++;
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
            savegame(board2,row,col,score,currentPlayer,line1,line2,minutes,seconds,moves,mode,&saveOne);
            printf("\033[2J\033[1;1H");
            printf(green"game saved successefuly\n"rest);
        }
        int movetype = valid_move(board2,r,c,row,col);
        if (movetype!=0) {
            makemove(board2,r,c,movetype,currentPlayer);
           int play_agin = comp_squer(board2,currentPlayer,score,row,col,&box1,&box2);
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
                if(r==-2 && c==-2){
                }
                else{
                 printf(red"Invalid move! Try again.\n"rest);}
            }
        }
    }
    if(currentPlayer!=1){
        printf(blue"Computer's turn:\n"rest );
        int po;
        po=checkcomplete_sq(board2,r,c,row,col);    
        if(po==1){           //he found a move that complete a square
            comp_squer(board2,2,score,row,col,&box1,&box2);
              NoPrint=1;
               moves++;
               line2++;
               
        }
        else{ 
            int movefound=0;
            for (int i = 0; i < row && !movefound; i++) {   //enter the loop until he found a valid move then break
                for (int j = 0; j < col && !movefound; j++) {
                    movetype=valid_move(board2,i,j,row,col);
                    if (movetype!=0){
                    makemove(board2,i,j,movetype,2);
                    movefound=1;
                    moves++;
                    line2++;
                    currentPlayer=1;
                    NoPrint=0;
                    comp_squer(board2,2,score,row,col,&box1,&box2);
                    break;}
            }  
        }
        } }}
displayboard(board2,row,col);
cpu_time_used = ((double)(clock() - start_time)) / CLOCKS_PER_SEC;   //calculate the time at this instant
int total_seconds= cpu_time_used + total_saved_seconds;
minutes = (int)(total_seconds / 60);  
seconds = (int)(total_seconds) % 60;
winnerc(score,minutes,seconds,row/2,col/2);
 for (int i = 0; i < row; i++)    //free the board
    {
        free(board2[i]);
    }
    free(board2);
    ask(row/2,col/2,2)  ;
}}

