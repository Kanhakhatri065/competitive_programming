#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    vector<int> recieved;
    for(int i = 0;i < size;i++) {
        for(int j = 0;j < size;j++) {
            if(i + 1 == arr[j]) {
                recieved.push_back(j + 1);
            }
        }
    }

    for(int i = 0;i < recieved.size();i++) {
        cout << recieved[i] << " ";
    }
    cout << endl;
    return 0;
}