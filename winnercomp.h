#include<stdio.h>
#include "color.h"

void winnerc (int score []){
char winnerr[50];

if (score[1]>score[2])
    {
      winner(score);
    }
    else if (score[1]<score[2])
    {
         printf(blue"Player 2 is the winner with score %i\n"rest ,score[2]);
          printf(red"Computer wins\n"rest);
    }
    else
    {
        printf("The game is equal\n");
    }}