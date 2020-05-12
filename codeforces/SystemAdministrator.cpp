#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count_a = 0;
    int count_b = 0;

    int x_a = 0;
    int x_b = 0;

    int t, x, y;
    for(int i = 0;i < n;i++) {
        cin >> t >> x >> y;
        if(t == 1) {
            count_a++;
            x_a += x;
        } else {
            count_b++;
            x_b += x;
        }
    }

    if(x_a >= count_a * 5) {
        cout << "LIVE" << endl;
    } else {
        cout << "DEAD" << endl;
    }

    if(x_b >= count_b * 5) {
        cout << "LIVE" << endl;
    } else {
        cout << "DEAD" << endl;
    }
    
    return 0;
}