#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    long long int sum = 0;
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + size);


    long long int left_sum = 0;

    int flag = 0;

    for(int i = 0;i < size;i++) {
        sum -= arr[i];
        
        if(left_sum == sum) {
            flag = 1;
            break;
        }

        left_sum += arr[i];
    }

    if(flag == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}