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
const int len = 32;
int mat[len][len];
int cnt;
char quad;

void build(char q, int c, int r, int w) {
    cin >> q;
    if(q == 'p') {
        build(q, c + w / 2, r, w / 2);
        build(q, c, r, w / 2);
        build(q, c, r + w / 2, w / 2);
        build(q, c + w / 2, r + w / 2, w / 2);
    } else if(q == 'f') {
        for(int i = r;i < (r + w);i++) {
            for(int j = c;j < (c + w);j++) {
                if(mat[i][j] == 0) {
                    mat[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
}

void solve() {
    cnt = 0;
    mem(mat, 0);
    build(quad, 0, 0, 32);
    build(quad, 0, 0, 32);
    cout << "There are " << cnt << " black pixels." << endl;
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