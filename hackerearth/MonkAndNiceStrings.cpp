#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    string names[size];
    for(int i = 0;i < size;i++) {
        cin >> names[i];
    }

    int count = 0;
    for(int i = 0;i < size;i++) {
        int count = 0;
        for(int j = 0;j < i;j++) {
            if(names[j] < names[i]) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}