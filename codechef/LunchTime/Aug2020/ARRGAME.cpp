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
    int n;
    sc(n);

    vector<int> a(n), zeroSegment;
    forIn(a, n);

    for(int i = 0;i < n;i++) {
        if(a[i]) {
            continue;
        }

        int ptr = i;
        while((ptr + 1) < n && (a[ptr + 1] == 0)) {
            ptr++;
        }

        zeroSegment.pb(ptr - i + 1);
        i = ptr;
    }

    if(zeroSegment.size() == 0) {
        pf("No");
    } else if(zeroSegment.size() == 1) {
        if(zeroSegment[0] % 2) {
            pf("Yes");
        } else {
            pf("No");
        }
    } else {
        int maxLen = 0, id = -1;
        int m = zeroSegment.size();

        for(int i = 0;i < m;i++) {
            if(maxLen < zeroSegment[i]) {
                maxLen = zeroSegment[i];
                id = i;
            }
        }

        swap(zeroSegment[0], zeroSegment[id]);
        maxLen = 0, id = -1;
        for(int i = 1;i < m;i++) {
            if(maxLen < zeroSegment[i]) {
                maxLen = zeroSegment[i];
                id = i;
            }
        }

        swap(zeroSegment[1], zeroSegment[id]);

        if((zeroSegment[0] % 2) && (zeroSegment[1] <= (zeroSegment[0] - 1) / 2)) {
            pf("Yes");
        } else {
            pf("No");
        }
    }
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