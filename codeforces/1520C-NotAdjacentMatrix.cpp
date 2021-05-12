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
    int n;
    cin >> n;

    if(n == 1) {
        pf(1);
        return;
    }

    if(n == 2) {
        pf(-1);
        return;
    }

    vector<vector<int>> a(n, vector<int>(n));
    a[0][0] = 1;
    a[n - 1][n - 1] = 2;

    int cnt = 3;
    for(int i = 1;i < n;i++) {
        int x = 0, y = i;
        while(y >= 0) {
            a[x][y] = cnt++;
            x++, y--; 
        }
    }

    for(int i = 1;i + 1 < n;i++) {
        int x = i, y = n - 1;
        while(x < n) {
            a[x][y] = cnt++;
            x++, y--;
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}