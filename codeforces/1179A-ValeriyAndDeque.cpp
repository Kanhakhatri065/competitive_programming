/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
void solve() {
    int n, q;
    cin >> n >> q;
    deque<int> d;
    int maxValue = -1;
    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        d.push_back(a_i);
        maxValue = max(maxValue, a_i);
    }
 
    map<int, pair<int, int>> answer;
 
    int maxIndex = 0;
    while (true) {
        /// showDeque(d);
        int first = d.front();
        d.pop_front();
        int second = d.front();
        d.pop_front();
 
        if (first == maxValue) {
            d.push_front(second);
            d.push_front(first);
            break;
        }
 
        maxIndex++;
        answer[maxIndex] = {first, second};
 
        if (second > first) {
            swap(first, second);
        }
 
        d.push_front(first);
        d.push_back(second);
    }
 
    int a[n];
    /// showDeque(d);
    for (int i = 0; i < n; i++) {
        a[i] = d.front();
        d.pop_front();
    }
 
    for (int i = 0; i < q; i++) {
        ll m_j;
        cin >> m_j;
        if (m_j <= maxIndex) {
            cout << answer[m_j].first << " " << answer[m_j].second << '\n';
        } else {
            cout << maxValue << " " << a[(m_j - (maxIndex + 1)) % (n - 1) + 1] << '\n';
        }
    }
}

int main() {
    go();
    solve();
    return 0;
}