#include <bits/stdc++.h>

using namespace std;

int main(){
    int streets;
    cin >> streets;

    int buildings,rate;
    for(int i = 0;i < streets;i++){
        cin >> buildings >> rate;

        int arr[buildings];
        for(int j = 0;j < buildings;j++){
            cin >> arr[j];
        }

        int count = 0;
        int store = 0;
        for(int j = 0;j < buildings;j++){
            if(j == 0){
                store = arr[j];
                count++;
            }

            if(store < arr[j]){
                store = arr[j];
                count++;
            }
        }

        int earning = count * rate;
        cout << earning << endl;
    }
    return 0;
}