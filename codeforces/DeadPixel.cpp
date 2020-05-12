#include <iostream>

typedef long long int ll;

using namespace std;

int main() {
    ll testcases;
    cin >> testcases;

    ll a, b, x, y;
    ll area;
    while(testcases--) {
        cin >> a >> b >> x >> y;
        x++;
        y++;

        ll aa = a * (y - 1);
        ll bb = a * abs(b - y);
        ll cc  = b * (x - 1);
        ll dd = b * abs(a - x);

        ll ans = max(aa,bb);
        ans = max(ans, cc);
        ans = max(ans, dd);     

        cout << ans << endl;
    }

    return 0;
}