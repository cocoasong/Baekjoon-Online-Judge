#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int triMin(int a, int b, int c){
    int min = a;
    
    if(min > b){
        min = b;
        if(min > c){
            min = c;
        }
    }
    else{
        if(min > c){
            min = c;
        }
    }

    return min;

}

int ButtonDistance(int target, int base){
    if(target >= base){
        return target - base;
    }
    else{
        return base - target;
    }
}



int main(void){
    int targetChannel;
    char targetChannelStr[7];
    int N;      // Number of Not Possible Button
    int num;    // Temporary Variable to Store the number of button input
    int button[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int currentChannel = 100;
    int minNum, maxNum;

    scanf("%s", targetChannelStr);
    targetChannel = atoi(targetChannelStr);

    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num);
        button[num] = 0;
    }

    for(int i = 0; i < 10; i++){
        if(button[i]){
            minNum = i;
            break;
        }
    }
    for(int i = 9; i >= 0; i--){
        if(button[i]){
            maxNum = i;
            break;
        }
    }


    char high[7], low[7];   // closest higher(or lower) than targeChannel
    int baseNum, highNum, lowNum;
    int highDiff, lowDiff;
    int res;
    for(int i = 0; i < strlen(targetChannelStr); i++){
        highNum = lowNum = baseNum = targetChannelStr[i] - '0';
        if(button[baseNum]){
            high[i] = targetChannelStr[i];
            low[i] = targetChannelStr[i];
        }
        else{
            while(!(button[highNum] || button[lowNum])){
                if(highNum != 9){
                    highNum++;
                }
                if(lowNum != 0){
                    lowNum--;
                }
            }

            if(button[highNum] && button[lowNum]){
                high[i] = highNum + '0';
                low[i] = lowNum + '0';
                for(int j = i + 1; j < strlen(targetChannelStr); j++){
                    high[j] = minNum;
                    low[j] = maxNum;
                }
                high[strlen(targetChannelStr)] = '\0';
                low[strlen(targetChannelStr)] = '\0';
                break;
            }
            else if(button[highNum]){
                high[i] = highNum + '0';
                for(int j = i + 1; j < strlen(targetChannelStr); j++){
                    high[j] = minNum;
                }
                high[strlen(targetChannelStr)] = '\0';
                strcpy(low, high);
                break;
            }
            else if(button[lowNum]){
                low[i] = lowNum + '0';
                for(int j = i + 1; j < strlen(targetChannelStr); j++){
                    low[j] = maxNum;
                }
                low[strlen(targetChannelStr)] = '\0';
                strcpy(high, low);
                break;
            }
        }
    }

    res = triMin(strlen(high) + ButtonDistance(targetChannel, atoi(high)), strlen(low) + ButtonDistance(targetChannel, atoi(low)), ButtonDistance(targetChannel, 100));

    printf("%d\n", res);

    /*
    printf("%d %d\n", targetChannel, nMalfunction);
    for(int i = 0; i < nMalfunction; i++){
        printf("%d ", buttonMalfunction[i]);
    }
    printf("\n");
    */



    return 0;
}