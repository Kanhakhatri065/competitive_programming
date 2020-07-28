#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

/*
int main() {
    long long int size, operations;
    cin >> size >> operations;

    vector<ll> v(size, 0);
    for(ll i = 0;i < size;i++) {
        cin >> v[i];
    }

    if(operations > size) {
        cout << "-1" << endl;
    } else {
        long long int last_max = v[0];
        v.erase(v.begin());

        ll temp;
        for(long long int i = 1;i < operations;i++) {
            temp = v[0];

            v.erase(v.begin());

            if(temp > last_max) {
                last_max = temp;
            }
        }

        cout << last_max << endl;
    }
    return 0;
}
*/

int main() {
    ll size, operations;
    cin >> size >> operations;

    ll m = 0;

    ll arr[size];
    for(ll i = 0;i < size;i++) {
        cin >> arr[i];
        m = max(arr[i], m);
    }

    if(operations == size || (size == 1 && operations % 2 == 1)) {
        cout << "-1 " << endl;
    } else if(operations > size + 1) {
        cout << m << endl;
    } else {
        m = -1;
        for(ll i = 0;i < operations - 1;i++) {
            m = max(m, arr[i]);
        }
        cout << m << endl;
    }

    return 0;
}