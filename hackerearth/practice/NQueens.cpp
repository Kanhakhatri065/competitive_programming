#include <bits/stdc++.h>

bool is_attacked(int x, int y, int board[][], int N){
    for(int i = 0;i < N;i++){
        if(board[i][x-1] == 1){
            return true;
        }
    }

    for(int i = 0;i < N;i++){
        if(board[y - 1][i] == 1){
            return true;
        }
    }

    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(i + j == x-1+y-1){
                if(board[i][j] == 1){
                    return true;
                }
            }

            if(i+j == x - y - 2){
                if(board[i][j] == 1){
                    return true;
                }
            }
        }
    }
    return false;
}

