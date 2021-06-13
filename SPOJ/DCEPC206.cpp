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

ll ft[N + 1];
ll get(int pos) {
    ll res = 0;
    while(pos) {
        res += ft[pos];
        pos -= pos & (-pos);
    }
    return res;
}

void update(int pos, int val) {
    while(pos <= N) {
        ft[pos] += val;
        pos += pos & (-pos);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), hold(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        hold[i] = a[i];
    }

    sort(all(a));
    for(int i = 0;i < n;i++) {
        int pos = lower_bound(all(a), hold[i]) - a.begin();
        hold[i] = pos;
    }

    ll sum = 0;
    memset(ft, 0, sizeof(ft));
    for(int i = 0;i < n;i++) {
        sum += get(hold[i]);
        update(hold[i] + 1, a[hold[i]]);
    }

    pf(sum);    
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}   