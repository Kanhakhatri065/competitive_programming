#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll count = 0;
    count += (2 * c);
    if(a > b) {
        count += ((2 * b) + 1);
    } else if(a < b){
        count += ((2*a) + 1);
    } else {
        count += (2 * a);
    }

    cout << count << endl;

    return 0;
}