#include <stdio.h>
#include "color.h"
#define row 5
#define col 5

void displayboard(char board[row][col]){
    printf("  ");
    for (int i=0;i<col;i++) {
        printf(black"%d "rest,i);
    }
    printf("\n");
    for (int i=0;i<row;i++) {
        printf(black"%d "rest ,i);
        for (int j=0;j<col;j++) {
            if (board[i][j]=='.')
            {
                printf(white"%c "rest ,board[i][j]);
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
                printf(yellow"%c "rest ,board[i][j]);
            }
            else{
            printf("%c ",board[i][j]);
            }
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
int comp_squer (char board[row][col],int player,int arr[]){
    char winer ;
   
    
for (int i = 1; i < row; i=i+2)
{
    for (int j = 1; j < col; j=j+2)
    {
        if ((board[i][j-1]=='|')&& (board[i][j+1]=='|')&&(board[i-1][j]=='-')&&(board[i+1][j]=='-')&&(board[i][j]=='a'))
        {

          if (player==1)
         {
           board[i][j]='c';
            arr[1]++;
            comp_squer(board,player,arr);
            return 0;
         }
         else{
            board[i][j] = 'k';
             arr[2]++; 
             comp_squer(board,player,arr);
             return 0;
             }


           board[i][j]= winer;
           
        }
        
    }
    
}

return 1;


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
        printf(yellow"player 1 score : %d\n"rest blue"player 2 score : %d\n"rest ,score[1],score[2]);
        if (currentPlayer == 1)
        {
            printf(yellow"Player %d's turn:\n"rest , currentPlayer);
        }
        else
        {
             printf(blue"Player %d's turn:\n"rest , currentPlayer);
        }

        int r,c;
      
        printf(white"Enter row and column to place a line: "rest);
        scanf("%d %d", &r,&c);
        if (r== 5 && c==5)
        {
            return 0 ;
        }
        
        int movetype = valid_move(board,r,c);
        if (movetype!=0) {
            makemove(board,r,c,movetype);
           int play_agin = comp_squer(board,currentPlayer,score);
            if (play_agin==1)
            {
                currentPlayer=(currentPlayer==1)?2:1; // Switch to the next player
            }
            
           
            displayboard(board);
            moves++;
            
        } else {
            printf("Invalid move! Try again.\n");
        }
    }
    if (score[1]>score[2])
    {
       printf(blue"Player 1 is the winner with score %i\n"rest  ,score[1]);
    }
    else if (score[1]<score[2])
    {
         printf(blue"Player 2 is the winner with score %i\n"rest ,score[2]);
    }
    else
    {
        printf("The game is equal\n");
    }
    char winnerr[50];
    printf(white"The winner name in :"white);
    scanf("%s",&winnerr);
    return 0;

}


