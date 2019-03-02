#include <stdio.h>

int main(){
    int weight;
    scanf("%d", &weight);

    int res = -1;
    int trial = weight / 5;
    for(int i = trial; i >= 0; i--){
        if((weight - (i * 5)) % 3 == 0){
            res = i + (weight - (i * 5)) / 3;
            break;
        }
    }

    printf("%d", res);
}