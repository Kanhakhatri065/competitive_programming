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
vector<vector<ll>> subseq;
vector<ll> b;
void subsequences(vector<ll> arr, int index, vector<ll> subarr) {
    if(index == int(arr.size())) {
        int l = arr.size();
        if(l != 0) {
            subseq.pb(arr);
        }
    } else {
        subsequences(arr, index + 1, subarr);
        subarr.pb(arr[index]);
        subsequences(arr, index + 1, subarr);
    }
}

const int MAX = 165;
ll g[MAX], l[MAX], lg[MAX], ans[MAX];
vector<ll> store[MAX];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0;i < n;i++) {
        scanf("%lld", &g[i]);
    }

    for(int i = 0;i < n;i++) {
        scanf("%lld", &l[i]);
    }

    for(int i =  0;i < m;i++) {
        scanf("%lld", &lg[i]);
    }

    for(int i = 0;i < n;i++) {
        store[g[i] - 1].pb(l[i]);
    }

    for(int i = 0;i < m;i++) {
        ans[i] = store[i][0] % lg[i];
    }

    ll tmp;
    for(int i = 0;i < m;i++) {
        subsequences(store[i], 0, b);
        
        for(auto it : subseq) {
            tmp = 1;
            for(auto jt : it) {
                tmp *= jt;
            }
            ans[i] = max(ans[i], tmp % lg[i]);
        }

        subseq.clear();
        b.clear();
    }

    for(int i = 0;i < m;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    for(int i = 0;i < m;i++) {
        store[i].clear();
    }
}

int main() {
    go();
    int t;
    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}