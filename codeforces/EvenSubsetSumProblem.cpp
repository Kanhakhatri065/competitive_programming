#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int n;
    while(testcases--) {
        cin >> n;

        int arr[n];
        for(int i = 0;i < n;i++) {
            cin >> arr[i];
        }

        if(n == 1) {
            if(arr[0] % 2 != 0) {
                cout << "-1" << endl;
            } else {
                cout << "1" << endl;
                cout << "1" << endl;
            }
        } else {
            int pos = 0;
            for(int i = 0;i < n;i++) {
                if(arr[i] % 2 == 0) {
                    pos = i + 1;
                    break;
                }
            }

            if(pos != 0) {
                cout << "1" << endl;
                cout << pos << endl;
            } else {
                vector<int> store;
                int sum = 0;
                for(int i = 0;i < n;i++) {
                    sum += arr[i];
                    store.push_back(i + 1);
                    if(sum % 2 == 0) {
                        break;
                    }
                }

                cout << store.size() << endl;
                for(int i= 0;i < store.size();i++) {
                    cout << store[i] << " ";
                }
                cout << endl;
            }

        }
    }
    return 0;
}