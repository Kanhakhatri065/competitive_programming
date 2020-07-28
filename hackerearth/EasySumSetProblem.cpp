#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    int c[m];
    for(int i = 0;i < m;i++) {
        cin >> c[i];
    }

    for(int x = 0;x <= 100;x++) {
        int count = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(x == c[j] - a[i]) {
                    count++;
                    break;
                }
            }
        }

        if(count == n) {
            cout << x << " ";
        }
    }
    return 0;
}