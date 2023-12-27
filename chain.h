#include<stdio.h>
int noTchain (int row,int col , int arr[row][col]){
    for (int i = 1; i < row-1; i=i+2)
    {
        for (int j =1; j < col-1; j=j+2)
        {
            if (arr[i][j]+arr[i][j+2]+arr[i+2][j]+arr[i+2][j+2]==4)
            {
               return 0 ;
            }
            
        }
        
    }
 return 1;   
}
void chain (char **board , int row ,int col , int arr[row][col],int player,int score[],int backarr[],int *inx,int *undo,int *m1,int *m2,int*moves){
int shifts[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int dash = 196;int dash1 = 195;int dash2 = 197;int slash1 = 123;int slash2 = 125;

if (player==1)
{
    for (int i = 1; i < row; i=i+2)
{
    for (int j = 1; j < col; j=j+2)
    {
        if (arr[i][j]==1)
        {  
            for (int shift = 0; shift < 4; shift++)
            {
               if (board[i + shifts[shift][0]][j + shifts[shift][1]] == ' ')
               {
                  if (shift==0||shift==2)
                  {
                    board[i + shifts[shift][0]][j + shifts[shift][1]]=slash1;
                  }
                  else
                  {
                    board[i + shifts[shift][0]][j + shifts[shift][1]]=dash1;
                  }
                  *undo=*undo+1;
                   backarr[*inx]=(i+shifts[shift][0]);
                   backarr[*inx+1]=(j+shifts[shift][1]);
                   *inx=*inx+2;
                   *m1=*m1+1;
                     *moves=*moves+1;
               }
            }
             

            board[i][j]='c';
            score[1]++;
        }
        
    }
    
}
}
else
{
     for (int i = 1; i < row; i=i+2)
{
    for (int j = 1; j < col; j=j+2)
    {
        if (arr[i][j]==1)
        {  
            for (int shift = 0; shift < 4; shift++)
            {
               if (board[i + shifts[shift][0]][j + shifts[shift][1]] == ' ')
               {
                  if (shift==0||shift==2)
                  {
                    board[i + shifts[shift][0]][j + shifts[shift][1]]=slash2;
                  }
                  else
                  {
                    board[i + shifts[shift][0]][j + shifts[shift][1]]=dash2;
                  }
                  *undo=*undo+1;
                   backarr[*inx]=i+shifts[shift][0];
                   backarr[*inx+1]=j+shifts[shift][1];
                   *inx=*inx+2;
                    *m2=*m2+1;
                    *moves=*moves+1;
               }
            }
            board[i][j]='k';
            score[2]++;
        }
        
    }
    
}
}
}