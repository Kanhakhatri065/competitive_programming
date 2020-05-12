#include <iostream>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    int sf = 0;
    int fs = 0;

    for(int i = 1;i < str.size();i++) {
        if(str[i - 1] == 'S' && str[i] == 'F') {
            sf++;
        }

        if(str[i - 1] == 'F' && str[i] == 'S') {
            fs++;
        }
    }

    if(sf > fs) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}