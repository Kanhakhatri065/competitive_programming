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

int n;
int segmentID;
char ch;
char type[N];
int l[N], r[N], who[N], c[N];
int ftree[2][N];
vector<int> dat;

void add(int *ft, int pos, int val) {
    while(pos < N) {
        ft[pos] += val;
        pos += pos & (-pos);
    }
}

int get(int *ft, int pos) {
    int sum = 0;
    while(pos > 0) {
        sum += ft[pos];
        pos -= pos & (-pos);
    }

    return sum;
}

void solve() {
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> type[i];
        if(type[i] == 'C') {
            cin >> c[i];
        } else if(type[i] == 'D') {
            cin >> l[i] >> r[i];
            who[++segmentID] = i;
        } else {
            cin >> l[i] >> r[i];
        }
    }

    dat = vector<int>(l, l + n);
    dat.insert(dat.end(), r, r + n);
    sort(all(dat));
    dat.erase(unique(all(dat)), dat.end());

    for(int i = 0;i < n;i++) {
        if(type[i] != 'c') {
            l[i] = lower_bound(all(dat), l[i]) - dat.begin();
            r[i] = lower_bound(all(dat), r[i]) - dat.begin();
        }
    }

    int ans = 0;
    for(int i = 0;i < n;i++) {
        if(type[i] == 'D') {
            add(ftree[0], l[i], 1);
            add(ftree[1], r[i], 1);
            ans++;
        } else if(type[i] == 'C') {
            int id = who[c[i]];
            add(ftree[0], l[id], -1);
            add(ftree[1], r[id], -1);
            ans--;
        } else {
            int res = get(ftree[0], r[i]) - get(ftree[1], l[i] - 1);
            pf(res);
        }
    }
}

int main() {
    go();
    int t = 1;
    while(t--) solve();
    return 0;
}