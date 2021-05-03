#include <bits/stdc++.h>

using namespace std;

using ll = long long;

long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << "Hash of string " << s << " : " << compute_hash(s) << endl;
    cout << "Hash of string " << t << " : " << compute_hash(t) << endl;

    return 0;
}
