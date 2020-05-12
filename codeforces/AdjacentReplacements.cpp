#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<long long int> v(size, 0);
    for(int i = 0;i <size;i++) {
        cin >> v[i];
        if(v[i] % 2 == 0) {
            v[i]--;
        }
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}