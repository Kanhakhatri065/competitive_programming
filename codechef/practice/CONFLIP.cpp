#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int g;
    while(testcases--) {
        cin >> g;

        int i, q;
        long long int n;
        while(g--) {
            cin >> i >> n >> q;
            
            long long int count = 0;
            if(n % 2 == 0) {
                count = n / 2;
            } else {
                if(i != q) {
                    count = (n / 2) + 1;
                } else {
                    count = n / 2;
                }
            }

            cout << count << endl;
        }
    }
    return 0;
}