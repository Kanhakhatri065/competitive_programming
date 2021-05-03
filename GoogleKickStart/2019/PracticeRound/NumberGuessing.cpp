#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    while(true) {
        int mid = (a + b + 1) >> 1;
        cout << mid << endl;
        string msg;cin >> msg;
        if(msg == "TOO_SMALL") {
            a = mid;
        } else if(msg == "TOO_BIG") {
            b = mid - 1;
        } else if(msg == "CORRECT") {
            break;
        } else {
            exit(0);
        }
    }
}

int main() {
    int t;cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}