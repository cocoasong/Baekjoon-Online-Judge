#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int num;
    scanf("%d", &num);
    char str[5];
    int numDigit[4];
    int cnt = 0;

    for(int i = 1; i <= num; i++){
        if((i >= 1) && (i <= 99)){
            cnt++;
        }
        else{
            sprintf(str, "%d", i);
            for(int j = 0; j < strlen(str); j++){
                numDigit[j] = str[j] - '0';
            }
            int base = numDigit[1] - numDigit[0];
            int j = 1;
            for(; j < strlen(str) - 1; j++){
                if(base != numDigit[j+1] - numDigit[j]){
                    break;
                }
            }
            if(j == strlen(str) - 1){
                cnt++;
            }
        }
    }

    printf("%d", cnt);
    return 0;
}