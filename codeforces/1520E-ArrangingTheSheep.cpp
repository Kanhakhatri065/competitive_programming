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
#ifdef LOCAL
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;

    string s;cin >> s;

    if(count(all(s), '*') <= 1) {
        pf(0);
        return;
    }

    ll ans = 0;
    vector<int> store;
    for(int i = 0;i < n;i++) {
        if(s[i] == '*') store.pb(i);
    }

    int num = sz(store);

    if(num & 1) {
        int mid = num / 2;
        ll cnt = 0;
        int pos = store[mid] + 1;
        for(int i = mid + 1;i < num;i++) {
            cnt += (store[i] - pos);
            pos++;
        }

        pos = store[mid] - 1;
        for(int i = mid - 1;i >= 0;i--) {
            cnt += (pos - store[i]);
            pos--;
        }

        ans = cnt;
    } else {
        int mid = num / 2;
        ll cnt = 0;
        int pos = store[mid] + 1;
        for(int i = mid + 1;i < num;i++) {
            cnt += (store[i] - pos);
            pos++;
        }

        pos = store[mid] - 1;
        for(int i = mid - 1;i >= 0;i--) {
            cnt += (pos - store[i]);
            pos--;
        }

        ans = cnt;
        cnt = 0;
        mid = mid - 1;
        pos = store[mid] + 1;
        for(int i = mid + 1;i < num;i++) {
            cnt += (store[i] - pos);
            pos++;
        }

        pos = store[mid] - 1;
        for(int i = mid - 1;i >= 0;i--) {
            cnt += (pos - store[i]);
            pos--;
        }

        ckmin(ans, cnt);
    }

    pf(ans);
}

int main() {
    go();
    int t;cin >> t;
    while(t--) solve();
    return 0;
}