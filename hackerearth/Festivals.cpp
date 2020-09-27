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
bool cmp(pair<ll, string> a, pair<ll, string> b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }

    return a.first > b.first;
}
void solve() {
    int n;
    sc(n);

    int x;
    string str;
    map<string, vector<int>> mp;
    for(int i = 0;i < n;i++) {
        cin >> str >> x;
        mp[str].pb(x);
    }

    vector<pair<ll, string>> store;
    ll sum = 0, cnt = 0;
    for(auto it : mp) {
        vector<int> tmp = it.second;
        sort(all(tmp), greater<int>());
        sum = 0;
        cnt = 0;
        for(auto j : tmp) {
            if(cnt == 3) {
                break;
            }
            sum += j;
            cnt++;
        }

        store.push_back({sum, it.first});
    }

    sort(all(store), cmp);

    cout << store.front().second << " " << store.front().first << endl;
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}