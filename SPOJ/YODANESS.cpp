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
const int N = 3e4 + 5;

int n;
string name;
int a[N], ft[N];
map<string, int> pos;

void add(int pos, int val) {
    while(pos < N) {
        ft[pos] += val;
        pos += (pos & (-pos));
    }
}

int get(int pos) {
    int res = 0;
    while(pos > 0) {
        res += ft[pos];
        pos -= (pos & (-pos));
    }

    return res;
}

void solve() {
    cin >> n;
    pos.clear();

    for(int i = 1;i <= n;i++) {
        cin >> name;
        pos[name] = i;
    }

    for(int i = 1;i <= n;i++) {
        cin >> name;
        a[i] = pos[name];
    }

    memset(ft, 0, sizeof(ft));

    int inv = 0;
    for(int i = n;i >= 1;i--) {
        inv += get(a[i] - 1);
        add(a[i], 1);
    }

    pf(inv);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}