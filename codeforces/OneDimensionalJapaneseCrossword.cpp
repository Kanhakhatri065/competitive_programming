#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    string str;
    cin >> str;

    int blacks = 0;
    vector<int> store;
    for(int i = 0;i < size;i++) {
        if(str[i] == 'B') {
            blacks++;
        } else {
            if(blacks != 0) {
                store.push_back(blacks);
                blacks = 0;
            }
        }
    }

    if(blacks != 0) {
        store.push_back(blacks);
    }

    if(store.empty()) {
        cout << "0" << endl;
    } else {
        cout << store.size() << endl;
        for(int i = 0;i < store.size();i++) {
            cout << store[i] << " ";
        }
        cout << endl;
    }
    return 0;
}