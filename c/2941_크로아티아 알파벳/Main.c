#include <stdio.h>
#include <string.h>

int main(void){
    char str[101];
    int i = 0;
    int cnt = 0;
    
    scanf("%s", str);
    while(i < strlen(str)){
        if(str[i] == 'c' && str[i+1] == '='){
                i += 2;
                cnt++;
        }
        else if(str[i] == 'c' && str[i+1] == '-'){
                i += 2;
                cnt++;
        }
        else if(str[i] == 'd' && str[i+1] == 'z' && str[i+2] == '='){
                i += 3;
                cnt++;
        }
        else if(str[i] == 'd' && str[i+1] == '-'){
                i += 2;
                cnt++;
        }
        else if(str[i] == 'd' && str[i+1] == '-'){
                i += 2;
                cnt++;
        }
        else if(str[i] == 'l' && str[i+1] == 'j'){
            i += 2;
            cnt++;
        }
        else if(str[i] == 'n' && str[i+1] == 'j'){
            i += 2;
            cnt++;
        }
        else if(str[i] == 's' && str[i+1] == '='){
            i += 2;
            cnt++;
        }
        else if(str[i] == 'z' && str[i+1] == '='){
            i += 2;
            cnt++;
        }
        else{
            i++;
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}