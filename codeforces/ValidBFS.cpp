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
int a[200010],lev[200010],idx[200010],x[200010],y[200010];
bool vis[200010];
vector<pair<int,int>>v[200010];
vector<int>node;

void bfs(int s){
    vis[s]=1;
    queue<int>q;
    q.push(s);
    node.push_back(s);
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int j=0;j<v[top].size();j++){
            if(!vis[v[top][j].second]){
                vis[v[top][j].second]=1;
                q.push(v[top][j].second);
                node.push_back(v[top][j].second);
            }
        }
    }
}

void solve() {
    ll n;
    sc(n);
    f(i, 1, n) {
        sc(x[i]);
        sc(y[i]);
    }

    f(i, 0, n) {
        sc(a[i]);
        idx[a[i]] = i;
    }

    f(i, 1, n) {
        v[x[i]].pb({idx[y[i]], y[i]});
        v[y[i]].pb({idx[x[i]], x[i]});
    }

    f(i, 1, n + 1) {
        srt(v[i]);
    }

    bfs(1);
    int flag = 0;
    f(i, 0, n) {
        if(node[i] != a[i]) {
            flag = 1;
            break;
        }
    }

    if(flag) {
        no;
    } else {
        yes;
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}