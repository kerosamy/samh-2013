#include <stdio.h>
#include "color.h"
#define row 5
#define col 5

void displayboard(char board[row][col]){
    printf("  ");
    for (int i=0;i<col;i++) {
        printf("%d ",i);
    }
    printf("\n");
    for (int i=0;i<row;i++) {
        printf("%d ",i);
        for (int j=0;j<col;j++) {
            printf("%c ",board[i][j]);
        }
        printf("\n");}}
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
void makemove(char board[][col],int r,int c,int movetype) {
    if (movetype==1) { //horizontal line
        board[r][c] = '-';
    } else if (movetype == 2) { //vertical line
        board[r][c] = '|';
    }
}
void comp_squer (char board[row][col],int player,int arr[]){
    char winer ;
   
    if (player==1)
    {
        winer='c';
        
    }
    else{ winer = 'k'; }
for (int i = 1; i < row; i=i+2)
{
    for (int j = 1; j < col; j=j+2)
    {
        if ((board[i][j-1]=='|')&& (board[i][j+1]=='|')&&(board[i-1][j]=='-')&&(board[i+1][j]=='-')&&(board[i][j]=='a'))
        {

          if (player==1)
         {
            winer='c';
            arr[1]++;
         }
         else{
             winer = 'k';
             arr[2]++; 
             }


           board[i][j]= winer;
           
        }
        
    }
    
}
}
int maingame() {
    int score[3]={0,0,0};
    char abc [(col/2)*2];
    int k =0;
    for (int i = 0; i <=(col/2)*2 ; i++)//creat characters for emty squars
    {   
        
        
        abc[i]= 'a';
    }
    

    char board[row][col];
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            if ((i%2==0)&&(j%2==0)){
                board[i][j] = '.';
                }
                else if (i%2!=0 && j%2!=0)
                {
                    board[i][j]=abc[k];
                    k++;
                }
                else{
                board[i][j] = ' ';}}}
    displayboard(board);    //initial board

    int currentPlayer=1;
    int moves=0;

    while (moves !=12) {
        printf("player 1 score : %d\nplayer 2 score : %d\n",score[1],score[2]);
        printf("Player %d's turn:\n", currentPlayer);

        int r,c;
      
        printf("Enter row and column to place a line: ");
        scanf("%d %d", &r,&c);
        if (r== 5 && c==5)
        {
            return 0 ;
        }
        
        int movetype = valid_move(board,r,c);
        if (movetype!=0) {
            makemove(board,r,c,movetype);
            comp_squer(board,currentPlayer,score);
            displayboard(board);
            moves++;
            currentPlayer=(currentPlayer==1)?2:1; // Switch to the next player
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    return 0;
}
