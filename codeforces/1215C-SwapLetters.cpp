/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
void solve() {
    int n;
    sc(n);

    string s, t;
    cin >> s >> t;

    int a = 0, b = 0;
    for(int i = 0;i < n;i++) {
        if(s[i] == 'a') {
            a++;
        } else {
            b++;
        }

        if(t[i] == 'a') {
            a++;
        } else {
            b++;
        }
    }

    if(a & 1 || b & 1) {
        pf(-1);
        return;
    }

    vector<int> ab, ba;
    for(int i = 0;i < n;i++) {
        if(s[i] == 'a' && t[i] == 'b') {
            ab.push_back(i + 1);
        } else if(s[i] == 'b' && t[i] == 'a') {
            ba.push_back(i + 1);
        }
    }

    vector<pair<int, int>> ans;
    if(int(ab.size()) % 2 == 1 && int(ba.size()) % 2 == 1) {
        ans.pb({ba.back(), ba.back()});
        ab.pb(ba.back());
        ba.pop_back();
    }
    
    for(int i = 0;i < int(ab.size());i += 2) {
        ans.pb({ab[i], ab[i + 1]});
    }

    for(int i = 0;i < int(ba.size());i += 2) {
        ans.pb({ba[i], ba[i + 1]});
    }

    pf(int(ans.size()));
    for(auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    go();
    solve();
    return 0;
}