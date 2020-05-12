#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr[m] = {0};
    int l, r;
    while(n--) {
        cin >> l >> r;
        for(int i = l - 1;i < r;i++) {
            arr[i] = -1;
        }
    }

    vector<int> store;
    for(int i = 0;i < m;i++) {
        if(arr[i] != -1) {
            store.push_back(i + 1);
        }
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