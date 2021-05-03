#include <bits/stdc++.h>
using namespace std;

vector<string> duval(string const& s) {
    int n = int(s.size());
    int i = 0;
    vector<string> factorization;
    while(i < n) {
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
            factorization.push_back(s.substr(i, j - k));
            i += (j - k);
        }
    }

    return factorization;
}

int main() {
    string s;
    cin >> s;

    vector<string> store = duval(s);

    cout << "Lyndon Factorization of " << s << " is : " << endl;
    for(string str : store) cout << str << " ";
    cout << endl;

    return 0;
}
