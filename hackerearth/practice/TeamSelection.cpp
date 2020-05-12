#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;

    long long int arr1[size];
    for(int i = 0;i < size;i++){
        cin >> arr1[i];
    }

    long long int arr2[size];
    for(int i = 0;i < size;i++){
        cin >> arr2[i];
    }

    long long int arr3[size];
    memset(arr3, 0, sizeof(arr3));

    long long int count = 0;

    for(int i = size - 1;i >= 0;i--){
        for(int j = i - 1;j >= 0;j--){
            if(arr1[i] > arr1[j]){
                arr3[i]++;
            }
        }
    }

    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            if(arr1[i] < arr2[j]){
                count += arr3[i];
            }
        }
    }

    cout << count << endl;
    
    return 0;
}