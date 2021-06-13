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
const int N = 1e5 + 5;

void solve() {
    int n;cin >> n;
    string s;cin >> s;

    int cnt = 0;
    while(sz(s) && s.front() == s.back()) {
        cnt++;
        s.pop_back();
    }

    if(s.empty()) {
        if(cnt <= 2) {
            pf(0);
            return;
        }

        if(cnt == 3) {
            pf(1);
            return;
        }

        pf((cnt + 2) / 3);
        return;
    }

    s.push_back('$');
    int ans = 0;
    for(int i = 0;i + 1 < sz(s);i++) {
        cnt++;
        if(s[i] != s[i + 1]) {
            ans += cnt / 3;
            cnt = 0;
        }
    }

    pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}