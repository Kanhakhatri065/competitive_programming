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
    int ans = 0;
    for(int i = 0;i < 10000;i++) {
        vector<int> flag(10);
        int x = i;
        for(int j = 0;j < 4;j++) {
            flag[x % 10] = true;
            x /= 10;
        }

        bool flag2 = true;
        for(int j = 0;j < 10;j++) {
            if(s[j] == 'o' && !flag[j]) flag2 = false;
            if(s[j] == 'x' && flag[j]) flag2 = false;
        }

        if(flag2) ans++;
    }

    pf(ans);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}