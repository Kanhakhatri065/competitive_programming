#include <bits/stdc++.h>

using namespace std;

int count_unique_substrings(string const& s) {
    int n = int(s.size());

    const int P = 31;
    const int MOD = 1e9 + 9;

    vector<long long> p_pow(n);
    p_pow[0] = 1;

    for(int i = 1;i < n;i++) {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
    }

    vector<long long> h(n + 1, 0);
    for(int i = 0;i < n;i++) {
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    int cnt = 0;
    for(int l = 1;l <= n;l++) {
        set<long long> hs;

        for(int i = 0;i <= n - l;i++) {
            long long cur_h = (h[i + l] + MOD - h[i]) % MOD;
            cur_h = (cur_h * p_pow[n - i - 1]) % MOD;
            hs.insert(cur_h);
        }

        cnt += int(hs.size());
    }

    return cnt;
}

int main() {
    string s = "abacddgwetiba";
    cout << "Unique substring of string " << s << " is : " << count_unique_substrings(s) << endl;

    return 0;
}
