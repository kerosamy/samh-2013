#include<stdio.h>
void nextbox(char **board,int movetype,int r,int c,int *p1,int *p2,int row ,int col){

if (movetype==1)
{
   if (board[r+1][c]=='a')
   {
    if (r+1<row)
    {
      *p1=r+1;
      *p2=c;
    }
    else{
    
     *p1=0;
     *p2=0;}
   }
   else if(board[r-1][c]=='a')
   {
     if (r-1>0)
     {
      *p1=r-1;
      *p2=c;
     }
     else{
    
     *p1=0;
     *p2=0;}
     
     
   }
   else{*p1=0;
     *p2=0;}
}
else
{
   if (board[r][c+1]=='a')
   {
     if (c+1<col)
     {
       *p1=r;
       *p2=c+1;
     }
     else
     {
       *p1=0;
       *p2=0;
     }
     
    
   }
   else if (board[r][c-1]=='a')
   {
     if (c-1>0)
     {
      *p1=r;
      *p2=c-1;
     }
     
      else
     {
       *p1=0;
       *p2=0;
     }
   }
    else{*p1=0;
     *p2=0;}

}







}