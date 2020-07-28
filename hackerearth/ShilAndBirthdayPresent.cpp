#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    long long int K = *max_element(arr, arr + size);

    long long int aux_arr[K + 1] = {0};
    for(long long int i = 0;i < size;i++) {
        aux_arr[arr[i]]++;
    }

    long long int count = 0;
    for(long long int i = 0;i < K + 1;i++) {
        if(aux_arr[i] > 0) {
            count++;
        }
    }

    count = (count * (count - 1)) / 2;

    cout << count << endl;

    return 0;
}