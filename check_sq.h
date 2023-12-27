#include<stdio.h>
int comp_squer (char **board,int player,int arr[],int row,int col,int* p1,int* p2){
   
   
for (int i = 1; i < row; i=i+2)
{
    for (int j = 1; j < col; j=j+2)
    {
        if ((board[i][j-1]!=' ')&& (board[i][j+1]!=' ')&&(board[i-1][j]!=' ')&&(board[i+1][j]!= ' ')&&(board[i][j]=='a'))
        {
          *p1=i;*p2=j;

          if (player==1)
         {
            board[i][j]='c';
            arr[1]++;
            comp_squer(board,player,arr,row,col,p1,p2);      //if it complete a square score ++ for the player
            return 0;
         }
         else{
            board[i][j] = 'k';
             arr[2]++; 
             comp_squer(board,player,arr,row,col,p1,p2);
             return 0;
             }
           
        }
        
    }
    
}
return 1;
}