#include<stdio.h>
#include "color.h"
#include"readtop10.h"
#include"start.h"
#include"load.h"


int menu1(){
int menu ; 
int sin =1;
char star =4 ;

while (sin==1)
{
   printf("\t\t\t\t\t\t" white "%c "rest  BYEL "Welcome to Dots and Boxes game" rest  white " %c\n\n\n"rest,star,star);
   printf( green"1-Start game \n\n"rest);
   printf(cyan"2-Load game \n\n"rest);
   printf( blue"3-Top 10 players \n\n"rest);
   printf( red"4-Exit \n\n"rest);
   printf(white"please choose :"rest);

scanf("%i",&menu);
printf("\033[2J\033[1;1H");
switch (menu)
{
case 1 :
    select1();
    break;
case 2:
    print ();
    break;
case 3 :
    printleaderboard();
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


    

