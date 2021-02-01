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
void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    if(k == 2) {
        string p = "";
        for(int i = 0;i < n;i++) {
            if(i & 1) {
                p += 'A';
            } else {
                p += 'B';
            }
        }

        string q = "";
        for(int i = 0;i < n;i++) {
            if(i & 1) {
                q += 'B';
            } else {
                q += 'A';
            }
        }

        int chngP = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] != p[i]) chngP++;
        }

        int chngQ = 0;
        for(int i = 0;i < n;i++) {
            if(s[i] != q[i]) chngQ++;
        }

        if(chngP >= chngQ) {
            pf(chngQ);
            pf(q);
        } else {
            pf(chngP);
            pf(p);
        }

        return;
    }

    int changes = 0;
    for(int i = 1;i < n;i++) {
        if(s[i] == s[i - 1]) {
            if(i == n - 1) {
                changes++;
                s[i] = (char) (s[i] - 65 + 1) % k + 65;
            } else {
                if(s[i - 1] == s[i + 1]) {
                    changes++;
                    s[i] = (char)(s[i] - 65 + 1) % k + 65;
                } else {
                    int mx = max(int(s[i - 1]), (int)s[i + 1]);
                    s[i] = (char) (mx - 65 + 1) % k + 65;
                    changes++;
                    if(s[i] == s[i - 1] || s[i] == s[i + 1]) {
                        s[i] = (char)(s[i] - 65 + 1) % k + 65;
                    }
                }
            }
        }
    }

    pf(changes);
    pf(s);
}

int main() {
    go();
    ssolve
    return 0;
}
