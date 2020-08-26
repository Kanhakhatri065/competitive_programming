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
#define F(ss) find(ss)
#define TWIN(ff) ((ff % 2) ? (ff + 1) : (ff - 1))
#define T(ff) TWIN(ff)
#define ENEMIES(a, b) ((F(b) == F(T(a))) || (F(a) == F(T(b))))
#define FRIENDS(a, b) ((F(a) == F(b)) || (F(T(a)) == F(T(b))))

vector<int> p;
void init(int N) {
    p.assign(N + 1, 0);
    for(int i = 1;i < N + 1;i++) {
        p[i] = i;
    }
}

int find(int a) {
    return p[a] == a ? a : (p[a] = find(p[a]));
}

void Union(int a, int b) {
    p[find(a)] = find(b);
}

void solve() {
    int n;
    sc(n);

    init(2 * n);
    int c, f1, f2;
    while(cin >> c >> f1 >> f2) {
        if(!c && !f1 && !f2) {
            break;
        }

        f1 = 2 * f1 + 1, f2 = 2 * f2 + 1;

        if(c == 1) {
            if(ENEMIES(f1, f2)) {
                pf(-1);
            } else {
                Union(f1, f2);
                Union(T(f1), T(f2));
            }
        } else if(c == 2) {
            if(FRIENDS(f1, f2)) {
                pf(-1);
            } else {
                Union(f1, T(f2));
                Union(T(f1), f2);
            }
        } else if(c == 3) {
            if(FRIENDS(f1, f2)) {
                pf(1);
            } else {
                pf(0);
            }
        } else {
            if(ENEMIES(f1, f2)) {
                pf(1);
            } else {
                pf(0);
            }
        }
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}