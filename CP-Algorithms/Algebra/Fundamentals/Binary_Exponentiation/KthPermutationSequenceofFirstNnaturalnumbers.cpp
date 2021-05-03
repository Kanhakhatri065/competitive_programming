#include <bits/stdc++.h>
using namespace std;

int findFirstNumIndex(int &k, int n) {
    if(n == 1) return 0;
    n--;

    int first_num_idx;
    int n_partial_fact = n;

    while(k >= n_partial_fact && n > 1) {
        n_partial_fact = n_partial_fact * (n - 1);
        n--;
    }

    first_num_idx = k / n_partial_fact;
    k = k % n_partial_fact;
    return first_num_idx;
}

vector<int> findKthPermutation(int n, int k) {
    vector<int> ans;
    set<int> s;

    for(int i = 1;i <= n;i++) s.insert(i);

    auto it = s.begin();
    k--;
    for(int i = 0;i < n;i++) {
        int idx = findFirstNumIndex(k, n - i);
        advance(it, idx);
        ans.push_back(*it);
        s.erase(it);
        it = s.begin();
    }

    return ans;
}

int main() {
    int n = 3;
    for(int i = 1;i <= 6;i++) {
        vector<int> res = findKthPermutation(n, i);
        for(int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
