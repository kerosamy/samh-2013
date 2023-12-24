#include<stdio.h>
#include "color.h"
#include"start.h"

int menu1(){
int menu ; 
int sin =1;
char star =4 ;

while (sin==1)
{
   printf(yellow"Welcome to Dots and Boxes game \n" rest green"1-Start game \n"rest cyan"2-Load game \n"rest blue"3-Top 10 players \n"rest red"4-Exit \n"rest white"please choose :"rest);
scanf("%i",&menu);
printf("\033[2J\033[1;1H");
switch (menu)
{
case 1 :
    select1();
    break;
case 2:

    break;
case 3 :

    break;
case 4 :
    sin = 0;
    return 0 ;
    break;
default:
   printf(red"\nSorry we can not understand you please try agin\n"rest);
    menu1();
    break;
}
}

   
}


    

