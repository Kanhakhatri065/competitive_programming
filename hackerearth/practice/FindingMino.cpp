#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;


int main() {
    ll n;
    cin >> n;

    ll l, r;
    for(ll i = 0;i < n;i++) {
        cin >> l >> r;

        ll ans;
        if(l <= 3 && r >= 3) {
            ans = -11;
        } else if(l < 3 && r < 3) {
            ans = (2 * r * r) - (12 * r) + 7;
        }else if(l > 3 && r > 3) {
            ans = (2 * l * l) - (12 * l) + 7;
        }

        cout << ans << endl;
    }

    return 0;
}