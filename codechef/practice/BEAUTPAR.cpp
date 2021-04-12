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
const ll INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
/*-------------- Push your limits here ---------------------------*/
vector<ll> LIS(const vector<ll> &elements) {
    // declare the set with a custom comparison function
    // that compares values instead of indices
    auto compare = [&](ll x, ll y) { return elements[x] < elements[y]; };
    set<ll, decltype(compare)> S(compare);

    // process the elements; for each length
    // maintain the index of the best end so far
    vector<ll> previous(elements.size(), -1);
    for (ll i = 0; i < elements.size(); ++i) {
        auto it = S.insert(i).first;
        if (it != S.begin())
            previous[i] = *prev(it);
        if (*it == i && next(it) != S.end())
            S.erase(next(it));
    }

    // reconstruct the indices that form
    // one possible optimal answer
    vector<ll> answer;
    answer.push_back(*S.rbegin());
    while (previous[answer.back()] != -1)   answer.push_back(previous[answer.back()]);
    reverse(answer.begin(), answer.end());
    return answer;
}
void solve() {
    ll n, k;
        cin >> n >> k;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i], a[i] += a[i - 1];
        for (ll i = 1; i < n; i++)
            if (a[i] < 0)
                a[i] = 0;
            else if (a[i] > a[n])
                a[i] = a[n];
        if (a[n] < k) {
            no;
            return;
        }
        auto lis = LIS(a);
        lis[0] = 0;
        if (lis.size() > k)
        {
            yes;
            for (ll i = 1; i < k; i++)
                cout << lis[i] - lis[i - 1] << ' ';
            cout << n - lis[k - 1] << '\n';
        }
        else {
            no;
        }
}

int main() {
    go();
    msolve
    return 0;
}
