#include <bits/stdc++.h>

using namespace std;

vector<int> rabin_karp(string const& s, string const& t) {
    const int P = 31;
    const int MOD = 1e9 + 9;

    int S = int(s.size()), T = int(t.size());

    vector<long long> p_pow(max(S, T));

    p_pow[0] = 1;
    for(int i = 1;i < int(p_pow.size());i++) {
        p_pow[i] = (p_pow[i - 1] * P) % MOD;
    }

    vector<long long> h(T + 1, 0);
    for(int i = 0;i < T;i++) {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    long long h_s = 0;
    for(int i = 0;i < S;i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % MOD;
    }

    vector<int> occurences;
    for(int i = 0;i + S - 1 < T;i++) {
        long long cur_h = (h[i + S] + MOD - h[i]) % MOD;
        if(cur_h == h_s * p_pow[i] % MOD) {
            occurences.push_back(i);
        }
    }

    return occurences;
}

int main() {
    string s = "ab", t = "abbbabbbabbbdcab";
    vector<int> occurences = rabin_karp(s, t);

    for(int x : occurences) cout << x << " ";
    cout << endl;

    return 0;
}
