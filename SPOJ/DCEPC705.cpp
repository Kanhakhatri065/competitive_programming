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

int n, k;
int bit[N];

void update(int idx, int val) {
    while(idx <= 1e5) {
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void solve() {
    memset(bit, 0, sizeof(bit));
    cin >> n >> k;

    set<pair<int, int>> s;
    vector<pair<int, int>> table;
    vector<int> Y, Ytemp;

    for(int i = 0;i < n;i++) {
        int x, y;cin >> x >> y;
        table.pb({x, y});
        s.insert({x, y});
    }

    sort(all(table));
    for(auto p : table) Y.pb(p.ss);
    for(int i : Y) Ytemp.pb(i);

    sort(all(Ytemp));
    vector<int> finals;
    for(auto i : Y) {
        int pos = lower_bound(all(Ytemp), i) - Ytemp.begin() + 1;
        finals.pb(pos);
    }

    int cnt = 0;
    for(int i = 0;i < n;i++) {
        int d = query(finals[i]);
        int nd = n - 1 - d;
        update(finals[i], 1);
        int diff =abs(d - nd);
        if(diff >= k) cnt++;
    }

    pf(cnt);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}