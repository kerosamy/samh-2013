#include<stdio.h>
#include <stdbool.h>
void zeroArr (int col,int row,int arr[row][col]){
for (int i = 0; i < row; i++)
{
    for (int j = 0; j < col; j++)
   {
      arr[i][j]=0;
   }
}
}
int DFS (char **board,int row ,int col,int boxnumber1,int boxnumber2,int arr[row][col],int *x){
 int shifts[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  
if (arr[boxnumber1][boxnumber2]==1)
{
   
    return (*x&1) ;
}
 if (boxnumber1>=row||boxnumber2>=col||boxnumber1<0||boxnumber2<0)
{
    return (*x&0) ;
}
else{
arr[boxnumber1][boxnumber2]=1;
       for (int shift = 0; shift < 4; shift++) {
                if (board[boxnumber1 + shifts[shift][0]][boxnumber2 + shifts[shift][1]] == ' ') {
                    
                 if (shift==0)
                 {
                    if (arr[boxnumber1][boxnumber2+2]==0)
                    {
                      if(!*x){return 0 ;}
                      
                      *x=*x&DFS(board,row,col,boxnumber1,boxnumber2+2,arr,x);
                    }
                    
                 }
                 else if (shift==1)
                 {
                     if (arr[boxnumber1+2][boxnumber2]==0)
                    {
                       if(!*x){return 0 ;}
                     *x=*x&DFS(board,row,col,boxnumber1+2,boxnumber2,arr,x);
                    }
                 }
                 else if (shift==2)
                 {
                     if (arr[boxnumber1][boxnumber2-2]==0)
                    {
                       if(!*x){return 0 ;}
                     *x=*x&DFS(board,row,col,boxnumber1,boxnumber2-2,arr,x);
                    }
                 }
                 else if (shift==3)
                 {
                    if (arr[boxnumber1-2][boxnumber2]==0)
                    {
                       if(!*x){return 0 ;}
                     *x=*x&DFS(board,row,col,boxnumber1-2,boxnumber2,arr,x);
                    }
                 }
               }
             }
 return *x ;
}   
}