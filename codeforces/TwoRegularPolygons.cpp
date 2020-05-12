#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int n, m;
    for(int i = 0;i < testcases;i++) {
        cin >> n >> m;
        if(n % m == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}