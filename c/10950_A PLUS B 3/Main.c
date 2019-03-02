#include <stdio.h>

int main(){
    int totalCase;
    scanf("%d", &totalCase);
    
    int a;
    int b;

    for(int i = 0; i < totalCase; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }
}