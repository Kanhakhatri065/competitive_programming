#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int n, m;
    while(testcases--) {
        cin >> n >> m;

        vector<int> v(n, 0);
        for(int i = 0;i < n;i++) {
            cin >> v[i];
        }

        long long int sum = 0;
        sum = accumulate(v.begin(), v.end(), sum);

        if(sum <= m) {
            cout << sum << endl;
        } else {
            cout << m << endl;
        }

    }
    return 0;
}