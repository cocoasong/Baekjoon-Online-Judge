#include <stdio.h>

int main(){
    int totalCase;
    int base;

    scanf("%d %d", &totalCase, &base);

    int num;
    for(int i = 0; i < totalCase; i++){
        scanf("%d", &num);
        if(num < base){
            printf("%d ", num);
        }
    }
}