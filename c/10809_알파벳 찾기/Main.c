#include <stdio.h>
#include <string.h>

int main(void){
    char alpha[26];
    for(int i = 0; i < 26; i++){
        alpha[i] = -1;
    }

    char str[101];
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++){
        if(alpha[str[i] - 'a'] == -1){
            alpha[str[i] - 'a'] = i;
        }
    }

    for(int i = 0; i < 26; i++){
        printf("%d ", alpha[i]);
    }
    return 0;
}