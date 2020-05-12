#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int size;
    cin >> size;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    long long int count = 0;
    for(int i = 1;i < size;i++) {
        for(int j = 0;j < i;j++) {
            if(arr[j] > arr[i]) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}