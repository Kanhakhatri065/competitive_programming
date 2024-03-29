/*
	I love the sound you make when you shut up.
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
/*----typedefs--------*/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
int n, m, K, a[15];
bool b[N];
double c1[N], c2[N];
void add(double *c, int p, double v) {
    while(p <= n + m) {
        c[p] += v;
        p += (p & (-p));
    }
}

double ask(double *c, int p) {
    double s = 0;
    while(p) {
        s += c[p];
        p -= (p & (-p));
    }

    return s;
}

void solve() {
    cin >> n >> m >> K;

    for(int i = 1;i <= K;i++) {
        cin >> a[i];
        b[a[i]] = true;
    }

    if(m <= K) {
        for(int i=1;i+m-1<=K;++i) {
            bool flg=1;
            for(int j=1;j<m;++j)
                if(a[i+j-1]+1!=a[i+j])
                    flg=0;
            if(flg) {
                pf(-1);
                return;
            }
        }  
    }

    for(int i = n - 1;i;i--) {
        if(b[i]) {
            add(c1, i, 1);
        } else {
            add(c1, i, ask(c1, i + m) / m);
            add(c2, i, ask(c2, i + m) / m + 1);
        }
    }

    double k = ask(c1, m) / m, d = ask(c2, m) / m + 1;
    cout << fixed << setprecision(4) << (d / (1 - k)) << endl;
}

int main() {
    //go();
    ssolve
    return 0;
}
