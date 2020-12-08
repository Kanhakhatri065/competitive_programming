/*
	I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
/*----typedefs--------*/
typedef long long ll;typedef long double ld;typedef complex<ld> cd;
typedef pair<int, int> pi;typedef pair<ll, ll> pl;typedef pair<ld, ld> pd;
typedef vector<int> vi;typedef vector<pi> vpi;typedef vector<ll> vl;typedef vector<ld> vd;typedef vector<pl> vpl;
typedef vector<cd> vcd;typedef vector<vi> vvi;
typedef map<int, int> mi;typedef map<ll, ll> ml;typedef map<int, vi> mivi;typedef map<int, pi> mipi;
typedef set<int> si;typedef set<ll> sl;typedef set<pair<int, int>> spi;
typedef queue<int> qi;typedef queue<pi> qpi;
/*-----in and out--------*/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*-----traversals--------*/
#define trav(it, a) for(auto &it : a)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
/*--- bit-stuff ----*/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*----- the binary answer of life-----*/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*---checking and pushing-----*/
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
/*---- FAST I/O and file read ---*/
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*------ single or multiple testcase-----*/
#define ssolve solve();
#define msolve int t;sc(t);while(t--) {solve();}
#define mcsolve int t;sc(t);for(int tt = 1;tt <= t;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int maxn = (1LL << 16) + 5;
const int minn = 4;
const int maxncheck = (1LL << 16);
/*-------------- Push your limits here ---------------------------*/
int n, xorvals[maxn], ans[maxn];
vector<int> pos[maxn];

int queries(string s, int i, int j)
{
    cout << s << " " << i << " " << j << endl;
    cout.flush();
    int dest;
    cin >> dest;
    if(dest == -1)
        exit(0);
    return dest;
}
 
int32_t main()
{
    cin >> n;
    assert(n >= minn && n <= maxncheck && __builtin_popcount(n) == 1);
    xorvals[1] = 0;
    pos[0].push_back(1);
    for(int i = 2; i <= n; i++)
    {
        xorvals[i] = queries("XOR", 1, i);
        pos[xorvals[i]].push_back(i);
    }
    int a = 1, b = -1, c = -1;
    int same = -1;
    for(int i = 0; i < n; i++)
        if(pos[i].size() > 1)
        {
            b = pos[i][0];
            c = pos[i][1];
            same = i;
        }
    if(same == -1)
    {
        // If a_b ^ a_c == n - 1, then a_b & a_c = 0 
        for(int i = 2; i <= 3; i++)
            for(int j = i + 1; j <= n; j++)
                if((xorvals[i] ^ xorvals[j]) == n - 1)
                {
                    b = i;
                    c = j;
                }
        int xorab = xorvals[a] ^ xorvals[b], xorac = xorvals[a] ^ xorvals[c], xorbc = xorvals[b] ^ xorvals[c];
        int andab = queries("AND", a, b);
        int andac = queries("AND", a, c);
        int andbc = 0;
        int x = xorab + 2 * andab;
        int y = xorac + 2 * andac;
        int z = xorbc + 2 * andbc;
        assert((x + y - z) % 2 == 0);
        ans[a] = (x + y - z) / 2;
    }
    else
    {
        // if a_1 ^ a_b == a_1 ^ a_c, then a_b = a_c = (a_b & a_c)
        ans[b] = queries("AND", b, c);
        ans[1] = xorvals[b] ^ ans[b];
    }
    for(int i = 2; i <= n; i++)
        ans[i] = (xorvals[i] ^ ans[1]);
    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << endl;
    cout.flush();
    return 0;
}
