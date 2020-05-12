#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    int count = 0;
    if(x % 4 == 0) {
        count++;
        cout << count << " A" << endl;
    } else if(x % 4 == 1) {
        cout << count << " A" << endl;
    } else if(x % 4 == 2) {
        count++;
        cout << count << " B" << endl;
    } else if(x % 4 == 3) {
        count += 2;
        cout << count << " A" << endl;
    }
    return 0;
}