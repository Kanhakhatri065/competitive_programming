#include <bits/stdc++.h>

using namespace std;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    for(int i = 0;i < testcases;i++) {
        cin >> size;

        pair<long long int, long long int> happy[size], sad[size], indexwise[size];
        long long int favour, anger;
        long long int netsad = 0;
        for(int j = 0;j < size;j++) {
            cin >> favour >> anger;
            happy[j] = make_pair(favour + anger, j);
            indexwise[j] = make_pair(favour, anger);
            netsad += anger;
        }

        sort(happy, happy + size);
        cout << (happy[size - 1].first + happy[size - 2].first - netsad) << endl;
    }
    return 0;
}