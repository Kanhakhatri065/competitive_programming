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

void output(vector<int> v) {
    cout << sz(v);
    for(int x : v) cout << " " << x;
    cout << endl;
}

void solve() {
    int n;cin >> n;
    
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    vector<vector<int>> bk(200, vector<int>(0));
    int cnt = min(n, 8);
    for(int i = 1;i < (1 << cnt);i++) {
        int sig = 0;
        vector<int> s;
        for(int j = 0;j < cnt;j++) {
            if(i & (1 << j)) {
                s.pb(j + 1);
                sig += a[j];
                sig %= 200;
            }
        }

        if(bk[sig].size() != 0) {
            pf("Yes");
            output(bk[sig]);
            output(s);
            return;
        } else {
            bk[sig] = s;
        }
    }

    pf("No");
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
