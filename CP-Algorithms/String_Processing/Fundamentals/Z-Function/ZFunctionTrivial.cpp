#include <bits/stdc++.h>

using namespace std;

vector<int> z_function_trivial(string s) {
    int n = int(s.size());

    vector<int> z(n);

    for(int i = 1;i < n;i++) {
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }

    return z;
}

int main() {
    string s = "abacaba";
    vector<int> v = z_function_trivial(s);

    cout << "Z-array of " << s << " is : ";
    for(int x : v) cout << x << " ";
    cout << endl;

    return 0;
}
