#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    ll n, k1, k2;
    while(testcases--) {
        cin >> n >> k1 >> k2;

        
        
        vector<ll> first(k1, 0);
        for(int i = 0;i < k1;i++) {
            cin >> first[i];
        }

        vector<ll> second(k2, 0);
        for(int i = 0;i < k2;i++) {
            cin >> second[i];
        }

        int first_largest = *max_element(first.begin(), first.end());

        if(first_largest == n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        /*
        sort(first.begin(), first.end(), greater<ll>());
        sort(second.begin(), second.end(), greater<ll>());

        if(first[0] > second[0]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        */
    }

    return 0;
}