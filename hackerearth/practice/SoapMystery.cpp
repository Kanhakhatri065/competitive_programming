#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<long long int> arr;
    long long int temp;
    for(int i = 0;i < size;i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int queries;
    cin >> queries;

    long long int amount;
    for(int i = 0;i < queries;i++) {
        cin >> amount;

        int count = lower_bound(arr.begin(), arr.end(), amount) - arr.begin();
        
        cout << count << endl;
    }
    return 0;
}