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
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef queue<ll>qll;typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
typedef vector<pair<ll,ll>>vpll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*** Swapping ***/
void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/
void add_edge(vll adj[], ll src, ll dest) {
    adj[src].pb(dest);
    adj[dest].pb(src);
}


bool BFS(vll adj[], ll src, ll dest, ll v, ll pred[], ll dist[]) 
{ 
    
    list<ll> queue; 
  
    bool visited[v]; 
  
    for (ll i = 0; i < v; i++) { 
        visited[i] = false; 
        dist[i] = LONG_LONG_MAX; 
        pred[i] = -1; 
    } 
  
    visited[src] = true; 
    dist[src] = 0; 
    queue.push_back(src); 

    while (!queue.empty()) { 
        ll u = queue.front(); 
        queue.pop_front(); 
        for (ll i = 0; i < adj[u].size(); i++) { 
            if (visited[adj[u][i]] == false) { 
                visited[adj[u][i]] = true; 
                dist[adj[u][i]] = dist[u] + 1; 
                pred[adj[u][i]] = u; 
                queue.push_back(adj[u][i]); 
   
                if (adj[u][i] == dest) 
                    return true; 
            } 
        } 
    } 
  
    return false; 
} 

vll shortestDistance(vll adj[], ll s, ll dest, ll v) 
{ 
    
    ll pred[v], dist[v]; 
  
    vector<ll> path; 
    if (BFS(adj, s, dest, v, pred, dist) == false) { 
        return path; 
    } 
  
    ll crawl = dest; 
    path.push_back(crawl); 
    while (pred[crawl] != -1) { 
        path.push_back(pred[crawl]); 
        crawl = pred[crawl]; 
    } 

    return path;
} 

void solve() {
    ll n, q;
    sc(n);
    sc(q);

    vll v(n, 0);
    forIn(v, n);

    ll vertices = n + 1;
    vll adj[vertices];
    
    ll src, dest;
    f(i, 0, n - 1) {
        sc(src);
        sc(dest);

        add_edge(adj, src, dest);
    }

    f(i, 0, q) {
        sc(src);
        sc(dest);

        vll path = shortestDistance(adj, src, dest, vertices);

        if(!path.empty()) {
            vll temp;
            f(j, 0, path.size()) {
                temp.pb(v[path[j] - 1]);
            }

            ll small = LONG_LONG_MAX;
            srt(temp);
            f(i, 0, temp.size() - 1) {
                small = min(small, abs(temp[i] - temp[i + 1]));
            }

            pf(small);
        }
    }
}

int main() {
    FAST_IO
    ll t;
    sc(t);

    while(t--) {
        solve();
    }
    return 0;
}