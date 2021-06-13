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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    int dist = 0;
    for(int i = 1;i < n;i++) {
        if(s[i] != s[i - 1]) dist++;
        else dist += 2;
    }

    for(int i = 0;i < k;i++) {
        int x;cin >> x;
        x--;

        char prev = s[x];

        if(x - 1 >= 0) {
            if(s[x - 1] == prev) dist--;
            else dist++;
        }

        if(x + 1 < n) {
            if(s[x + 1] == prev) dist--;
            else dist++;
        }

        if(s[x] == '1') s[x] = '0';
        else s[x] = '1';
        
        pf(dist);
    }


}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}