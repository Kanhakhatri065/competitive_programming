#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
const int MOD = 1e9 + 7;
const int N = 1e4 + 5;


int ask(int t, int i, int j, int x) {
    cout << "? " << t << " " << i << " " << j << " " << x << endl;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;

    int l = 0, r = n;
    while(r - l > 1) {
        int mid = (l + r) >> 1;
        int x = ask(2, 1, 2, mid);
        if(x == mid) r = mid;
        else l = mid;
    }    

    int p[n + 1];

    p[1] = r;
    for(int i = 2;i <= n;i++) {
        if(r - 1 > n - r) {
            int x = ask(2, i, 1, 1);
            if(x < r) p[i] = x;
            else {
                int x = ask(1, 1, i, n - 1);
                p[i] = x;
            }
        } else {
            int x = ask(1, 1, i, n - 1);
            if(x > r) p[i] = x;
            else {
                int x = ask(2, i, 1, 1);
                p[i] = x;
            }
        }
    }

    cout << "!";
    for(int i = 1;i <= n;i++) cout << " " << p[i];
    cout << endl;
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}