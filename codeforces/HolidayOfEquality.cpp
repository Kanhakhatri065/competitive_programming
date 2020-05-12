#include <iostream>
#include <algorithm>
typedef long long int ll;

using namespace std;

int main() {
    int size;
    cin >> size;

    ll arr[size];
    for(int i = 0;i < size;i++) {
        cin >> arr[i];
    }

    sort(arr, arr + size);
    
    long long int count = 0;
    for(int i = 0;i < size;i++) {
        count += (arr[size - 1] - arr[i]);
    }

    cout << count << endl;
    
    return 0;
}