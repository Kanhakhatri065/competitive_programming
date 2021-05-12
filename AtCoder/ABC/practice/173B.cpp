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
    int n;
    cin >> n;
    
    map<string, int> mp;
    for(int i = 0;i < n;i++) {
        string s;cin >> s;
        mp[s]++;
    }

    pf("AC x " + to_string(mp["AC"]));
    pf("WA x " + to_string(mp["WA"]));
    pf("TLE x " + to_string(mp["TLE"]));
    pf("RE x " + to_string(mp["RE"]));
}

int main() {
    go();
    int t;t = 1;
    while(t--) solve();
    return 0;
}
