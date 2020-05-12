#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;
    
    int b, p, f, h, c;
    while(testcases--) {
        cin >> b >> p >> f >> h >> c;
        long long int total = 0;

        int burgers_possible = b / 2;
        if(h > c) {
            if(p > burgers_possible) {
                total += burgers_possible * h;
                burgers_possible = 0;
            } else {
                total += p * h;
                burgers_possible -= p;
            }

            if(burgers_possible > 0) {
                if(f > burgers_possible) {
                    total += burgers_possible * c;
                    burgers_possible = 0;
                } else {
                    total += f * c;
                    burgers_possible -= f;
                }
            }
        } else {
            if(f > burgers_possible) {
                total += burgers_possible * c;
                burgers_possible = 0;
            } else {
                total += f * c;
                burgers_possible -= f;
            }

            if(burgers_possible > 0) {
                if(p > burgers_possible) {
                    total += burgers_possible * h;
                    burgers_possible = 0;
                } else {
                    total += p * h;
                    burgers_possible -= p;
                }
            }
        }

        cout << total << endl;
    }

    return 0;
}