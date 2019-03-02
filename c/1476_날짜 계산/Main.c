#include <stdio.h>

int main(){
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    int year = 1;

    while(!(E == 1 && S == 1 && M == 1)){
        year++;
        E--;
        S--;
        M--;
        if(E == 0){
            E = 15;
        }
        if(S == 0){
            S = 28;
        }
        if(M == 0){
            M = 19;
        }
    }
    printf("%d", year);
}