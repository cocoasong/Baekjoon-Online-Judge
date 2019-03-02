#include <stdio.h>
#include <string.h>

int main(void){
    int testCase;
    scanf("%d", &testCase);

    char str[21];
    int repeat;
    for(int i = 0; i < testCase; i++){
        scanf("%d", &repeat);
        scanf("%s", str);
        for(int j = 0; j < strlen(str); j++){
            for(int k = 0; k < repeat; k++){
                printf("%c", str[j]);
            }
        }
        printf("\n");

    }
    return 0;
}