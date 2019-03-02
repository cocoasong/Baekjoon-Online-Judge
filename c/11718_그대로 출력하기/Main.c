#include <stdio.h>

int main(){
    int ch = getchar();
    while(ch != EOF){
        putchar(ch);
        ch = getchar();
    }
}