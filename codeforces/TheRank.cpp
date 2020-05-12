#include <bits/stdc++.h>

using namespace std;

struct Scores {
    int id;
    int sum;
};

bool cmp(const Scores &s1, const Scores &s2) {
    if(s1.sum != s2.sum) {
        return s1.sum > s2.sum;
    }
    return s1.id < s2.id;
}

int main() {
    int n;
    cin >> n;

    int a, b, c, d;
    int sum;
    Scores v[n];
    for(int i = 0;i < n;i++) {
        Scores s;
        s.id = i + 1;
        cin >> a >> b >> c >> d;
        sum = a + b + c + d;
        s.sum = sum;
        v[i] = s;
    }

    sort(v, v + n,  cmp);
    for(int i = 0;i < n;i++) {
        if(v[i].id == 1) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}