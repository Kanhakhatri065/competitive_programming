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
bool isPrime(int n) {
    for(int i = 2;i * i <= n;i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    sc(n);

    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    if(isPrime(n)) {
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                arr[i][j] = 1;
            }
        }
    } else {
        
        for(int i = 0;i < n;i++) {
            arr[i][i] = 4;
        }

        for(int i = 0;i < n;i++) {
            arr[i][(i + 1) % n] = 1;
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
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