#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    char board[4][4];
    for(int i = 0;i < testcases;i++){
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 4;k++){
                cin >> board[j][k];
            }
        }

        int flag = 0;
        for(int j = 0;j < 4;j++){
            for(int k = 0;k < 4;k++){
                if(board[j][k] == 'x'){
                    // horizontal
                    if((k + 1 < 4) && (k + 2 < 4)){
                        if(board[j][k + 1] == 'x' && board[j][k + 2] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j][k + 1] == '.' && board[j][k + 2] == 'x'){
                            flag = 1;
                            break;
                        }
                    }
                    
                    if((k - 1 >= 0) && (k - 2 >= 0)){
                        if(board[j][k - 1] == 'x' && board[j][k - 2] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j][k - 1] == '.' && board[j][k - 2] == 'x'){
                            flag = 1;
                            break;
                        }
                    }

                    if((k - 1 >= 0) && (k + 1 < 4)){
                        if(board[j][k + 1] == 'x' && board[j][k - 1] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j][k + 1] == '.' && board[j][k - 1] == 'x'){
                            flag = 1;
                            break;
                        }
                    }
                    // vertical
                    if((j + 1 < 4) && (j + 2 < 4)){
                        if(board[j + 1][k] == 'x' && board[j + 2][k] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j + 1][k] == '.' && board[j + 2][k] == 'x'){
                            flag = 1;
                            break;
                        }
                    }
                    
                    if((j - 1 >= 0) && (j - 2 >= 0)){
                        if(board[j - 1][k] == 'x' && board[j - 2][k] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j - 1][k] == '.' && board[j - 2][k] == 'x'){
                            flag = 1;
                            break;
                        }
                    }

                    if((k - 1 >= 0) && (k + 1 < 4)){
                        if(board[j + 1][k] == 'x' && board[j - 1][k] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j + 1][k] == '.' && board[j - 1][k] == 'x'){
                            flag = 1;
                            break;
                        }
                    }
                    //diagonal
                    if(((j + 1 < 4) && (k + 1 < 4)) && ((j + 2 < 4) && (k + 2 < 4))){
                        if(board[j + 1][k + 1] == 'x' && board[j + 2][k + 2] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j + 1][k + 1] == '.' && board[j + 2][k  + 2] == 'x'){
                            flag = 1;
                            break;
                        }
                    }

                    if(((j - 1 >= 0) && (k - 1 >= 0)) && ((j - 2 >= 0) && (k - 2 >= 0))){
                        if(board[j - 1][k - 1] == 'x' && board[j - 2][k - 2] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j - 1][k - 1] == '.' && board[j - 2][k -2] == 'x'){
                            flag = 1;
                            break;
                        }
                    }

                    if(((j - 1 >= 0) && (k - 1 >= 0)) && ((j + 1 < 4) && (k + 1 < 4))){
                        if(board[j - 1][k - 1] == 'x' && board[j + 1][k + 1] == '.'){
                            flag = 1;
                            break;
                        } else if(board[j - 1][k - 1] == '.' && board[j + 1][k + 1] == 'x'){
                            flag = 1;
                            break;
                        }
                    }
                } 
                if(flag == 1){
                    break;
                }  
            }
        }

        if(flag == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}