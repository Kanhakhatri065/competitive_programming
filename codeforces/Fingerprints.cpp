#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int arr1[n];
    for(int i = 0;i < n;i++) {
        cin >> arr1[i];
    }

    int arr2[m];
    for(int i = 0;i < m;i++) {
        cin >> arr2[i];
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j <  m;j++) {
            if(arr1[i] == arr2[j]) {
                cout << arr2[j] << " ";
                break;
            }
        }
    }

    cout << endl;

    return 0;
}