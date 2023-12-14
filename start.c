#include <stdio.h>
#define red  "\033[1;31m"
#define black  "\033[1;30m"
#define green  "\033[1;32m"
#define yellow  "\033[1;33m"
#define cyan "\033[1;36m"
#define blue  "\033[1;34m"
#define white  "\033[1;37m"
#define rest  "\033[1;0m"


int select1(){
 int i;


printf("\n///////////////////////////////////////\n");
printf("///////////////////////////////////////\n");
printf(yellow"please select the leve <3\n"rest);
printf(green"1-beginner 2x2 \n"rest red"2-expert 5x5\n"rest white"your game will be :"rest);
scanf("%li",&i);

switch (i)
{
case 1 :
   
   break;
case 2 :
   
   break;
default:
  
  printf(red"sorry we can not understand you please try agin"rest);
  select1();
   break;
}
}
