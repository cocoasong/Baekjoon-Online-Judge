#include <stdio.h>
#include <string.h>

int main(void){
    char msg[501];
    gets(msg);

    while(strcmp(msg, "END") != 0){
        for(int i = strlen(msg) - 1; i >= 0; i--){
            printf("%c", msg[i]);
        }
        printf("\n");
        gets(msg);
    }
    return 0;
}