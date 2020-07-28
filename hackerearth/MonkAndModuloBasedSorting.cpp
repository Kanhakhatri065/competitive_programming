#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    long long int number;
    cin >> number;

    long long int arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    multimap<int, long long int> table;
    for(int i = 0;i < size;i++) {
        int modulo = arr[i] % number;

        table.insert(make_pair(modulo, arr[i]));
    }

    multimap<int, long long int>::iterator itr;
    for(itr = table.begin(); itr != table.end();++itr) {
        cout << itr->second << " ";
    }

    cout << endl;

    return 0;
}