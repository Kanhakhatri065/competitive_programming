#include <iostream>

using namespace std;

typedef long long int ll;

int main() {
    int testcases;
    cin >> testcases;

    int size;
    while(testcases--) {
        cin >> size;
        int arr[size];

        ll count = 0;
        ll sum = 0;
        for(int i = 0;i < size;i++) {
            cin >> arr[i];
            if(arr[i] == 0) {
                count++;
                arr[i]++;
            }

            sum += arr[i];
        }

        if(sum == 0) {
            count++;
        }

        cout << count << endl;
    }
    return 0;
}