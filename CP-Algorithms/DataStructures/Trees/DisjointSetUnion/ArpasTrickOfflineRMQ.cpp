#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];

void make_set(int v) {
    par[v] = v;
}

int find_set(int v) {
    if(v == par[v]) return v;
    return par[v] = find_set(par[v]);
}

struct Query {
    int L, R, idx;
};

vector<int> answer;
vector<vector<Query>> container;
// container[i] contains all the query with r == i
int n;
vector<int> a;
void solvequeries() {
stack<int> s;
for (int i = 0; i < n; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
        par[s.top()] = i;
        s.pop();
    }
    s.push(i);
    for (Query q : container[i]) {
        answer[q.idx] = a[find_set(q.L)];
    }
}
}

int main() {
    cout << "Size of the array :" << endl;
    cin >> n;
    a.resize(n);
    container.resize(n);
    cout << "Enter elements :" << endl;
    for(int &x : a) cin >> x;

    for(int i = 0;i < n;i++) make_set(i);

    cout << "Enter number of queries : " << endl;
    int q;cin >> q;
    answer.resize(q);
    for(int i = 0;i < q;i++) {
        int l, r;cin >> l >> r;
        container[r].push_back({l, r, i});
    }

    solvequeries();

    cout << "Answer of queries : " << endl;
    for(int i = 0;i < q;i++) cout << answer[i] << endl;

    return 0;
}
