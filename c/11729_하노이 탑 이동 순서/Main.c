#include <stdio.h>
#include <math.h>

void towerOfHanoi(int n, int start, int end, int remain){
    if(n == 1){
        printf("%d %d\n", start, end);
    }
    else{
        towerOfHanoi(n - 1, start, remain, end);
        towerOfHanoi(1, start, end, remain);
        towerOfHanoi(n - 1, remain, end, start);
    }
}

int main(void){
    int N;
    scanf("%d", &N);

    int count = (int)(exp2(N) - 1);
    printf("%d\n", count);

    towerOfHanoi(N, 1, 3, 2);

    return 0;
}