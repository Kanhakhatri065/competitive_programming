#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        long long int arr[size];
        for(long long int j = 0;j < size;j++) {
            cin >> arr[j];
        }

        long long int K = *max_element(arr, arr + size);

        long long int aux_size = K + 1;

        long long int aux_arr[aux_size];
        for(long long int j = 0;j < aux_size;j++) {
            aux_arr[j] = 0;
        }

        for(long long int j = 0;j < size;j++) {
            aux_arr[arr[j]]++;
        }

        long long int count = 0;
        for(long long int j = 0;j < aux_size;j++) {
            count+= aux_arr[j];
            count += ((aux_arr[j] * (aux_arr[j] - 1)) / 2);
        }

        cout << count << endl;
    }

    return 0;
}