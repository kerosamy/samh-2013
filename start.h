#include <stdio.h>
#include "2x2game.h"
#include "color.h"
int select2(int i){
   int j ;
printf("\n///////////////////////////\n");
printf("///////////////////////////\n");
printf(yellow"please select the mode <3\n"rest);
printf(green"1-human Vs human \n"rest blue"2-human Vs computer\n"rest red"3-return to lobby\n"rest);
printf(white"your mode will be :"rest);
scanf("%i",&j);
switch (j)
{
case 1:
   maingame();
   break;
case 2:
   
   break;
case 3:
return 0 ;
break;
default:
printf(red"sorry we can not understand you please try agin"rest);
select2(i);
   break;
}
return 0 ;
}

int select1(){
 int i;


printf("\n///////////////////////////////////////\n");
printf("///////////////////////////////////////\n");
printf(yellow"please select the leve <3\n"rest);
printf(green"1-beginner 2x2 \n"rest blue"2-expert 5x5\n"rest red"3-return to lobby\n"rest white"your game will be :"rest );
scanf("%i",&i);

switch (i)
{ 
case 1 :
   
   select2(i);
   break;
case 2 :
   select2(i);
   break;
case 3:
     return 0 ;
     break;
default:
  
  printf(red"sorry we can not understand you please try agin"rest);
  select1();
   break;
}
}
