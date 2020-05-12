#include <bits/stdc++.h>

using namespace std;

int main(){
    int size, lower, upper;
    cin >> size >> lower >> upper;

    int arr[size];
    for(int i = 0;i < size;i++){
        cin >> arr[i];
    }
    int flag = 0;
    for(int i = 0;i < size;i++){
        if(arr[i] >= lower && arr[i] <= upper){
            continue;
        } else {
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}