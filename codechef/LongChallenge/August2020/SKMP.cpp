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
    string s, p;
    cin >> s >> p;

    int n = int(s.size());
    int m = int(p.size());

    if(n == m) {
        pf(p);
        return;
    }

    if(m == 1) {
        srt(s);
        pf(s);
        return;
    }

    int cnt1[26];
    mem(cnt1, 0);
    for(int i = 0;i < n;i++) {
        cnt1[s[i] - 'a']++;
    }

    int cnt2[26];
    mem(cnt2, 0);
    for(int i = 0;i < m;i++) {
        cnt2[p[i] - 'a']++;
    }

    char initial = p[0];
    char next;
    for(int i = 1;i < m;i++) {
        if(p[i] != p[0]) {
            next = p[i];
            break;
        }

        if(i == m - 1) {
            next = p[i];
        }
    }
    string out = "";
    char c;
    for(int i = 0;i < 26;i++) {
        c = i + 97;
        if(c < initial) {
            if(cnt1[i] > cnt2[i]) {
                string tmp(cnt1[i] - cnt2[i], c);
                out += tmp;
                cnt1[i] = cnt2[i];
            }
        } else if(c == initial) {
            if(next < initial) {
                out += p;
            } else {
                string tmp(cnt1[i] - cnt2[i], c);
                out += tmp;
                cnt1[i] = cnt2[i];
                out += p;
            }
            break;
        }
    }

    for(int i = 0;i < 26;i++) {
        cnt1[i] -= cnt2[i];
    }

    for(int i = 0;i < 26;i++) {
        if(cnt1[i] > 0) {
            string tmp(cnt1[i], char(i + 97));
            out += tmp;
            cnt1[i] = 0;
        }
    }

    //cout << "Answer : ";
    pf(out);
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