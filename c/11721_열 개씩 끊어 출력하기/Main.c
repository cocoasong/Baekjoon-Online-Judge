#include <stdio.h>

int main(){    
    int ch = getchar();
    int len = 1;
    while(ch != '\n'){
        putchar(ch);
        if(len == 10){
            putchar('\n');
            len = 1;
        }
        else{
            len++;
        }

        ch = getchar();
    }       
}