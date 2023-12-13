#include<stdio.h>
int main(){
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
   printf("Sorry we can not understand you please try agin");
    break;
}



    return 0;
}