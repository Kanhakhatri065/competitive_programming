/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod 1000000007
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
void solve() {
    int n,m;
    cin>>n>>m;
    
    int r[n];
    forIn(r, n);

    int a[n][m+1];
    for(int i = 0;i < n;i++) {
        int prev = r[i];
        int mx = 0, c, indx = -1;
        for(int j = 0;j < m;j++) {
            cin >> c;
            a[i][j] = prev + c;
            prev = a[i][j];
            if(mx < a[i][j]){
                mx = a[i][j];
                indx = j;
            }
        }
        
        a[i][m] = indx;
    }
    
    int rank[n][m+1] = {};
    
    for(int i = 0;i < m;i++) {
        int temp[n];
        for(int j = 0;j < n;j++) {
            temp[j] = a[j][i];
        }
        
        sort(temp,temp+n);
        
        for(int j = 0;j < n;j++) {
            int to_search = a[j][i];
            int indx = upper_bound(temp, temp+n, to_search) - temp;
            rank[j][i] = n  - indx;
        }
    }
    
    
    
    for(int i = 0;i < n;i++) {
        int best = n,indx = -1;
        for(int j = 0;j < m;j++) {
            if(rank[i][j]<best) {
                best = rank[i][j];
                indx = j;
            }
        }
       
        rank[i][m] = indx;
    }
    
    
    
    int ans = 0;
    for(int i = 0;i < n;i++) {
        ans += (a[i][m] != rank[i][m]);
    }

    pf(ans);
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}