#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcases;
    cin >> testcases;

    for(int i = 0;i < testcases;i++){
        int size,min;
        cin >> size >> min;

        int arr[size];
        for(int j = 0;j < size;j++){
            cin >> arr[j];
        }

        sort(arr,arr + size);
        int output = 0;
        if(arr[0] < min){
            output = min - arr[0];
        }

        cout << output << endl;
    }
    return 0;
}