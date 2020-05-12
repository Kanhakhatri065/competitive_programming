#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    int size, rotation;
    int temp;
    for(int i = 0;i < testcases;i++){
        cin >> size >> rotation;

        int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        for(int j = 0;j < rotation;j++){
            temp = arr[size - 1];
            
            for(int k = size - 2;k >=0;k--){
                arr[k+1] = arr[k];
            }

            arr[0] = temp;
        }

        for(int j = 0;j < size;j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}