#include<stdio.h>


void delet (char **board,int arr[],int *indx )
{
  
   *indx=*indx-2;
   board[arr[*indx]][arr[*indx+1]]=' ';
   
   
}
void check (char **board,int row ,int col,int arr[],int player){
    
for (int i = 1; i < row; i=i+2)
{
    for (int j = 1; j < col; j=j+2)
    {  
        
        int count =0;
        if (board[i][j]!='a')
        {
            if (board[i+1][j]!=' ')
            {
                count++;
            }
             if (board[i-1][j]!=' ' )
            {
                count++;
            }
            if (board[i][j+1]!=' ')
            {
                count++;
            }
             if (board[i][j-1]!=' ' )
            {
                count++;
            }
            if (count<4)
            {
                if (board[i][j]=='c')
                         {
                         arr[1]--;
                         }
                         else
                         {
                         arr[2]--;  
                         }
                 board[i][j]='a';
                
            }
            
            
        }
        
    }
    
}




}