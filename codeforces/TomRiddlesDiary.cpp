#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> m;
    string str;
    for(int i = 0;i < n;i++) {
        cin >> str;
        if(m.find(str) != m.end()) {
            cout << "YES" << endl;
            m[str]++;
        } else {
            cout << "NO" << endl;
            m[str]++;
        }
    }
    return 0;
}