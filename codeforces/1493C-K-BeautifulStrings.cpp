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
int get(int x, int k) {
    return (k - x % k) % k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cnt[26] = {0};
    for(char c : s) cnt[c - 'a']++;

    int sum = 0, flag = 1;
    for(int i = 0;i < 26;i++) {
        sum += get(cnt[i], k);
    }

    if(sum == 0) {
        pf(s);
        return;
    }

    if(n % k) {
        pf(-1);
        return;
    }

    for(int i = n - 1; i >= 0 && flag; --i) {
        sum -= get(cnt[s[i] - 'a'], k);
        cnt[s[i] - 'a']--;
        sum += get(cnt[s[i] - 'a'], k);
        for (int j = s[i] - 'a' + 1; j < 26; ++j) {

            int lst_sum = sum;
            sum -= get(cnt[j], k);
            cnt[j]++;
            sum += get(cnt[j], k);

            if (i + sum + 1 <= n) {
                for (int pos = 0; pos < i; ++pos) {
                    cout << s[pos];
                }
                cout << char('a' + j);

                string add = "";
                for (int w = 0; w < 26; ++w) {
                    int f = get(cnt[w], k);
                    while (f) {
                        f--;
                        add += char('a' + w);
                    }
                }
                while ((int)add.size() + i + 1 < n) {
                    add += "a";
                }

                sort(add.begin(), add.end());
                cout << add << '\n';
                flag = 0;
                break;
            }

            cnt[j]--;
            sum = lst_sum;
        }
    }
}

int main() {
    go();
    msolve
    return 0;
}
