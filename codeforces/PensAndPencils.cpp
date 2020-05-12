#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int lectures, practicals, pens, pencils, k;
    while(testcases--) {
        cin >> lectures >> practicals >> pens >> pencils >> k;

        int total_pens = lectures / pens;
        if(lectures % pens != 0) {
            total_pens++;
        }

        int total_pencils = practicals / pencils;
        if(practicals % pencils != 0) {
            total_pencils++;
        }

        if(total_pencils + total_pens <= k) {
            cout << total_pens << " " << total_pencils << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}