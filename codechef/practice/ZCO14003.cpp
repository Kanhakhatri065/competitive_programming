#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    vector<long long int> v(n, 0);
    for(long long int i = 0;i < n;i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<long long int>());

    long long sum = v[0];
    for(long long int i = 1;i < v.size();i++) {
        if(((i + 1) * v[i]) >= sum) {
            sum = ((i + 1) * v[i]);
        }
    }

    cout << sum << endl;
    return 0;
}