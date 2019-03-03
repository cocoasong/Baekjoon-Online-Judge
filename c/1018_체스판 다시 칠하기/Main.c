#include <stdio.h>

char toggleChar(char ch){
    if(ch == 'B'){
        return 'W';
    }
    else return 'B';
}

int recolor(char chess[8][8], char startChar, int base){
    int cnt = 0;
    char currentChar = startChar;


    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(chess[i][j] != currentChar){
                cnt++;
            }

            if(cnt >= base){
                return base;
            }
            currentChar = toggleChar(currentChar);
        }
        currentChar = toggleChar(currentChar);
    }

    return cnt;
}

int main(void){
    char input[50][50];
    char temp[51];
    char chess[8][8];
    int row, col;

    scanf("%d %d ", &row, &col);

    for(int i = 0; i < row; i++){
        fgets(temp, 51,stdin);
        for(int j = 0; j < col; j++){
            input[i][j] = temp[j];
        }
    }

    int res = 8*8;
    for(int rowInput = 0; rowInput <= row - 8; rowInput++){
        for(int colInput = 0; colInput <= col - 8; colInput++){
            for(int rowChess = 0; rowChess < 8; rowChess++){
                for(int colChess = 0; colChess < 8; colChess++){
                    chess[rowChess][colChess] = input[rowInput+rowChess][colInput+colChess];
                }
            }
            res = recolor(chess, 'B', res);
            res = recolor(chess, 'W', res);
        }
    }

    printf("%d\n", res);

    return 0;
}