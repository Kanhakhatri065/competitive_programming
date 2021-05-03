#include <bits/stdc++.h>
using namespace std;

string min_cyclic_string(string s) {
    s += s;
    int n = int(s.size());
    int i = 0, ans = 0;
    while(i < n / 2) {
        ans = i;
        int j = i + 1, k = i;
        while(j < n && s[k] <= s[j]) {
            if(s[k] < s[j]) {
                k = i;
            } else {
                k++;
            }
            j++;
        }

        while(i <= k) { 
            i += (j - k);
        }
    }

    return s.substr(ans, n / 2);
}

int main() {
    string s;
    cin >> s;

    cout << " Smallest cyclic shift string of " << s << " is : ";
    cout << min_cyclic_string(s) << endl;

    return 0;
}
