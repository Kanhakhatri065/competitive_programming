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
    int n;cin >> n;
    string s;cin >> s;
    
    bool isPalindrome = true;
    int zeros = 0, ones = 0;
    for(int i = 0;i < n;i++) zeros += (s[i] == '0');

    for(int i = 0;i < (n / 2);i++) {
        if(s[i] != s[n - i - 1]) isPalindrome = false;
        if((s[i] == '1' || s[n - i - 1] == '1') && s[i] != s[n - i - 1]) {
            ones++;
        }
    }

    if(isPalindrome) {
        if(zeros == 1) {
            pf("BOB");
            return;
        }

        if(zeros & 1) {
            pf("ALICE");
            return;
        }

        pf("BOB");
        return;
    }

    if(zeros == 2 && ones == 1) {
        pf("DRAW");
        return;
    }

    pf("ALICE");
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}