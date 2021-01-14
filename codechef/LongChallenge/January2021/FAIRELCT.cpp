#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<int> b(m);
    for(int &x : b) cin >> x;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    int sum_a = accumulate(a.begin(), a.end(), 0);
    int sum_b = accumulate(b.begin(), b.end(), 0);

    int cnt = 0;
    bool flag = false;
    for(int i = 0;i < n;i++) {
        if(sum_a > sum_b) {
            flag = true;
            break;
        }

        sum_a -= a[i];
        sum_b -= b[i];
        
        sum_a += b[i];
        sum_b += a[i];
        cnt++;
    }

    if(sum_a > sum_b) {
        flag = true;
    }

    if(flag) {
        cout << cnt << endl;
    } else {
        cout << (-1) << endl;
    }
}


int main() {
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
