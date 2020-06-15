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
const int n = 7;
bool visited[7][7];
int reserved[49];

void move(int r, int c, ll &ans, ll &steps) {
    if(r == n - 1 && c == 0) {
        ans += (steps == n * n - 1);
        return;
    }

    if(((r + 1 == n || (visited[r - 1][c] && visited[r + 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) ||
        ((c + 1 == n || (visited[r][c - 1] && visited[r][c + 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && ! visited[r + 1][c]) ||
        ((r == 0 || (visited[r + 1][c] && visited[r - 1][c])) && c - 1 >= 0 && c + 1 < n && !visited[r][c - 1] && !visited[r][c + 1]) || 
        ((c == 0 || (visited[r][c + 1] && visited[r][c - 1])) && r - 1 >= 0 && r + 1 < n && !visited[r - 1][c] && !visited[r + 1][c])) {
        return;
    }

    visited[r][c] = true;
    if(reserved[steps] != -1) {
        switch(reserved[steps]) {
            case 0:
                if(r - 1 >= 0) {
                    if(!visited[r - 1][c]) {
                        steps++;
                        move(r - 1, c, ans, steps);
                        steps--;
                    }
                }
            break;

            case 1:
                if(c + 1 < n) {
                    if(!visited[r][c + 1]) {
                        steps++;
                        move(r, c + 1, ans, steps);
                        steps--;
                    }
                }
            break;

            case 2:
                if(r + 1 < n) {
                    if(!visited[r + 1][c]) {
                        steps++;
                        move(r + 1, c, ans, steps);
                        steps--;
                    }
                }
            break;

            case 3:
                if(c - 1 >= 0) {
                    if(!visited[r][c - 1]) {
                        steps++;
                        move(r, c - 1, ans, steps);
                        steps--;
                    }
                }
            break;
        }
        visited[r][c] = false;
        return;
    }

    if(r + 1 < n) {
        if(!visited[r + 1][c]) {
            steps++;
            move(r + 1, c , ans, steps);
            steps--;
        }
    }

    if(c + 1 < n) {
        if(!visited[r][c + 1]) {
            steps++;
            move(r, c + 1, ans, steps);
            steps--;
        }
    }

    if(r - 1 >= 0) {
        if(!visited[r - 1][c]) {
            steps++;
            move(r - 1, c, ans, steps);
            steps--;
        }
    }

    if(c - 1 >= 0) {
        if(!visited[r][c - 1]) {
            steps++;
            move(r, c - 1, ans, steps);
            steps--;
        }
    }

    visited[r][c] = false;
}


void solve() {
    string path;
    sc(path);

    f(i, 0, path.length()) {
        if(path[i] == '?') {
            reserved[i] = -1;
        } else if(path[i] == 'U') {
            reserved[i] = 0;
        } else if(path[i] == 'R') {
            reserved[i] = 1;
        } else if(path[i] == 'D') {
            reserved[i] = 2;
        } else if(path[i] == 'L') {
            reserved[i] = 3;
        }
    }

    ll ans = 0, steps = 0;
    move(0, 0, ans, steps);
    pf(ans);
}

int main() {
    FAST_IO
    solve();
    return 0;
}