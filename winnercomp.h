#include<stdio.h>
#include "color.h"

void winnerc (int score [],int minutes,int seconds,int row ,int col){
char winnerr[50];

if (score[1]>score[2])
    {
      winner(score,minutes,seconds,row,col,2);
    }
    else if (score[1]<score[2])
    {
         int i ;
       while (i!=1)
       {
         printf(blue"Computer is the winner with score %i\n"rest ,score[2]);
         printf(green"Total time taken: %d minutes %d seconds\n"rest, minutes, seconds);
          printf(red"To exit enter (1) :"rest);
          if (scanf("%d", &i) != 1) {
            printf(red "\nNOT VALID!!.Please enter a number.\n\n" rest);
            while (getchar() != '\n'); 
            continue;
        }
          printf("\033[2J\033[1;1H");

          }
       
    }
    else
    {
       int i ;
       while (i!=1)
       {
        printf(white"The game is equal\n"rest);
        printf(green"Total time taken: %d minutes %d seconds\n"rest, minutes, seconds);
        printf(red"To exit enter (1) :"rest);
        if (scanf("%d", &i) != 1) {
            printf(red "\nNOT VALID!!.Please enter a number.\n\n" rest);
            while (getchar() != '\n'); 
            continue;
        }
        printf("\033[2J\033[1;1H");

       }
       
        
        
    }}