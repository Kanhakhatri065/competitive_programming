#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int larger, smaller;
    if(a >= b) {
        larger = a;
        smaller = b;
    } else {
        larger = b;
        smaller = a;
    }

    int differentsocks = 0;
    int samesocks = 0;

    while(larger != 0) {
        if(smaller > 0) {
            differentsocks++;
            smaller--;
            larger--;
        } 

        if(smaller == 0 && larger > 1) {
            samesocks++;
            larger -= 2;
        }

        if(smaller == 0 && larger == 1) {
            break;
        }
    }

    cout << differentsocks << " " << samesocks << endl;

    return 0;
}