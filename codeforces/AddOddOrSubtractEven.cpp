#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int a, b;
    while(testcases--) {
        cin >> a >> b;

        long long int count = 0;
        while(a != b) {
            if(b > a && ((b - a) % 2 != 0)) {
                a += (b - a);
                count++;
            }
            
            if(b > a && ((b - a) % 2 == 0)) {
                a += ((b - a) - 1);
                count++;
            }
            
            if(b < a && ((a - b) % 2 == 0)) {
                a -= (a - b);
                count++;
            }
            
            if(b < a && ((a - b) % 2 != 0)) {
                a -= ((a -b) + 1);
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}