#include <iostream>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int questions, tags;
        cin >> questions >> tags;

        int arr[questions][tags];
        for(int j = 0;j < questions;j++){
            for(int k = 0;k < tags;k++){
                cin >> arr[j][k];
            }
        }

        int possibilities = 0;
        int count = 0;
        for(int j = 0;j < questions;j++){
            count = 0;
            for(int k = 0;k < questions;k++){
                if(k == j){
                    continue;
                }
                
                for(int l = 0;l < tags;l++){
                    if(arr[j][l] | arr[k][l] == 1){
                        count++;
                    }
                }
                if(count == (tags - 1)){
                    possibilities++;
                }
            }
        }

        cout << (possibilities + 1) << endl;

    }
    return 0;
}