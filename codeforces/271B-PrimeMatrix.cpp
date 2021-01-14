/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
using ll = long long;
using pi = pair<int, int>;
/*-----in and out--------*/
#define pf(a) cout << a << endl
#define forIn(arr, num) for(int i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(int i = 0; i < int(ans.size()); i++) cout << ans[i] << (i + 1 < int(ans.size()) ? ' ' : '\n');
/*---useful defines------*/
#define sz(x) (int)(x).size()
#define pb push_back
#define mem(a, b) memset(a,(b), sizeof(a))
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
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
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
/*--------test-stuff--------------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
/*-------------- Push your limits here ---------------------------*/
bool sieve[N];
int nearest_prime[N];
void precomputation() {
    mem(sieve, true);
    sieve[0] = sieve[1] = false;
    for(int i = 2;i < N;i++) if(sieve[i]) for(int j = 2 * i;j < N;j += i) sieve[j] = false;

    int idx = 1e6;
    while(sieve[idx] == false) idx--;
    
    int cnt = 0;
    for(int i = idx;i >= 1;i--) {
        sieve[i] == true ? cnt = 0 : cnt++;
        nearest_prime[i] = cnt;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) cin >> arr[i][j];

    int mn_row = -1;
    for(int i = 0;i < n;i++) {
        int sum = 0;
        for(int j = 0;j < m;j++) sum += nearest_prime[arr[i][j]];

        mn_row == -1 ? mn_row = sum : mn_row = min(mn_row, sum);
    }

    int mn_col = -1;
    for(int i = 0;i < m;i++) {
        int sum = 0;
        for(int j = 0;j < n;j++) sum += nearest_prime[arr[j][i]];
        mn_col == -1 ? mn_col = sum : mn_col = min(mn_col, sum);
    }

    pf(min(mn_col, mn_row));
}

int main() {
    go();
    precomputation();
    ssolve
    return 0;
}