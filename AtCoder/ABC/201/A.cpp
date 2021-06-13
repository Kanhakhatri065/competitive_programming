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
    vector<int> a(3);
    for(int i = 0;i < 3;i++) cin >> a[i];

    do {
        if(a[2] - a[1] == a[1] - a[0]) {
            pf("Yes");
            return;
        }
    } while(next_permutation(all(a)));

    pf("No");
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}