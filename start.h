#include <stdio.h>
#include "hhgame2.h"
#include"computer.h"
#include "color.h"

int s ;
int select2(int c1,int c2){
   int j ;
   
printf("\n///////////////////////////\n");
printf("///////////////////////////\n");
printf(yellow"please select the mode <3\n"rest);
printf(green"1-human Vs human \n"rest blue"2-human Vs computer\n"rest  red"3-return to lobby\n"rest);
printf(white"your mode will be :"rest);
scanf("%i",&j);
printf("\033[2J\033[1;1H");
switch (j)
{
case 1:
   maingame(c1,c2);
   break;
case 2:
   maingamec(c1,c2);
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
printf("\n///////////////////////////////////////\n");
printf("///////////////////////////////////////\n");
printf(yellow"please select the leve <3\n"rest);
printf(green"1-beginner 2x2 \n"rest blue"2-expert 5x5\n"rest cyan"3-custom game\n"rest red"4-return to lobby\n"rest white"your game will be :"rest );
scanf("%i",&i);
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
   scanf("%i %i",&k1,&k2);
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
