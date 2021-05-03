#include <bits/stdc++.h>

using namespace std;

void getZarr(string str, int Z[]);

void search(string text, string pattern) {
    string concat = pattern + '$' + text;
    int l = int(concat.size());

    int Z[l];
    getZarr(concat, Z);

    for(int i = 0;i < l;i++) {
        if(Z[i] == int(pattern.length())) {
            cout << "Pattern found at : ";
            cout << (i - int(pattern.length()) - 1) << endl;
        }
    }
}

void getZarr(string s, int Z[]) {
    int n = int(s.length());
    int L, R, k;

    L = R = 0;
    for(int i = 1;i < n;i++) {
        if(i > R) {
            L = R = i;
            while(R < n && s[R - L] == s[R]) {
                R++;
            }

            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if(Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while(R < n && s[R - L] == s[R]) R++;
                Z[i] = R - L;
                R--;
            }

        }
    }
}

int main() {
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    search(text, pattern);
    return 0;
}
