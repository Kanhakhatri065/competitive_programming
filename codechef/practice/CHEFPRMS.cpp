/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
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

    bool flag = false;
    for(int i = 2;i < n;i++) {
        int tmp = i;
        map<int, int> s, t;
        for(int j = 2;j < n;j++) {
            while(tmp % j == 0) {
                s[j]++;
                tmp /= j;
            }
        }

        if(tmp > 1) {
            s[tmp]++;
        }

        if(s.size() == 2) {
            //pf("First condition passed");
            bool inner_flag = true;
            for(auto it : s) {
                if(it.ss > 1) {
                    inner_flag = false;
                    break;
                }
            }

            //pf("First part2 condition passed");

            if(!inner_flag) {
                continue;
            }

            tmp = n - i;
            for(int j = 2;j < n;j++) {
                while(tmp % j == 0) {
                    t[j]++;
                    tmp /= j;
                }
            }

            if(tmp > 1) {
                t[tmp]++;
            }

            if(t.size() == 2) {
                //pf("Second condition passed");
                //cout << i << " " << (n - i) << endl;
                for(auto it : t) {
                    if(it.ss > 1) {
                        inner_flag = false;
                        break;
                    }
                }

                if(!inner_flag) {
                    continue;
                }

                //pf("Second part2 condition passed");
                flag = true;
                break;
            }
        }
    }

    flag ? yes : no;
}

int main() {
    FAST_IO
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}