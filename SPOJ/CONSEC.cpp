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
    string s;cin >> s;
    int n = sz(s);
    
    set<pair<int, int>> ranges;
    int lst = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] !=  s[lst]) {
            ranges.insert({lst, i - 1});
            lst = i;
        }
    }

    ranges.insert({lst, n - 1});

    int q;
    cin >> q;
    while(q--) {
        int t, p;
        cin >> t >> p;
        if(t == 1) {
            auto it = --ranges.upper_bound({p, 1 << 30});
            cout << ((it->ss) - (it->ff) + 1) << endl;
        } else {
            auto it = --ranges.upper_bound({p, 1 << 30});
            int l = it->ff, r = it->ss;
            ranges.erase(it);
            if(l != p) ranges.insert({l, p - 1});
            if(r != p) ranges.insert({p + 1, r});
        }
    }
}

#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case " << tt << ":\n";solve();}

int main() {
    go();
    mcsolve
    return 0;
}
