#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, m;
    cin >> n >> m;
    long long int first, second;
    if(n >=m) {
        first = n;
        second = m;
    } else {
        first = m;
        second = n;
    }

    long long int arr[5];
    for(int i = 0;i < 5;i++) {
        arr[i] = 0;
    }

    for(long long int i = 1;i <= second;i++) {
        arr[i % 5]++;
    }

    long long int count = 0;
    for(long long int i = 1;i <= first;i++) {
        if(i % 5 == 0) {
            count += arr[0];
        } else {
            count += arr[5 - (i % 5)];
        }
    }

    cout << count << endl;

    return 0;
}