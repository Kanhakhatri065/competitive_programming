#include <iostream>

using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    long long int first = (s * v1) + (2 * t1);
    long long int second = (s * v2) + (2 * t2);

    if(first < second) {
        cout << "First" << endl;
    } else if(first > second) {
        cout << "Second" << endl;
    } else {
        cout << "Friendship" << endl;
    }

    return 0;
}