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

        sort(arr, arr + size);

        long long int output = 2, counter = 2;
        for(int j = 0;j < size;j++) {
            if(arr[j] >= output) {
                output = 2 * (counter++);
            }
        }

        cout << output << endl;
    }

    return 0;
}