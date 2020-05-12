#include <iostream>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int n, x, a, b;
    while(testcases--) {
        cin >> n >> x >> a >> b;
        int first;
        int second;

        if(a > b) {
            second = a;
            first = b;
        } else {
            first = a;
            second = b;
        }

        while(x != 0) {
            if(second < n && x > 0) {
                second++;
                x--;
            }

            if(first > 1 && x > 0) {
                first--;
                x--;
            }

            if(first == 1 && second == n) {
                break;
            }
        }

        cout << (second - first) << endl;
    }
    return 0;
}