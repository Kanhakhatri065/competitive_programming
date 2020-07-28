#include <bits/stdc++.h>

using namespace std;

int main() {
    int size, k;
    cin >> size >> k;

    vector<long long int> v(size, 0);
    for(int i = 0;i < size;i++) {
        cin >> v[i];
    }

    vector<long long int> b(size, 0);
    for(int i = 1;i < size;i++) {
        v[i] += v[i - 1];
        b[i] = v[i]; 
    }

    long long total = 0;
    for(int i = 0;i < k;i++) {
        long long int temp = v[i] + b[size - 1] - b[size - k + i];
        total = max(temp, total);
    }

    cout << total << endl;
    return 0;
}