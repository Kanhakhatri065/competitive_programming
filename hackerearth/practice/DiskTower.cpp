#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    vector<long long int> store;

    for(long long int i = 0;i < size;i++) {
        if(i < size - 1) {
            if(arr[i] <= arr[i + 1]) {
                store.push_back(arr[i]);
            } else {
                store.push_back(arr[i]);
                for(long long int j = store.size() - 1;j >= 0;j--) {
                    cout << store[j] << " ";
                }
                store.clear();
            }
        } else {
            store.push_back(arr[i]);
            for(long long int j = store.size() - 1;j >= 0;j--) {
                cout << store[j] << " ";
            }
            store.clear();
        }
        cout << endl;
    }

    return 0;
}