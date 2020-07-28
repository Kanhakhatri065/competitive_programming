#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;
    
    int size;
    for(int i = 0;i < testcases;i++){
        cin >> size;

        unsigned long long int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        for(int j = 0;j < size;j++){
            if(arr[j] == 0){
                continue;
            }

            for(int k = 0;k < size;k++){
                if(j == k){
                    continue;
                }

                if(arr[k] == arr[j]){
                    arr[j] = arr[k] = 0;
                    break;
                }
            }
        }

        int flag = 0;
        unsigned long long int output = 0;
        for(int j = 0;j < size;j++){
            if(arr[j] != 0){
                output = arr[j];
                break;
            }

            if(j == size - 1){
                flag = 1;
            }
        }

        if(flag == 1){
            cout << "-1" << endl;
        } else {
            cout << output << endl;
        }
    }
    return 0;
}