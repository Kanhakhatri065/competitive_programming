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
const int N = 2e5 + 5;
/*-------------- Push your limits here ---------------------------*/
void solve() {
    string number, type;
    cin >> number >> type;

    reverse(all(number));
    string x = "";
    vector<vector<int>> store;
    for(int i = 0;i < sz(type);i++) {
        if(type[i] == '-') {
            int p = stoi(x);
            vector<int> tmp;
            while(p--) {
                tmp.push_back(number.back() - '0');
                number.pop_back();
            }

            store.pb(tmp);
            x = "";
        } else {
            x += type[i];
        }
    }

    if(sz(x) > 0) {
        int p = stoi(x);
        vector<int> tmp;
        while(p--) {
            tmp.push_back(number.back() - '0');
            number.pop_back();
        }

        store.pb(tmp);
        x = "";
    }

    map<int, string> mp;
    mp[2] = "double";
    mp[3] = "triple";
    mp[4] = "quadruple";
    mp[5] = "quintuple";
    mp[6] = "sextuple";
    mp[7] = "septuple";
    mp[8] = "octuple";
    mp[9] = "nonuple";
    mp[10] = "decuple";
    map<int, string> num_to_str;
    num_to_str[0] = "zero";
    num_to_str[1] = "one";
    num_to_str[2] = "two";
    num_to_str[3] = "three";
    num_to_str[4] = "four";
    num_to_str[5] = "five";
    num_to_str[6] = "six";
    num_to_str[7] = "seven";
    num_to_str[8] = "eight";
    num_to_str[9] = "nine"; 

    string ans = "";
    for(vector<int> it : store) {
        int cnt = 1;
        int num = it[0];
        for(int i = 1;i < sz(it);i++) {
            if(it[i] != it[i - 1]) {
                if(cnt < 2 || cnt > 10) {
                    while(cnt--) {
                        ans += num_to_str[num];
                        ans += " ";
                    }
                } else {
                    ans += mp[cnt];
                    ans += " ";
                    ans += num_to_str[num];
                    ans += " ";
                }

                cnt = 1;
                num = it[i];
            } else {
                cnt++;
            }
        }

        if(cnt < 2 || cnt > 10) {
            while(cnt--) {
                ans += num_to_str[num];
                ans += " ";
            }
        } else {
            ans += mp[cnt];
            ans += " ";
            ans += num_to_str[num];
            ans += " ";
        }
    }

    pf(ans);
}

int main() {
    go();
    mcsolve
    return 0;
}
