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
const int MAX = 1e2 + 10;
char arr[MAX][MAX];
bool check(char a,char b,char c,char d) {
    if(a=='s' && b=='a' && c=='b' && d=='a') {
        return true;
    }

    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            sc(arr[i][j]);
        }
    }
    
    for(int i = 4;i <= n;i++) {
        for(int j = 1;j <= m - 3;j++) {
            if(check(arr[i][j], arr[i - 1][j + 1], arr[i - 2][j + 2], arr[i - 3][j + 3])) {
	            ans++;
            }
        }
    }

    for(int i = 1;i <= n - 3;i++) {
        for(int j = 1;j <= m - 3;j++) {
            if(check(arr[i][j], arr[i + 1][j + 1], arr[i + 2][j + 2], arr[i + 3][j + 3])) {
	            ans++;
            }
        }
    }
  
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m - 3;j++) {
            if(check(arr[i][j], arr[i][j + 1], arr[i][j + 2], arr[i][j + 3])) {
	            ans++;
            }
        }
    }

    for(int i = 1;i <= n - 3;i++) {
        for(int j = 1;j <= m;j++) {
            if(check(arr[i][j], arr[i + 1][j], arr[i + 2][j], arr[i + 3][j])) {
	            ans++;
            }
        }
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}