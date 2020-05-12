#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main() {
    int queries;
    cin >> queries;

    ll sticks;
    while(queries--) {
        cin >> sticks;

        if(sticks <= 4) {
            cout << (4 - sticks) << endl;
        } else {
            if(sticks % 2 == 0) {
                cout << "0" << endl;
            } else {
                cout << "1" << endl;
            }
        }
    }
    return 0;
}