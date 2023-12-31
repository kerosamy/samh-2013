#include <stdio.h>
#include "hhgame2.h"
#include"computer.h"
#include "color.h"
int ask(int row,int col,int mode){

    int i ;
    printf(green"1-Play again\n\n"rest);
    printf(blue"2-lead board\n\n"rest);
    printf(red"3-return lobby\n\n"rest);
    printf(yellow"please select :"rest);
    scanf("%i",&i);
    printf("\033[2J\033[1;1H");
    switch (i)
    {
    case 1:
       if (mode==1)
       {
       if (maingame(row,col))
        {
         ask(row,col,1);
        }
       }
       if (mode==2)
       {
        if (maingamec(row,col))
        {
         ask(row,col,2);
        }
        
       }
        break;
    case 2:
         printf(red"\t\t\t\t\tTOP 10 PLAYERS\n\n"rest);
         printleaderboard();
        break;
    case 3:
        
        break;
    default:
        printf(red"We cant understand please try again!"rest);
        ask(row,col,mode);
        break;
    }
    }


int s ;
int select2(int c1,int c2){
   int j ;
   

printf(yellow"please select the mode <3\n\n"rest);
printf(green"1-human Vs human \n\n"rest blue"2-human Vs computer\n\n"rest  red"3-return to lobby\n\n"rest);
printf(white"your mode will be :"rest);
while(scanf("%d", &j) != 1) {
            printf("\033[2J\033[1;1H");
            printf(red "\nNOT VALID!!.Please enter a number.\n\n" rest);
            printf(yellow"please select the mode <3\n\n"rest);
            printf(green"1-human Vs human \n\n"rest blue"2-human Vs computer\n\n"rest  red"3-return to lobby\n\n"rest);
            printf(white"your mode will be :"rest);
            while (getchar() != '\n'); 
            continue;
        }
printf("\033[2J\033[1;1H");
switch (j)
{
case 1:
if ( maingame(c1,c2))
{
   ask(c1,c2,1);
}

  
   
   break;
case 2:
   if (maingamec(c1,c2))
   { 
      ask(c1,c2,2);
   }
   
   break;


case 3:
return 0 ;
break;
default:
printf(red"sorry we can not understand you please try agin"rest);
select2(c1,c2);
   break;
}
return 0 ;
}

int select1(){
 int i;

int k1,k2;

printf(yellow"please select the level <3\n\n"rest);
printf(green"1-beginner 2x2 \n\n"rest blue"2-expert 5x5\n\n"rest cyan"3-custom game\n\n"rest red"4-return to lobby\n\n"rest white"your game will be :"rest );
while(scanf("%d", &i) != 1) {
            printf("\033[2J\033[1;1H");
            printf(red "\nNOT VALID!!.Please enter a number.\n\n" rest);
            printf(yellow"please select the level <3\n\n"rest);
            printf(green"1-beginner 2x2 \n\n"rest blue"2-expert 5x5\n\n"rest cyan"3-custom game\n\n"rest red"4-return to lobby\n\n"rest white"your game will be :"rest );
            while (getchar() != '\n'); 
            continue;
        }
printf("\033[2J\033[1;1H");

switch (i)
{ 
case 1 :
   k1=2; k2=2;
   select2(k1,k2);
   break;
case 2 :
   k1=5; k2=5;
   select2(k1,k2);
   break;
case 3 :
   printf(white"please enter number of rows and column :"rest);
    while (scanf("%d %d", &k1,&k2)!=2){
            printf(red "\nNOT VALID!!.Please enter numbers.\n\n" rest);
            while (getchar() != '\n'); 
            continue;
        }
   printf("\033[2J\033[1;1H");
   select2(k1,k2);
break;
case 4:
     return 0 ;
     break;
default: 
  printf(red"sorry we can not understand you please try agin"rest);
  select1();
   break;
}
}
