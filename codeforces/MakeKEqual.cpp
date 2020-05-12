#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int size, k;
    cin >> size >> k;

    long long int arr[size];
    for(long long int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);

    map<long long int, long long int> m;
    for(long long int i = 0;i < size;i++) {
        m[arr[i]]++;
    }

    long long int most_frequent;
    long long int how_much;
    map<long long int, long long int>::iterator it = m.begin();
    most_frequent = it->first;
    how_much = it->second;

    map<long long int, long long int>::reverse_iterator rev_it = m.rbegin();
    long long int largest_element = rev_it->first;
    long long int largest_element_frequency = rev_it->second;

    long long int count = 0;
    for(it = m.begin();it != m.end();++it) {
        if(it->second > how_much) {
            most_frequent = it->first;
            how_much = it->second;
        }
    }

    if(how_much < k) {

    }

    return 0;
}