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
const int N = 105;
/*-------------- Push your limits here ---------------------------*/
map<char, char> valid_reflections;

void solve() {
    int h, m;
    cin >> h >> m;

    string query;
    cin >> query;
    int qh = stoi(query.substr(0, 2));
    int qm = stoi(query.substr(3, 2));

    string nex = "00:00";
    string ans = "";
    for(int i = h - 1;i >= 0;i--) {
        for(int j = m - 1;j >= 0;j--) {
            string time = i > 9 ? to_string(i) : "0" + to_string(i);
            time += ':';
            time += j > 9 ? to_string(j) : '0' + to_string(j);
            bool flag = true;
            string tmp = time;
            reverse(all(time));
            for(int k = 0;k < sz(time);k++) {
                if(time[k] == ':') continue;
                if(valid_reflections.find(time[k]) != valid_reflections.end()) {
                    time[k] = valid_reflections[time[k]];
                } else {
                    flag = false;
                    break;
                }
            } 

            if(!flag) {
                if(i == qh && j == qm) {
                    ans = nex;
                }
                continue;
            }

            int th = 0;
            th = th * 10 + (time[0] - '0');
            th = th * 10 + (time[1] - '0');

            int tm = 0;
            tm = tm * 10 + (time[3] - '0');
            tm = tm * 10 + (time[4] - '0');

            if(th < h && tm < m) {
                nex = tmp;
            }

            if(i == qh && j == qm) {
                ans = nex;
                break;
            }
        }

        if(ans != "") break;
    }

    pf(ans);
}

int main() {
    valid_reflections['0'] = '0';
    valid_reflections['1'] = '1';
    valid_reflections['2'] = '5';
    valid_reflections['5'] = '2';
    valid_reflections['8'] = '8';
    go();
    msolve
    return 0;
}
