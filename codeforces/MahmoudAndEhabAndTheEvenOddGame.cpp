#include <iostream>

typedef long long int ll;

using namespace std;

int main() {
    ll n;
    cin >> n;

    ll turn = 0;
    int flag = 0;
    while(flag == 0) {
        if(turn % 2 == 0 && n > 1) {
            if(n % 2 == 0) {
                n = 0;
            } else {
                n = 1;
            }
        }

        if(turn % 2 == 1 && n > 1) {
            if(n % 2 == 0) {
                n = 1;
            } else {
                n = 0;
            }
        }

        turn++;

        if(turn % 2 == 0 && n <= 1) {
            cout << "Ehab" << endl;
            flag = 1;
            break;
        }

        if(turn % 2 != 0 && n == 0) {
            cout << "Mahmoud" << endl;
            flag = 1;
            break;
        }

        
    }
    return 0;
}