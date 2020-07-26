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
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const int MAX = 1e5 + 5;
const double INF = 10e30;

pdd v[MAX];
set<pdi> s;
double res;

double dist(int a, int b) {
    double d = sqrt((v[a].ff - v[b].ff) * (v[a].ff - v[b].ff) + (v[a].ss - v[b].ss) * (v[a].ss - v[b].ss));
    return d;
}

void solve() {
    int n;
    sc(n);
    for(int i = 0;i < n;i++) {
        sc(v[i].ff);
        sc(v[i].ss);
    }

    sort(v, v + n);

    s.clear();
    res = INF;

    int l = 0;

    for(int i = 0;i < n;i++) {
        while(l < i && v[i].ff - v[l].ff >= res) {
            s.erase(pdi(v[l].ss, l));
            l++;
        }

        set<pdi>::iterator lef = s.lower_bound(pdi(v[i].ss - res, 0));
        set<pdi>::iterator rig = s.lower_bound(pdi(v[i].ss + res, n));

        for(set<pdi>::iterator it1 = lef;it1 != rig;it1++) {
            set<pdi>::iterator it2 = it1;
            for(it2++;it2 != rig;it2++) {
                res = min(res, dist(i, it1->ss) + dist(i, it2->ss) + dist(it1->ss, it2->ss));
            }
        }
        s.insert(pdi(v[i].ss, i));
    }

    cout << fixed << setprecision(10) << res << endl;
}

int main() {
    FAST_IO
    int t;
    sc(t);

    f(tt, 1, t + 1) {
        cout << "Case " << tt << ": ";
        solve();
    }
    return 0;
}