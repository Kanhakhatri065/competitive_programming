#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    map<int,int> m;
    int temp;
    for(int i = 0;i < size;i++) {
        cin >> temp;
        m[temp]++;
    }

    map<int,int>::iterator it;
    it = m.begin();
    int frequency = it->second;
    for(it = m.begin();it != m.end();++it) {
        if(it->second > frequency) {
            frequency = it->second;
        }
    }

    cout << frequency << endl;
    
    return 0;
}