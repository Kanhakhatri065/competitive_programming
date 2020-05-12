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

        int count = 1;
        for(int j = 0;j < size - 1;j++) {
            if(arr[j] >= arr[j + 1]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}