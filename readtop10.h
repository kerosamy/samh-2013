#include <stdio.h>
int printleaderboard(){
    
    
    FILE *file;
    file = fopen("top10.txt", "r");
    if (file != NULL) {
        
        char c;
        while ((c=fgetc(file)) != EOF)
        putchar(c);
        fclose(file);}
         int i ;
        printf(red"enter (1) for lobby"rest);
        scanf("%i",&i);
       
        
        
            printf("\033[2J\033[1;1H");
        if (i==1)
        {

            return 0 ;
        }
        else{printleaderboard();}
        
        
        
}