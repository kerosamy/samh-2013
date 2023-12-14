#include<stdio.h>
#define red  "\033[1;31m"
#define black  "\033[1;30m"
#define green  "\033[1;32m"
#define yellow  "\033[1;33m"
#define cyan "\033[1;36m"
#define blue  "\033[1;34m"
#define white  "\033[1;37m"
#define rest  "\033[1;0m"
#include"start.h"
int menu1(){
char menu ; 

printf(yellow"Welcome to Dots and Boxes game \n"rest green"Start game \n"rest cyan"Load game \n"rest blue"Top 10 players \n"rest red"Exit \n"rest white"please choose :"rest);
scanf("%c",&menu);
switch (menu)
{
case 's':
    select1();
    break;
case 'l':

    break;
case 't':

    break;
case 'e':
    return 0 ;
    break;
default:
   printf(red"\nSorry we can not understand you please try agin\n"rest);
    menu1();
    break;
}
}
