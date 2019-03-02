#include <stdio.h>
#include <string.h>

int main(void){
    char str[101];
    scanf("%s", str);

    char* token;
    token = strtok(str, "-");
    while(token != NULL){
        printf("%c", token[0]);
        token = strtok(NULL, "-");
    }
    return 0;
}