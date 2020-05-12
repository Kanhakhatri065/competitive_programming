#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    int testcases;
    cin >> testcases;

    ll k;
    int d0, d1;
    while(testcases--) {
        cin >> k >> d0 >> d1;

        int d2 = (d0 + d1) % 10;
        ll sum = d0 + d1 + d2;
        int prev = d2;
        int num = 0;
        for(ll i = 3;i < k;i++) {
            num = (2 * prev) % 10;
            prev = num;
            sum += num;
        }

        if(sum % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}