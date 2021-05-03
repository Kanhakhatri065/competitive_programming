#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = int(s.length());
    vector<int> pi(n);

    for(int i = 0;i < n;i++) {
        for(int k = 0;k <= i;k++) {
            if(s.substr(0, k) == s.substr(i - k + 1, k)) {
                pi[i] = k;
            }
        }
    }

    return pi;
}

int main() {
    string s = "abcabcd";

    vector<int> pi = prefix_function(s);

    cout << "For string " << s << " prefix values are : ";
    for(int x : pi) cout << x << ' ';
    cout << endl;

    return 0;
}
