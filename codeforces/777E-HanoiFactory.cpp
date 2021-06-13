#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pf(a) cout << a << endl
#define sz(x) (int)(x).size()
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void go() {
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    vector<array<int, 3>> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i][1] >> arr[i][0] >> arr[i][2];

    sort(all(arr));

    stack<ll> st;
    ll cnt = 0, ans = 0;
    for(int i = n - 1;i >= 0;i--) {
        while(!st.empty() && arr[i][0] <= arr[st.top()][1]) {
            cnt = cnt - arr[st.top()][2];
            st.pop();
        }

        st.push(i);
        cnt += arr[i][2];
        ckmax(ans, cnt);
    }

    pf(ans);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}
