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
    string s;
    cin >> s;


    reverse(all(s));
    for(int i = 0;i < sz(s);i++) {
        if(s[i] == '6') {
            s[i] = '9';
        } else if(s[i] == '9') {
            s[i] = '6';
        }
    }

    pf(s);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}