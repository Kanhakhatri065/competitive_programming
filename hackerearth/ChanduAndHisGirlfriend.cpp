#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        long long int arr[size];
        for(int j = 0;j < size;j++) {
            cin >> arr[j];
        }

        sort(arr, arr + size, greater<long long int>());

        for(int j = 0;j < size;j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}