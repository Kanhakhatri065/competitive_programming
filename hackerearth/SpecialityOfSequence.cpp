#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, k;
    cin >> size >> k;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    long long int sum = 0;
    for(int i = 0;i < size - k;i++) {
        sum += arr[i];
    }

    cout<< sum << endl;

    return 0;
}