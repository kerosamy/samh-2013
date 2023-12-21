#include<stdio.h>
#include "color.h"
void winner (int score []){
char winnerr[50];
if (score[1]>score[2])
    {
       printf(yellow"Player 1 is the winner with score %i \n"rest  ,score[1]);
        printf(white"The winner name in :"white);
        scanf("%s",&winnerr);
    }
    else if (score[1]<score[2])
    {
         printf(blue"Player 2 is the winner with score %i\n"rest ,score[2]);
          printf(white"The winner name in :"white);
          scanf("%s",&winnerr);
    }
    else
    {
        printf("The game is equal\n");
    }
    
    



}