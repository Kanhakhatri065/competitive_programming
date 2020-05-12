#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[2 * size];
    for(int i = 0;i < 2 * size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + (2 * size));

    long long int sum = 0;
    for(int i = 0;i < 2 * size;i += 2) {
        int min_build = min(arr[i], arr[i + 1]);
        sum += min_build;
    }

    cout << sum << endl;

    return 0;
}