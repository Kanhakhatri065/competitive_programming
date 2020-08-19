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
int nSets;
map<char, char> p;
map<char, int> r, sizes;

void init() {
    nSets = 0;
    p.clear();
    r.clear();
    sizes.clear();
}

char getSet(char i) {
    if(p.find(i) == p.end()) {
        p[i] = i;
        r[i] = 0;
        sizes[i] = 1;
        nSets++;
        return i;
    }

    return (p[i] == i) ? i : (p[i] = getSet(p[i]));
}

bool sameSet(char i, char j) {
    return getSet(i) == getSet(j);
}

void joinSet(char i, char j) {
    if(sameSet(i, j)) {
        return;
    }

    nSets--;
    char a = getSet(i), b = getSet(j);

    if(r[a] < r[b]) {
        p[a] = b;
        sizes[b] += sizes[a];
    } else {
        p[b] = a;
        sizes[a] += sizes[b];

        if(r[a] == r[b]) {
            r[a]++;
        }
    }
}

int t;
vector<pair<char, char>> edges;
string s;

int main() {
    sc(t);
    getline(cin, s);
    while(t--) {
        edges.clear();
        while(getline(cin, s) && s[0] != '*') {
            edges.pb({s[1], s[3]});
        }
        
        getline(cin, s);
        init();

        for(auto c : s) {
            if(c != ',') {
                getSet(c);
            }
        }

        for(auto e : edges) {
            joinSet(e.ff, e.ss);
        }

        int acorns = 0;
        for(auto pp : p) {
            if(pp.ff == pp.ss && sizes[pp.ff] == 1) {
                acorns++;
            }
        }
        cout << "There are " << nSets-acorns << " tree(s) and " << acorns << " acorn(s)." << endl;
    }


    return 0;
}