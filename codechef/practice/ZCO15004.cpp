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
ll lefti[300005], righti[300005];
stack<ll> left_stack, right_stack;

void solve() {
    ll n;
    sc(n);

    vector<pll> points(n);
    f(i, 0, n) {
        sc(points[i].ff);
        sc(points[i].ss);
    }

    for(int i = 0; i <= 100000; i++)
        points.push_back({i, 500});

    n += 100001;

    sort(points.begin(), points.end());

    lefti[0] = -1;
    left_stack.push(0);
    right_stack.push(n-1);
    for(int i = 1; i < n; i++){

        while(!left_stack.empty() and (points[left_stack.top()].second >= points[i].second or points[left_stack.top()].second == 0))
            left_stack.pop();
        if(left_stack.empty())
            lefti[i] = -1;
        else
            lefti[i] = left_stack.top();
        left_stack.push(i);
    }

    righti[n-1] = -1;
    for(int i = n-2; i >= 0; i--){

        while(!right_stack.empty() and (points[right_stack.top()].second >= points[i].second or points[right_stack.top()].second == 0))
            right_stack.pop();
        if(right_stack.empty())
            righti[i] = -1;
        else
            righti[i] = right_stack.top();
        right_stack.push(i);
    }

    ll sol = -1;
    int left_width, right_width;
    for(int i = 0; i < n; i++){
        ll height  = points[i].second;
        if(lefti[i] != -1)
            left_width = points[lefti[i]].first;
        else
            left_width = 0;
        if(righti[i] != -1)
            right_width = points[righti[i]].first;
        else
            right_width = 100000;
        sol = max(sol, height*(right_width - left_width));
    }

    pf(sol);
}

int main() {
    FAST_IO
    solve();
    return 0;
}