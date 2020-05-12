#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll testcases;
    cin >> testcases;

    ll size;
    while(testcases--) {
        cin >> size;

        vector<ll> v(size, 0);
        for(ll i = 0;i < size;i++) {
            cin >> v[i];
        }

        ll count = 1;
        ll speed = v[0];

        for(int i = 1;i < size;i++) {
            if(v[i] <= speed) {
                count++;
                speed = v[i];
            }
        }

        cout << count << endl;
    }

    return 0;
}