#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    long long int left, right;
    long long int each;
    for(int i = 0;i < testcases;i++) {
        cin >> left >> right >> each;

        long long int min = (long long int) ceil((left / each) + 1) ;

        long long int max = (long long int) ceil(right / each);

        if(each > right || min > max) {
            cout << "-1 -1" << endl;
        } else {
            cout << min << " " << max << endl;
        }
    }

    return 0;
}