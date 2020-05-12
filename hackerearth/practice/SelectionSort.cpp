#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, iterations;
    cin >> size >> iterations;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    int min_idx;
    int count = 0;
    for(int i = 0;i < size;i++) {
        if(count == iterations) {
            break;
        }

        min_idx = i;
        for(int j = i + 1;j < size;j++) {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        count++;
    }

    for(int i = 0;i < size;i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}