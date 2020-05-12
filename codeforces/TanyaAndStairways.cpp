#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    vector<int> store;

    int count = 1;
    for(int i = 1;i < n;i++) {
        if(arr[i] == 1) {
            store.push_back(count);
            count = 1;  
        } else {
            count++;
        }
    }

    if(count > 0) {
        store.push_back(count);
    }

    cout << store.size() << endl;
    for(int i = 0;i < store.size();i++) {
        cout << store[i] << " ";
    }
    cout << endl;

    return 0;
}