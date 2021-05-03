#include <bits/stdc++.h>
using namespace std;
#define pf(x) cout << (x) << endl

bool next_balanced_sequence(string &s) {
    int n = int(s.size());
    int depth = 0;
    for(int i = n - 1;i >= 0;i--) {
        if(s[i] == '(') {
            depth--;
        } else {
            depth++;
        }

        if(s[i] == '(' && depth > 0) {
            depth--;
            int open = (n - i - 1 - depth) / 2;
            int close = n - i - 1 - open;
            string nex = s.substr(0, i) + ')' + string(open, '(') + string(close, ')');
            s.swap(nex);
            return true;
        }
    }

    return false;
}

int main() {
    string s;
    cin >> s;
    
    pf("Input string " + s);
    bool flag = next_balanced_sequence(s);
    if(flag) {
        cout << "Lexographically next string : ";
        pf(s);
    } else {
        pf("Lexographically next sequence not found");
    }
}
