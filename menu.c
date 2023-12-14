#include<stdio.h>
int menu1(){
char menu ; 
printf("Welcome to Dots and Boxes game \nStart game \nLoad game \nTop 10 players \nExit \nplease choose :");
scanf("%c",&menu);
switch (menu)
{
case 's':
    
    break;
case 'l':

    break;
case 't':

    break;
case 'e':
    return 0 ;
    break;
default:
   printf("\nSorry we can not understand you please try agin\n");
    menu1();
    break;
}
}
