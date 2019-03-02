#include <stdio.h>

int main(void){
    int x, y;
    scanf("%d %d", &x, &y);
    char day[][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int n = 1;
    while(!(x == 1 && y == 1)){
        y--;
        if(y == 0){
            x--;
            if((x == 1) || (x == 3) || (x == 5) || (x == 7) || (x == 8) || (x == 10) || (x == 12)){
                y = 31;
            } 
            else if((x == 4) || (x == 6) || (x == 9) || (x == 11)){
                y = 30;
            }
            else if((x == 2)){
                y = 28;
            }
        }
        n++;
    }

    printf(day[n % 7]);
    return 0;
}