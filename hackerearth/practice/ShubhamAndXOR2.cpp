#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    long long size;
    cin >> size;

    long long arr[size];
    for(long long i = 0;i < size;i++) {
        cin >> arr[i];
    }

    unordered_map<long long, long long> mp;
    for(long long i = 0;i < size;i++) {
        mp[arr[i]]++;
    }

    long long int answer = 0;
    for(auto it = mp.begin(); it != mp.end();it++) {
        answer += (it->second) * (it->second -1);
    }

    cout << (answer / 2) << endl;

    return 0;
}