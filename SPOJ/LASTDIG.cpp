#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll t, a, b, res;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        res = 1;
        a %= 10LL;
        while(b) {
            if(b & 1) res = (res * a) % 10LL;
            a = (a * a) % 10LL;
            b >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}
