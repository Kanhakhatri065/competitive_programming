#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int,int>> v;

    int l, r;
    for(int i = 0;i < n;i++) {
        cin >> l >> r;
        v.push_back(make_pair(l, r));
    }

    int k;
    cin >> k;

    int count = 0;
    for(int i = 0;i < v.size();i++) {
        if(k >= v[i].first && k <= v[i].second) {
            count = i;
            break;
        }
    }

    count = n - count;
    cout << count << endl;
    return 0;
}