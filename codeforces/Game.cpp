#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<ll> v(size, 0);
    for(int i = 0;i < size;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    cout << v[(v.size() - 1) / 2] << endl;
    return 0;
}