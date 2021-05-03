#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& occ, string& s) {
    for(int i = 1;i <= int(s.size());i++) {
        cout << s.substr(0, i) << " occurs " << occ[i] << " times" << endl;
    }
}

vector<int> prefix_function(string& s) {
    vector<int> LPS(int(s.size()));

    LPS[0] = 0;

    for(int i = 1;i < int(s.size());i++) {
        int j = LPS[i - 1];

        while(j > 0 && s[i] != s[j]) {
            j = LPS[j - 1];
        }

        if(s[i] == s[j]) {
            LPS[i] = j + 1;
        } else {
            LPS[i] = 0;
        }
    }

    return LPS;
}

void count_occurence(string& s) {
    int n = int(s.size());

    vector<int> LPS = prefix_function(s);

    vector<int> occ(n + 1);

    for(int i = 0;i < n;i++) {
        occ[LPS[i]]++;
    }

    for(int i = n - 1;i > 0;i--) {
        occ[LPS[i - 1]] += occ[i];
    }

    for(int i = 0;i <= n;i++) {
        occ[i]++;
    }

    print(occ, s);
}

int main() {
    string s = "abacaba";

    count_occurence(s);

    return 0;
}
