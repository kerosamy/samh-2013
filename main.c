#include <stdio.h>
#include <stdlib.h>
#define r 4
#define c 4
void printboard(char board[r][c]){
 for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
                if(i==0||j==0)
                printf (" ");
           else printf("%c ", board[i][j]); }
        printf("\n");}}
int main()
{
  char board[r][c];
   for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            board[i][j] = '.';}}
 printf ("Initial board:");
 printf("\n");
 printboard(board);
 return 0;}

