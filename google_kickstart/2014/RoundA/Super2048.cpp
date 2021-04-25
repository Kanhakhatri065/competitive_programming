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
    int n;
    cin >> n;

    string direction;
    cin >> direction;

    int arr[n][n];
    for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) {
        cin >> arr[i][j];
    }

    if(direction == "up") {
        for(int i = 0;i < n;i++) {
            deque<int> store;
            for(int j = 0;j < n;j++) {
                if(arr[j][i] != 0) {
                    store.pb(arr[j][i]);
                    arr[j][i] = 0;
                }
            }

            int idx = 0;
            while(!store.empty()) {
                if(sz(store) > 1) {
                    int x = store.front(); 
                    store.pop_front();
                    int y = store.front();
                    store.pop_front();

                    if(x == y) {
                        arr[idx][i] = x + y;
                        idx++;
                    } else {
                        arr[idx][i] = x;
                        idx++;
                        store.push_front(y);
                    }
                } else {
                    arr[idx][i] = store.front();
                    store.pop_front();
                }
            }
        }
    } else if(direction == "down") {
        for(int i = 0;i < n;i++) {
            deque<int> store;
            for(int j = n - 1;j >= 0;j--) {
                if(arr[j][i] != 0) {
                    store.push_back(arr[j][i]);
                    arr[j][i] = 0;
                }
            }

            int idx = n - 1;
            while(!store.empty()) {
                if(sz(store) > 1) {
                    int x = store.front();
                    store.pop_front();
                    int y = store.front();
                    store.pop_front();

                    if(x == y) {
                        arr[idx--][i] = x + y;
                    } else {
                        arr[idx--][i] = x;
                        store.push_front(y);
                    }
                } else {
                    arr[idx--][i] = store.front();
                    store.pop_front();
                }
            }
        }
    } else if(direction == "left") {
        deque<int> store;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if(arr[i][j] != 0) {
                    store.push_back(arr[i][j]);
                    arr[i][j] = 0;
                }
            }

            int idx = 0;
            while(!store.empty()) {
                if(sz(store) > 1) {
                    int x = store.front();
                    store.pop_front();
                    int y = store.front();
                    store.pop_front();
                    if(x == y) {
                        arr[i][idx++] = x + y;
                    } else {
                        arr[i][idx++] = x;
                        store.push_front(y);
                    }
                } else {
                    arr[i][idx++] = store.front();
                    store.pop_front();
                }
            }
        }
    } else {
        for(int i = 0;i < n;i++) {
            deque<int> store;
            for(int j = n - 1;j >= 0;j--) {
                if(arr[i][j] != 0) {
                    store.push_back(arr[i][j]);
                    arr[i][j] = 0;
                }
            }

            int idx = n - 1;
            while(!store.empty()) {
                if(sz(store) > 1) {
                    int x = store.front();
                    store.pop_front();
                    int y = store.front();
                    store.pop_front();

                    if(x == y) {
                        arr[i][idx--] = x + y;
                    } else {
                        arr[i][idx--] = x;
                        store.push_front(y);
                    }
                } else {
                    arr[i][idx--] = store.front();
                    store.pop_front();
                }
            }
        }
    }

    cout << endl;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    go();
    mcsolve
    return 0;
}
