#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    int arr[n];
    for(int i= 0;i < n;i++) {
        cin >> arr[i];
    }

    int last0, last1;
    for(int i= n - 1;i >= 0;i--) {
        if(arr[i] == 0) {
            last0 = i + 1;
            break;
        }
    }

    for(int i = n - 1;i >= 0;i--) {
        if(arr[i] == 1) {
            last1 = i + 1;
            break;
        }
    }

    cout << min(last0, last1) << endl;
    return 0;
}