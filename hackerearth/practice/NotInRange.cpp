#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int size = 1000000;
    
    long long int arr[size];
    for(long long int i = 0;i < size;i++){
        arr[i] = i + 1;
    }

    int ranges;
    cin >> ranges;

    long long int left, right;
    for(int i = 0;i < ranges;i++){
        cin >> left >> right;

        for(long long int j = left - 1;j < right;j++){
            arr[j] = 0;
        }       
    }

    long long int total = 0;
    for(long long int i = 0;i < size;i++){
        total += arr[i];
    }

    cout << total << endl;

    return 0;
}