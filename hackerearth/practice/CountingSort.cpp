#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    int K = *max_element(arr, arr + size);

    int aux[K + 1] = {0};
    for(int i = 0;i < size;i++) {
        aux[arr[i]]++;
    }

    for(int i = 0;i <= K;i++) {
        if(aux[i] > 0) {
            cout << i << " " << aux[i] << endl;
        }
    }

    return 0;
}