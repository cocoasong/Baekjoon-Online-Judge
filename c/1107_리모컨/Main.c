#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* DeleteZero(char* num){
    char temp[8] = {'0'};
    char* res;

    int idx = 0;
    while(num[idx] == '0'){
        idx++;
    }

    int resIdx = 0;
    if(idx != strlen(num)){
        for(int i = idx; i < strlen(num); i++){
            temp[resIdx] = num[i];
            resIdx++; 
        }

        temp[resIdx] = '\0';
    }

    res = temp;
    return res;
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

    
    //printf("%d %d\n", targetChannel, N);
    //for(int i = 0; i < 10; i++){
    //    printf("%d ", button[i]);
    //}
    //printf("\n");
    //printf("MAX: %d\nMIN: %d\n", maxNum, minNum);
    
    
    char sameHigh[8];
    char sameLow[8];
    char bigLow[8];
    char smallHigh[8];

    int res = ButtonDistance(targetChannel, 100);
    int baseNum, higherBaseNum, lowerBaseNum;

    if(N != 10){
        //CASE 1: Same Digit
        for(int i = 0; i < strlen(targetChannelStr); i++){
            baseNum = higherBaseNum = lowerBaseNum = targetChannelStr[i] - '0';
            if(button[baseNum]){
                sameHigh[i] = targetChannelStr[i];
                sameLow[i] = targetChannelStr[i];
            }        
            else{
                while(!button[higherBaseNum] || !button[lowerBaseNum]){
                    if(!button[higherBaseNum]){
                        if(higherBaseNum != 9){
                            higherBaseNum++;
                        }
                        else if(higherBaseNum == 9){
                            if(i != 0){
                                sameHigh[i - 1]++;
                                while(!button[sameHigh[i - 1] - '0']){
                                    sameHigh[i - 1]++;
                                }
                                higherBaseNum = minNum;
                            }
                            else{
                                higherBaseNum = maxNum;
                            }
                        }
                    }

                    if(!button[lowerBaseNum]){
                        if(lowerBaseNum != 0){
                            lowerBaseNum--;
                        }
                        else if(lowerBaseNum == 0){
                            if(i != 0){
                                sameLow[i - 1]--;
                                while(!button[sameLow[i - 1] - '0']){
                                    sameLow[i - 1]--;
                                }
                                lowerBaseNum = maxNum;
                            }
                            else{
                                lowerBaseNum = minNum;
                            }
                        }
                    }                    
                }
                sameHigh[i] = higherBaseNum + '0';
                sameLow[i] = lowerBaseNum + '0';

                for(int j = i + 1; j < strlen(targetChannelStr); j++){
                    sameHigh[j] = minNum + '0';
                    sameLow[j] = maxNum + '0';
                }

                break;
            }
        }
        sameHigh[strlen(targetChannelStr)] = '\0';
        sameLow[strlen(targetChannelStr)] = '\0';

        if(sameHigh[0] == '0'){
            strcpy(sameHigh, DeleteZero(sameHigh));
        }
        if(sameLow[0] == '0'){
            strcpy(sameLow, DeleteZero(sameLow));
        }

        //CASE 2: Big Digit
        for(int i = 0; i < strlen(targetChannelStr) + 1; i++){
            bigLow[i] = minNum + '0';
            bigLow[strlen(targetChannelStr) + 1] = '\0';
        }

        //CASE 3: Small Digit
        if(strlen(targetChannelStr) != 1){
            for(int i = 0; i < strlen(targetChannelStr) - 1; i++){
                smallHigh[i] = maxNum + '0';
            }
            smallHigh[strlen(targetChannelStr) - 1] = '\0';
        }
        else{
            strcpy(smallHigh, sameLow);
        }

    }
    else{
        strcpy(sameHigh, "100");
        strcpy(sameLow, "100");
        strcpy(bigLow, "100");
        strcpy(smallHigh, "100");
    }


    if(maxNum == 0){
        strcpy(bigLow, DeleteZero(bigLow));
        strcpy(smallHigh, DeleteZero(smallHigh));
    }
    else if(minNum == 0){
        baseNum = higherBaseNum = minNum;
        higherBaseNum++;
        while(!button[higherBaseNum]){
            if(higherBaseNum != 9){
                higherBaseNum++;
            }
            else{
                higherBaseNum = maxNum;
            }
        }
        bigLow[0] = higherBaseNum + '0';
    }

    if(res > strlen(sameHigh) + ButtonDistance(targetChannel, atoi(sameHigh))){
        res = strlen(sameHigh) + ButtonDistance(targetChannel, atoi(sameHigh));
    }
    if(res > strlen(sameLow) + ButtonDistance(targetChannel, atoi(sameLow))){
        res = strlen(sameLow) + ButtonDistance(targetChannel, atoi(sameLow));
    }
    if(res > strlen(bigLow) + ButtonDistance(targetChannel, atoi(bigLow))){
        res = strlen(bigLow) + ButtonDistance(targetChannel, atoi(bigLow));
    }
    if(res > strlen(smallHigh) + ButtonDistance(targetChannel, atoi(smallHigh))){
        res = strlen(smallHigh) + ButtonDistance(targetChannel, atoi(smallHigh));
    }

    //printf("SAME HIGH:%s\nSAME LOW:%s\nBIG LOW:%s\nSMALL HIGH:%s\n", sameHigh, sameLow, bigLow, smallHigh);
    printf("%d\n", res);
    return 0;
}