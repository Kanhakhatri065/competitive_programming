#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    for(int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }

    return 0;
}