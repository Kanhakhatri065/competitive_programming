#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b, c;
    
    int total = 0;
    while(n--) {
        cin >> a >> b >> c;

        int count = a + b + c;

        if(count >= 2) {
            total++;
        }
    }

    cout << total << endl;
    
    return 0;
}