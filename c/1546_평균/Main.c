#include <stdio.h>

int main(void){
    int N;
    scanf("%d", &N);

    int grade[1000];

    int max = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &grade[i]);
        if(max < grade[i]){
            max = grade[i];
        }
    }

    double sum = 0.0;
    for(int i = 0; i < N; i++){
        sum += ((double)grade[i]/(double)max) * 100.0;
    }

    printf("%lf", sum / N);

    return 0;
}