#include <stdio.h>
#include "color.h"
int printleaderboard(){
    
    
    FILE *file;
    file = fopen("top10.txt", "r");
    if (file != NULL) {
        
        char c[100];
        int nofline=1;
        while (fgets(c, sizeof(c), file) != NULL){
             printf(green"%d.%s"rest,nofline,c);
             printf("\n");
             nofline++;
        }
       
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