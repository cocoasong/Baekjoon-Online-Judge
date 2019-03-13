#include <stdio.h>

int hasTripleSix(int num){
    int countSix = 0;

    while(num != 0){
        if((num % 10) == 6){
            countSix++;
        }
        else{
            countSix = 0;
        }

        if(countSix == 3){
            break;
        }
        
        num /= 10;
    }

    
    return (countSix == 3);
}

int main(void){
    int N;
    int idx = 1;
    int res = 666;

    scanf("%d", &N);

    while(idx <= N){
        if(hasTripleSix(res)){
            idx++;
        }
        res++;
    }

    printf("%d\n", res - 1);
    return 0;
}