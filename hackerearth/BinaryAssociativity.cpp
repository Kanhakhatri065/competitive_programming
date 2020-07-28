#include <iostream>

using namespace std;

int table[4];

int op(int a, int b){
    if(a == 0 && b== 0){
        return table[0];
    } else if(a == 0 && b == 1){
        return table[1];
    } else if(a == 1 && b == 0){
        return table[2];
    } else {
        return table[3];
    }    
}

int main(){
    int testcases;
    cin >> testcases;


    for(int i = 0;i < testcases;i++){
        for(int j = 0;j < 4;j++){
            cin >> table[i];
        }

        int flag = 0;
        for(int j = 0;j < 2;j++){
            for(int k = 0;k < 2;k++){
                for(int l = 0;l < 2;l++){
                    if(op(op(j,k),l) != op(j,op(k,l))){
                        flag = 1;
                        break;
                    }
                }

                if(flag == 1){
                    break;
                }
            }

            if(flag == 1){
                break;
            }
        }

        if(flag == 1){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}