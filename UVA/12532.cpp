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
const int M = 1e5 + 5;
int x[M + 10];
int segtree[4 * M + 100];

void buildTree(int at, int lo, int hi) {
    if(lo == hi) {
        segtree[at] = x[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    buildTree(2 * at, lo, mid);
    buildTree(2 * at + 1, mid + 1, hi);

    segtree[at] = segtree[2 * at] * segtree[2 * at + 1];
}

void update(int at, int index, int val, int lo, int hi) {
    if(index < lo || index > hi) {
        return;
    }

    if(lo == hi) {
        segtree[at] = val;
        return;
    }

    int mid = (lo + hi) / 2;
    update(2 * at, index, val, lo, mid);
    update(2 * at + 1, index, val, mid + 1, hi);

    segtree[at] = segtree[2 * at] * segtree[2 * at + 1];
}

int query(int at, int lo, int hi, int start, int endInd) {
    if(start > hi || endInd < lo) {
        return 1;
    }

    if(lo >= start && hi <= endInd) {
        return segtree[at];
    }

    int mid = (lo + hi) / 2;

    return query(2 * at, lo, mid, start, endInd) * query(2 * at + 1, mid + 1, hi, start, endInd);
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    while(cin >> n >> k) {
        for(int i = 0;i < n;i++) {
            sc(x[i]);
            if(x[i] > 1) {
                x[i] = 1;
            }

            if(x[i] < -1) {
                x[i] = -1;
            }
        }

        buildTree(1, 0, n - 1);

        char type;
        while(k--) {
            sc(type);

            if(type == 'C') {
                int ind, val;
                sc(ind);
                sc(val);

                ind--;
                if(val > 1) {
                    val = 1;
                }

                if(val < -1) {
                    val = -1;
                }

                update(1, ind, val, 0, n - 1);
                x[ind] = val;
            } else {
                int start, endInd;
                cin >> start >> endInd;

                start--;
                endInd--;

                int res = query(1, 0, n - 1, start, endInd);

                if(res == 1) {
                    cout << "+";
                } else if(res == -1) {
                    cout << "-";
                } else {
                    cout << "0";
                }
            }
        }

        cout << endl;
    }

    return 0;
}