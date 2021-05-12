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
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int x, y;
    cin >> x >> y;
    
    bool flag = false;
    for(int i = 0;i <= x;i++) {
        if(i * 2 + (x - i) * 4 == y) {
            flag = true;
        }
    }

    if(flag) pf("Yes");
    else pf("No");
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
