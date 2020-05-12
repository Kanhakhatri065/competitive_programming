#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<int> v(size, 0);
    for(int i = 0;i < size;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    long long int count = 0;
    for(int i = 0;i < size;i += 2) {
        if(v[i] != v[i + 1]) {
            count += (v[i] - v[i + 1]);
        } 
    }

    cout << count << endl;

    return 0;
}