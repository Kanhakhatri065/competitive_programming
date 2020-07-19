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
struct segtree {
    struct node {
        int lo, lc, matched;
    };

    int n;

    node st[int(4e6 + 5)];
    segtree(string &s) {
        n = (int) s.length();
        build(1, 0, n - 1, s);
    }

    node combine(node &a, node &b) {
        struct node res;
        int delta = min(a.lo, b.lc);
        res.matched = a.matched + b.matched + delta;
        res.lo = a.lo + b.lo - delta;
        res.lc = a.lc + b.lc - delta;
        return res;
    }

    void build(int idx, int start, int end, string &s) {
        if(start == end) {
            if(s[start] == '(') {
                st[idx].lc = st[idx].matched = 0;
                st[idx].lo = 1;
            } else {
                st[idx].lo = st[idx].matched = 0;
                st[idx].lc = 1;
            }

            return;
        }

        int mid = (start + end) / 2;
        build(2 * idx, start, mid, s);
        build(2 * idx + 1, mid + 1, end, s);
        st[idx] = combine(st[2 * idx], st[2 * idx + 1]);
    }

    node query(int idx, int s, int e, int qs, int qe) {
        if(qe < qs || qe < s || qs > e) {
            return {0, 0, 0};
        }

        if(qs <= s && e <= qe) {
            return st[idx];
        }

        int mid = (s + e) / 2;
        node q1 = query(2 * idx, s, mid, qs, qe);
        node q2 = query(2 * idx + 1, mid + 1, e, qs, qe);
        return combine(q1, q2);
    }
};

void solve() {
    string s;
    sc(s);

    int n = (int) s.length();

    static segtree st(s);

    int m;
    sc(m);

    int l, r;
    for(int i = 0;i < m;i++) {
        sc(l);
        sc(r);
        l--;
        r--;
        cout << (2 * (st.query(1, 0, n - 1, l, r).matched)) << endl;
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}