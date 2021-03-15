/*
    I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
/*-------typedefs------*/
template<class T> using ordered_set = tree<T, null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update> ;
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
/*-------- test-case stuff--------------*/
#define ssolve solve();
#define msolve int T;cin >> T;while(T--) {solve();}
#define mcsolve int T;cin >> T;for(int tt = 1;tt <= T;tt++) {cout << "Case #" << tt << ": ";solve();}
/*-------- movement in a 2D array ------*/
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
/*----------------------------------------------------------------*/
const int MOD = 1e9 + 7;
const int N = 1e7;
/*-------------- Push your limits here ---------------------------*/
bool sieve[N];
int bigger_prime[N];
void precomputation() {
    mem(sieve, true);
    sieve[0] = sieve[1] = false;
    for(int i = 2;i < N;i++) {
        if(sieve[i]) {
            for(int j = 2 * i;j < N;j += i) sieve[j] = false;
        }
    }

    int idx = -1;
    for(int i = N - 1;i >= 1;i--) {
        if(sieve[i]) {
            idx = i;
            break;
        }
    }

    bigger_prime[idx] = idx;
    for(int i = idx - 1;i >= 1;i--) {
        if(sieve[i]) {
            bigger_prime[i] = i;
        } else {
            bigger_prime[i] = bigger_prime[i + 1];
        }
    }
}

void solve() {
    int l, r;
    cin >> l >> r;

    if(sieve[r]) {
        pf(bigger_prime[r + 1]);
    } else {
        pf(bigger_prime[r]);
    }
}

int main() {
    go();
    precomputation();
    msolve
    return 0;
}
