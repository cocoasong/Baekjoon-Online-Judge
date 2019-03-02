#include <stdio.h>

int main(void){
    int testCase;
    scanf("%d", &testCase);

    int grade[1000];
    int student;
    double average;
    double sum;

    for(int i = 0; i < testCase; i++){
        scanf("%d", &student);
        sum = 0.0;
        for(int j = 0; j < student; j++){
            scanf("%d", &grade[j]);
            sum += grade[j];
        }
        average = sum / student;
        int cnt = 0;
        for(int j = 0; j < student; j++){
            if(average < grade[j]){
                cnt++;
            }
        }
        printf("%.3lf%%\n", (cnt / (double)student) * 100.0);
    }

    
    return 0;
}