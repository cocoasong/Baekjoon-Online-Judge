#include <stdio.h>

int main(){
    int num[3];

    for(int i = 0; i < 3; i++){
        scanf("%d", &num[i]);
    }

    for(int i = 1; i < 3; i++){
        for(int j = i; j >= 1; j--){
            if(num[j] < num[j - 1]){
                int temp = num[j];
                num[j] = num[j - 1];
                num[j - 1] = temp; 
            }
        }
    }

    printf("%d", num[1]);
}
