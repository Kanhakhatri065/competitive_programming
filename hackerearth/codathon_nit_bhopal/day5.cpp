#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;


    for(int i = 0;i < testcases;i++){
        int total_coins;
        cin >> total_coins;

        int chance = 0;
        int x = 0;
        
        int j = 1;
        while(total_coins != 0){
            if((j >= 1 && j<= total_coins) && (j & total_coins == 0)){
                total_coins -= j;
                j = 0;
                chance++;
            } 

            if((j == total_coins) && (j & total_coins != 0)){
                break;
            }
            j++;
        }

        if((chance == 0) || (chance % 2 == 0)){
            cout << "Pranshu" << endl;
        }

        if(chance % 2 == 1){
            cout << "Jatin" << endl;
        }
    }

    return 0;
}