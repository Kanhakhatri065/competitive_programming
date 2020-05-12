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

        vector<long long int> operation;
        long long int temp;
        for(int j = 0;j < size;j++) {
            temp = (arr[j] & arr[j + 1]) ^ (arr[j] | arr[j + 1]);
            operation.push_back(temp);
        }

        sort(operation.begin(), operation.end());

        cout << operation[0] << endl;
    }

    return 0;
}