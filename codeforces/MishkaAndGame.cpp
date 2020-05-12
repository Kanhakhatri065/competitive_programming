#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int mishka = 0;
    int chris = 0;

    int a, b;
    while(size--) {
        cin >> a >> b;
        if(a > b) {
            mishka++;
        } else if(b > a) {
            chris++;
        }
    }

    if(mishka > chris) {
        cout << "Mishka" << endl;
    } else if(mishka < chris) {
        cout << "Chris" << endl;
    } else {
        cout << "Friendship is magic!^^" << endl;
    }

    return 0;
}