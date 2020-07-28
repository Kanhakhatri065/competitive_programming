#include <bits/stdc++.h>

using namespace std;

int main(){
    int size;
    cin >> size;

    int arr[size];
    for(int i= 0;i < size;i++){
        cin >> arr[i];
    }

    sort(arr, arr + size);

    int max_count = 1, res = arr[0], current_count = 1;
    for(int i = i;i < size;i++){
        if(arr[i] == arr[i - 1]){
            current_count++;
        } else {
            if(current_count > max_count){
                max_count = current_count;
                res = arr[i - 1];
            }
            current_count = 1;
        }
    }

    if(current_count > max_count){
        max_count = current_count;
        res = arr[size - 1];
    }

    cout << res << endl;
    return 0;
}