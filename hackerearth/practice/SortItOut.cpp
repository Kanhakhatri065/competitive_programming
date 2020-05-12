#include <bits/stdc++.h>

using namespace std;


int main() {
    long long size;
    cin >> size;

    vector<pair<long long, long>> vec;
    long long  count = 0;
    long long temp;
    for(long long i = 0;i < size;i++) {
        cin >> temp;
        vec.push_back(pair<long long, long long>(temp, count));
        count++;
    }

    sort(vec.begin(), vec.end(), [](const pair<long long, long long> &l, const pair<long long, long long> &r) {
        if(l.second != r.second) {
            l.second < r.second;
        }
        return l.first < r.first;
    });

    for(auto const &pair: vec) {
        cout << pair.second << " ";
    }

    return 0;
}