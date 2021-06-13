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

int count(string s) {
    int ans = 0;
    for(int i = 0;i + 4 <= sz(s);i++) {
        ans += (s.substr(i, 4) == "haha");
    }

    return ans;
}

auto merge(pair<ll, string> a, pair<ll, string> b) {
    ll cnt = a.ff + b.ff;
    string s = a.ss + b.ss;
    for(int i = max(0, sz(a.ss) - 3);i + 4 <= sz(s) && i < sz(a.ss);i++) {
        cnt += (s.substr(i, 4) == "haha");
    }

    if(sz(s) >= 6) {
        s.erase(s.begin() + 3, s.end() - 3);
    }

    return make_pair(cnt, s);
}

void solve() {
    int n;cin >> n;
    
    map<string, pair<ll, string>> f;
    string last;
    while(n--) {
        string a, op, b, c;
        cin >> a >> op;
        if(op == ":=") {
            cin >> b;
            f[a] = {count(b), b};
        } else {
            cin >> b >> op >> c;
            f[a] = merge(f[b], f[c]);
        }

        last = a;
    }

    pf(f[last].ff);
}   

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}