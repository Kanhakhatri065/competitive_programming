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
    string s;
    sc(s);

    //pf("string input completed");
    vector<set<int>> poss(26);
    for(int i = 0;i < (int) s.size();i++) {
        poss[s[i] - 'a'].insert(i);
    }

    //pf("vector of set creation completed");

    int q;
    sc(q);

    for(int i = 0;i < q;i++) {
        int tp;
        sc(tp);

        if(tp == 1) {
            //pf("Type 1 query execution start");
            int pos;
            char c;
            sc(pos);
            sc(c);

            --pos;
            poss[s[pos] - 'a'].erase(pos);
            s[pos] = c;
            poss[s[pos] - 'a'].insert(pos);
            //pf("Type 1 query done right");
        } else {
            //pf("Type 2 query execution start");
            int l, r;
            sc(l);
            sc(r);

            l--;
            r--;

            int cnt = 0;
            for(int c = 0;c < 26;c++) {
                auto it = poss[c].lower_bound(l);
                if(it != poss[c].end() && *it <= r) {
                    cnt++;
                }
            }

            pf(cnt);
            //pf("Type 2 query done right");
        }
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}