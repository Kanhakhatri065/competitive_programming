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
const int N = 1e6 + 5;
const int BLOCK = 200;

struct query {
    int l, r, i;
};

vector<int> a;
vector<query> v;
vector<int> ans;
vector<int> cnt;

bool cmp(query a, query b) {
    if(a.l / BLOCK != b.l / BLOCK) {
        return a.l < b.l;
    }

    return a.r < b.r;
}

int answer = 0;
void add(int i) {
    cnt[a[i]]++;
    if(cnt[a[i]] == 1) answer++;
}

void remove(int i) {
    cnt[a[i]]--;
    if(cnt[a[i]] == 0) answer--;
}

void solve() {
    int n;cin >> n;
    a.resize(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    int q;cin >> q;
    for(int i = 0;i < q;i++) {
        int l, r;cin >> l >> r;
        l--, r--;
        v.pb({l, r, i});
    }

    sort(all(v), cmp);

    ans.resize(q);
    cnt.assign(N, 0);
    int curl = 0, curr = 0, l, r;
    add(0);
    for(int i = 0;i < q;i++) {
        l = v[i].l, r = v[i].r;
        while(curl < l) {
            remove(curl);
            curl++;
        }

        while(curl > l) {
            add(curl - 1);
            curl--;
        }

        while(curr < r) {
            add(curr + 1);
            curr++;
        }

        while(curr > r) {
            remove(curr);
            curr--;
        }

        ans[v[i].i] = answer;
    }

    for(int i = 0;i < n;i++) pf(ans[i]);
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}